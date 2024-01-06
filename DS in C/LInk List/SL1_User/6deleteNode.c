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
void delNode()
{
    int pos;
    
    /*
    hl Noted that:
    ! current pointer will point to the node, we want to delete.
    ! previous pointer will point to the node, just before the node we want to delete.
    */

    block *current=head, *previous=head;
    printf("Enter node to delete: ");
    scanf("%d", &pos);
    
    if(head==NULL)
    {
        printf("Empty!!");
    }

    else if(pos==1)
    {
        head=current->link;
        free(current);
        current=NULL;
    }
    else
    {
        while (pos!=1)
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

    delNode();
    display();
    return 0;
}