#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void add_at_end(struct node *head, int data)
{
    struct node *p, *temp;
    p = head;
    temp = malloc(sizeof(struct node));

    temp->data = data;
    temp->link = NULL;

    while(p->link != NULL)
    {
        p = p->link;
    }
    p->link = temp;
}
//hl Whether to check is node added by printing.
//hl It is also used to traverse a SL

void printNodes(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked List is empty");
    }

    struct node *p = NULL;
    p = head;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->link;
    }
}
int main()
{
    struct node *head = malloc(sizeof(struct node));
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

    add_at_end(head, 60);
    printNodes(head);
    return 0;
}