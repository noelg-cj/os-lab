#include <stdio.h>
#include <stdlib.h>

int find_index(int* arr, int key, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

int pageFaults_fifo(int pages[], int n, int capacity) {
    int *indexes = (int*)malloc(sizeof(int) * n);
    int front = 0;
    int rear = 0;
    int *s = (int*)malloc(sizeof(int) * capacity);
    int a = 0;

    int page_faults = 0;
    for (int i = 0; i < n; i++) {
        if (a < capacity) {
            int flag = find_index(s, pages[i], a);

            if (flag == -1) {
                s[a++] = pages[i];
                page_faults++;
                indexes[front++] = pages[i];
            }
        }

        else {
            int flag = find_index(s, pages[i], a);

            if (flag == -1) {
                int first = indexes[rear++];

                int idx = find_index(s, first, capacity);
                s[idx] = pages[i];

                page_faults++;
            }
        }

        printf("%d\t\t", pages[i]);
        for (int j = 0; j < a; j++) {
            printf("%d\t\t", s[j]);
        }
        printf("\n");
    }

    return page_faults;
}

int pageFaults_lru(int pages[], int n, int capacity) {
    int *indexes = (int*)malloc(sizeof(int) * n);
    int front = 0;
    int rear = 0;
    int *s = (int*)malloc(sizeof(int) * capacity);
    int a = 0;

    int page_faults = 0;
    for (int i = 0; i < n; i++) {
        if (a < capacity) {
            int flag = find_index(s, pages[i], a);

            if (flag == -1) {
                s[a++] = pages[i];
                page_faults++;
                indexes[front++] = pages[i];
            }
        }

        else {
            int flag = find_index(s, pages[i], a);

            if (flag == -1) {
                int first = indexes[rear++];

                int idx = find_index(s, first, capacity);
                s[idx] = pages[i];

                page_faults++;
                indexes[front++] = pages[i];
            }

            else {
                int idx = find_index(indexes, pages[i], n);
                int value = pages[i];

                for (int j = idx; j < front; j++) {
                    indexes[j] = indexes[j+1];
                }

                indexes[front-1] = value;
            }
        }

        printf("%d\t\t", pages[i]);
        for (int j = 0; j < a; j++) {
            printf("%d\t\t", s[j]);
        }
        printf("\n");
    }

    return page_faults;
}

int main(void) {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(int);
    int capacity = 3;

    int fifo_pf = pageFaults_fifo(pages, n, capacity);
    printf("Page faults: %d\n", fifo_pf);

    int lru_pf = pageFaults_lru(pages, n, capacity);
    printf("Page faults: %d\n", lru_pf);
}