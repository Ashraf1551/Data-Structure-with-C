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
        scanf("%d", &temp->data);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->link = temp;
            tail = temp;
        }
        tail->link = NULL;
    }
}
void display()
{
    block *temp = head;
    printf("Display data: ");
    while (temp != NULL)
    {
        printf("%d-->", temp->data);
        temp = temp->link;
    }
    printf("data\n");
}
void count()
{
    block *temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->link;
    }
    printf("Total node: %d\n", count);
}
int main()
{
    create();
    display();
    count();

    return 0;
}