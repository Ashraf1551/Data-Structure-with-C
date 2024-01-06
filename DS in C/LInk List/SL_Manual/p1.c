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
int main()
{
    struct node *head = malloc(sizeof(struct node));
    creatingNodes(head);

    head = delEntileSl(head);
    printNodes(head);
}