#include <stdio.h>
#include <stdlib.h>


struct block
{
    int block_no;
    struct block *next;
};

struct file
{
    int start_block;
    int length;
    struct block *list;
};

int main(void)
{
    int n, blocks[100], flag = 0, count, i;
    char c = 'y';
    printf("Enter the number of free blocks: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        blocks[i] = 0;

    while (c == 'y' || c == 'Y')
    {
        struct file *ptr = (struct file *)malloc(sizeof(struct file));
        printf("Enter file starting block: ");
        scanf("%d", &(ptr->start_block));
        printf("Enter file length: ");
        scanf("%d", &(ptr->length));
        if (blocks[ptr->start_block] == 1)
        {
            printf("Starting block already allocated! Allocation not possible.\n");
        }
        else
        {
            struct block *b = (struct block *)malloc(sizeof(struct block));
            b->block_no = ptr->start_block;
            b->next = NULL;
            ptr->list = b;
            blocks[ptr->start_block] = 1;
            count = 1;
            i = ptr->start_block + 1;
            while (count < ptr->length)
            {
                if (i >= n)
                i = 0;
                if (blocks[i] == 0)
                {
                struct block *new_block = (struct block *)malloc(sizeof(struct block));
                new_block->block_no = i;
                new_block->next = NULL;
                struct block *p = ptr->list;
                while (p != NULL && p->next != NULL)
                p = p->next;
                p->next = new_block;
                count++;
                blocks[i] = 1;
                }
                i++;
            }
            if (count < ptr->length)
            {
                printf("Allocation not possible due to insufficient storage!\n");
            }
            else
            {
                printf("File allocated to disk.\n");
                printf("Linked list of blocks allocated to this file: ");
                struct block *p = ptr->list;
                while (p->next != NULL)
                {
                    printf("%d->", p->block_no);
                    p = p->next;
                }
                printf("%d", p->block_no);
            }
        }
        printf("\nAre there more files? (y/n): ");
        scanf(" %c", &c);
    }
}