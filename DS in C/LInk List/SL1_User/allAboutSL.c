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
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}
void insertEnd()
{
    block *temp = head, *newNode;
    printf("Enter data for newNode(insertEnd): ");
    newNode = malloc(sizeof(block));
    scanf("%d", &newNode->data);
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = newNode;
    newNode->link = NULL;
}
void insertBeg()
{
    block *temp=head, *newNode;
    printf("Enter data for newNode(insertBeg): ");
    newNode=malloc(sizeof(block));
    scanf("%d", &newNode->data);
    newNode->link=NULL;
    newNode->link=temp;
    head=newNode;
}
void mb_i()
{
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);
    block *temp=head, *newNode;
    newNode=malloc(sizeof(block));
    printf("Enter data for newNode(mb_i): ");
    scanf("%d", &newNode->data);
    newNode->link=NULL;
    pos--;
    while(pos!=1)
    {
        temp=temp->link;
        pos--;
    }
    newNode->link=temp->link;
    temp->link=newNode;
}
void ma_i()
{
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);
    block *temp=head, *newNode;
    newNode=malloc(sizeof(block));
    printf("Enter data for newNode(ma_i): ");
    scanf("%d", &newNode->data);
    newNode->link=NULL;

    pos--;
    while(pos!=0)
    {
        temp=temp->link;
        pos--;
    }
    newNode->link=temp->link;
    temp->link=newNode;
}
void delNode()
{
    int pos;
    printf("Enter node you want to delete: ");
    scanf("%d", &pos);

    block *current=head, *previous=head;
    //current--to delete the node, previous--before node to delete
    if(pos==1)
    {
        head=current->link;
        free(current);
        current=NULL;
    }
    else
    {
        while(pos!=1)
        {
            previous=current;
            current=current->link;
            pos--;
        }
        previous->link=current->link;
        free(current);
        current=NULL;
    }
}
int main()
{
    create();
    display();

    insertEnd();
    display();

    insertBeg();
    display();

    mb_i();
    display();

    ma_i();
    display();

    delNode();
    display();
}