#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} block;
block *head = NULL;
int node = 0;
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
            node++;
        }
        else
        {
            tail->link = temp;
            tail = temp;
            node++;
        }
        tail->link = NULL;
    }
    tail->link = head;
}

void display()
{
    block *temp = head;
    printf("Display data: ");

    for (int i = 0; i < ((2 * node)); i++)
    {
        printf("%d-->", temp->data);
        temp = temp->link;
    }
    printf("head\n");
}
void insertBeg()
{
    block *newNode, *temp = head;
    newNode = malloc(sizeof(block));
    printf("Enter data for newNode(insertBeg):");
    scanf("%d", &newNode->data);
    newNode->link = NULL;
    head = newNode;
    newNode->link = temp;
    node++;
    temp=head;
    for(int i=1; i<node; i++)
    {
        temp=temp->link;
    }
    temp->link=head;
}

int main()
{
    create();
    display();

    insertBeg();
    display();
    return 0;
}