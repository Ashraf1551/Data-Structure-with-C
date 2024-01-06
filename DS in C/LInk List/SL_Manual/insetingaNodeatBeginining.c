//hl Method 1 done by me
/*
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
int main()
{
   struct node *head = malloc(sizeof(struct node));
   head->data = 50;
   head->link = NULL;

   struct node *current = malloc(sizeof(struct node));
   current->data = 60;
   current->link = NULL;
   head->link = current;
   
   struct node *newNode = malloc(sizeof(struct node));
   newNode->data = 40;  
   newNode->link = head;  

   head = newNode;

   return 0;
}
*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

// Function to add a node at the beginning of the linked list.
void addNodeAtBeginning(struct node **head, int newData)
{
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    newNode->data = newData;
    newNode->link = *head; // Make the new node point to the current head.
    *head = newNode;      // Update the head to be the new node.
}

int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 50;
    head->link = NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data = 60;
    current->link = NULL;
    head->link = current;

    // Add a node at the beginning of the linked list using the function.
    addNodeAtBeginning(&head, 40);

    return 0;
}
