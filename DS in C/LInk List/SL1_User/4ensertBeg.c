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
    int count = 0;
    printf("Display data: ");
    while (temp != NULL)
    {
        count++;
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("(Total node %d)\n", count);
}
void insertBeg()
{
    block *newNode, *temp=head;
    newNode=malloc(sizeof(block));
    printf("Enter data for newNode(insertBeg):");
    scanf("%d", &newNode->data);
    newNode->link=NULL;
    head=newNode;
    newNode->link=temp;
}
int main()
{
    create();
    display();

    insertBeg();
    display();
    return 0;
}