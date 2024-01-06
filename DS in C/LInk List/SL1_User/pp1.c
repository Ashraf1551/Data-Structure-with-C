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
    printf("Enter node no: ");
    scanf("%d", &n);
    block *temp, *tail;
    printf("Enter data for node: ");
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

    if (head == NULL)
        printf("Empty!!");
    printf("Display data: ");
    while (temp != NULL)
    {
        printf("%d-->", temp->data);
        temp = temp->link;
    }
    printf("data\n\n");
}
void insertBeg()
{
    block *temp = head, *newNode;
    printf("Enter data for newNode(insertBeg): ");
    newNode = malloc(sizeof(block));
    scanf("%d", &newNode->data);
    newNode->link = NULL;
    newNode->link = temp;
    head = newNode;
}
void insertEnd()
{
    block *temp = head, *newNode;
    newNode = malloc(sizeof(block));
    printf("Enter data for newNode(insertEnd): ");
    scanf("%d", &newNode->data);
    newNode->link = NULL;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = newNode;
}
void mb_i()
{
    int i, pos;
    printf("Enter position you want to insert(mb_i): ");
    scanf("%d", &pos);
    block *temp = head, *newNode;
    newNode = malloc(sizeof(block));
    printf("Enter data for newNode: ");
    scanf("%d", &newNode->data);
    newNode->link = NULL;
    pos--;
    while (pos != 1)
    {
        temp = temp->link;
        pos--;
    }
    newNode->link = temp->link; //! forgot the condtion
    temp->link = newNode;
}
void ma_i()
{
    int i, pos;
    printf("Enter position you want to insert(ma_i): ");
    scanf("%d", &pos);
    block *temp = head, *newNode;
    newNode = malloc(sizeof(block));
    printf("Enter data for newNode: ");
    scanf("%d", &newNode->data);
    newNode->link = NULL;
    pos--;
    while (pos != 0)
    {
        temp = temp->link;
        pos--;
    }
    newNode->link = temp->link;
    temp->link = newNode;
}
void delNode()
{
    block *current = head, *prev = head;
    int pos;
    printf("Enter the node_num you want to delete: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        head = current->link;
        free(current);
        current = NULL;
    }
    else
    {
        while (pos != 1)
        {
            prev = current;
            current = current->link;
            pos--;
        }
        prev->link = current->link;
        free(current);
        current = NULL;
    }
}
int search(int s_key)
{
    int pos = 0;
    block *temp = head;
    while (temp != NULL)
    {
        pos++;
        if (temp->data == s_key)
            return pos;

        temp = temp->link;
    }
    return -1;
}

int main()
{
    create();
    display();

    insertBeg();
    display();

    insertEnd();
    display();

    mb_i();
    display();

    ma_i();
    display();

    delNode();
    display();

    int s_key, pos;
    printf("Enter the search key value: ");
    scanf("%d", &s_key);
    pos=search(s_key);
    if (pos == -1)
        printf("Not Found!");

    else
        printf("Found at: %d position.", pos);
    return 0;
}
