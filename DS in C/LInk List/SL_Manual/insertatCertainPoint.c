#include <stdio.h>
struct node
{
    int data;
    struct node *link;
};
void creatingLinkedList()
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 50;
    head->link = NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data = 60;
    current->link = NULL;
    head->link = current;

    current = malloc(sizeof(struct node));
    current->data = 70;
    current->link = NULL;

    head->link->link = current;
}
void countNodes(struct node *head)
{
    int count = 0;
    if (head == NULL)
    {
        printf("Linked List is empty");
    }

    struct node *p = NULL;
    p = head;
    while(p != NULL)
    {
        count++;
        p = p->link;
    }
    printf("%d", count);
}
int main()
{
    creatingLinkedList();
}