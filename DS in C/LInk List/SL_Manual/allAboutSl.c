#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};

void creatingNodes(struct node *head)
{
    head->data = 65;
    head->link = NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data = 77;
    current->link = NULL;
    head->link = current;

    current = malloc(sizeof(struct node));
    current->data = 89;
    current->link = NULL;

    head->link->link = current;
}

void countingNodes(struct node *head)
{
    int count = 0;
    if (head == NULL)
        printf("Linked List is Empty!!");
    struct node *p = NULL;
    p = head;
    while (p != NULL)
    {
        count++;
        p = p->link;
    }
    printf("%d\n", count);
}

void printNodes(struct node *head)
{
    if (head == NULL)
        printf("Linked List Empty!!");

    struct node *p = NULL;
    p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("\n");
}

void insertEnd(struct node *head)
{
    if (head == NULL)
        printf("Liked List is Empty!!");

    struct node *p, *temp;

    temp = malloc(sizeof(struct node));
    temp->data = 45;
    temp->link = NULL;

    p = head;
    while (p->link != NULL)
    {
        p = p->link;
    }
    p->link = temp;
}

struct node *insertBeg(struct node *head)
{
    struct node *p = malloc(sizeof(struct node));
    p->data = 10;
    p->link = NULL;

    p->link = head;

    head = p;
    return head;
}

void insertCertainPosition(struct node *head)
{
    int pos = 5;
    struct node *p = head;
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = 70;
    newNode->link = NULL;

    pos--;
    while (pos != 1)
    {
        p = p->link;
        pos--;
    }
    newNode->link = p->link;
    p->link = newNode;
}

struct node *delLastNode(struct node *head)
{
    if (head == NULL)
        printf("Linked List is empty");

    else if (head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *temp = head;
        struct node *temp2 = head;
        while (temp->link != NULL)
        {
            temp2 = temp;
            temp = temp->link;
        }
        temp2->link = NULL;
        free(temp);
        temp = NULL;
    }
    return head;
}

struct node *delFirstNode(struct node *head)
{
    if (head == NULL)
        printf("Linked List is empty!!");

    struct node *temp = head;
    head = head->link;
    free(temp);
    temp = NULL;

    return head;
}

struct node *delCertainNode(struct node *head)
{
    int pos = 2;

    /*
    hl Noted that:
    ! current pointer will point to the node, we want to delete.
    ! previous pointer will point to the node, just before the node we want to delete.
    */
    struct node *current = head;
    struct node *previous = head;
    if (head == NULL)
        printf("Linked List is empty!!");

    else if (pos == 1)
    {
        head = current->link;
        free(current);
        current = NULL;
    }
    else
    {
        while(pos !=1)
        {
            previous = current;
            current=current->link;
            pos--;
        }
        previous->link=current->link;
        free(current);
        current=NULL;
    }
    return head;
}

struct node *delEntileSl(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        temp = temp->link;
        free(head);
        head = temp;
    }
    if (head == NULL)
        printf("Empty\n");

    return head;
}
struct node *reverseSL(struct node *head)
{
    struct node *prev = NULL;
    struct node *next = NULL;
    while (head!=NULL)
    {
        next=head->link;
        head->link=prev;
        prev=head;
        head=next;
    }
    head = prev;
    return head;
}
int main()
{
    struct node *head = malloc(sizeof(struct node));
    creatingNodes(head);

    countingNodes(head);

    printNodes(head);

    insertEnd(head);
    printNodes(head);

    head = insertBeg(head);
    printNodes(head);

    insertCertainPosition(head);
    printNodes(head);

    head = delLastNode(head);
    printNodes(head);

    head = delFirstNode(head);
    printNodes(head);

    head = delCertainNode(head);
    printNodes(head);

    head = reverseSL(head);
    printNodes(head);
    
    head = delEntileSl(head);

    return 0;
}