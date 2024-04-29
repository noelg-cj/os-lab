#include <stdio.h>


void firstFit(int *arr, int *alloc, int n) {
	int mem[5] = { 0, 0, 0, 0, 0 };
	for (int i = 0; i < n; i++) {
		int flag = 0;
		for (int j = 0; j < n; j++) {
			if (arr[i] <= alloc[j] && mem[j] == 0) {
				mem[j] = 1;
				flag = 1;
				printf("%d ---> %d\n", arr[i], alloc[j]);
				break;
			}
		}

		if (!flag) {
			printf("%d ---> Not allocated\n", arr[i]);
		}
	}
}

void worstFit(int *arr, int *alloc, int n) {
	int mem[5] = { 0, 0, 0, 0, 0 };
	for (int i = 0; i < n; i++) {
		int flag = 0;
		int max = alloc[0];
		int idx = 0;
		for (int j = 0; j < n; j++) {
			if (alloc[j] > max && mem[j] == 0) {
				max = alloc[j];
				idx = j;
			}
		}

		if (arr[i] <= max) {
			mem[idx] = 1;
			flag = 1;
			printf("%d ---> %d\n", arr[i], alloc[idx]);
		}

		if (!flag) {
			printf("%d ---> Not allocated\n", arr[i]);
		}
	}
}

void bestFit(int *arr, int *alloc, int n) {
	int mem[5] = { 0, 0, 0, 0, 0 };
	for (int i = 0; i < n; i++) {
		int flag = 0;
		int best = alloc[0];
		int idx = 0;
		for (int j = 0; j < n; j++) {

			if (alloc[j] >= arr[i]) {
				if (mem[j] == 0) {
					flag = 1;
					best = alloc[j];
					idx = j;
				}
			}
		}

		for (int j = 0; j < n; j++) {
			if (alloc[j] <= best && alloc[j] >= arr[i] && mem[j] == 0) {
				best = alloc[j];
				idx = j;
			}
		}

		if (flag == 1) {
			mem[idx] = 1;
			printf("%d ---> %d\n", arr[i], alloc[idx]);
		}

		else {
			printf("%d ---> Not allocated\n", arr[i]);
		}
	}
}

int main(void) {
	int alloc[5] = { 100, 200, 300, 400, 500 };
	int arr[5] = { 50, 350, 850, 200, 250 };
	firstFit(arr, alloc, 5);
	printf("\nWorst Fit:\n");
	worstFit(arr, alloc, 5);
	printf("\nBest Fit:\n");
	bestFit(arr, alloc, 5);
}
