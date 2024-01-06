#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
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

    printNodes(head);
    return 0;
}