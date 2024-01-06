#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} block;
block *head = NULL;

void create()
{
    int i, n;
    printf("Enter node number: ");
    scanf("%d", &n);
    block *temp, *tail;
    printf("Enter data: ");
    for (i = 0; i < n; i++)
    {
        temp = malloc(sizeof(block));
        scanf("%d", temp->data);

        if (head == NULL)
        {
            temp = head;
            tail = head;
        }
        else
        {
            tail->link = temp;
            tail = temp;
        }
    }
    tail->link = NULL;
}