#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
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

    countNodes(head);
    return 0;
}