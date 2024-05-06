#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, blocks[100], flag = 0, index, length, count = 0, index_block[100];
    char c = 'y';
    printf("Enter the number of blocks: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        blocks[i] = 0;
    while (c == 'y' || c == 'Y')
    {
        count = 0;
        printf("Enter file index block number: ");
        scanf("%d", &index);
        if (index >= n || index < 0)
        {
            printf("Invalid index block number! Please enter a valid index.\n");
            continue;
        }
        if (blocks[index] == 1)
        {
            printf("Index block already allocated! No allocation possible.\n");
        }
        else
        {
            printf("Enter file length: ");
            scanf("%d", &length);
            blocks[index] = 1;
            int start = 0;
            for (int i = start; i < n && count < length; i++)
            {
                if (blocks[i] == 0)
                {
                blocks[i] = 1;
                index_block[count] = i;
                count++;
                }
            }
            if (count < length)
            {
                printf("Insufficient storage! No allocation.\n");
                blocks[index] = 0;
                for (int i = start; i < n && i < start + count; i++)
                blocks[i] = 0;
            }
            else
            {
                printf("File allocated to disk with index block %d\n", index);
                for (int i = 0; i < count; i++)
                printf("%d->%d\n", index, index_block[i]);
            }
        }
        printf("\nAre there more files? (y/n): ");
        scanf(" %c", &c);
    }
}