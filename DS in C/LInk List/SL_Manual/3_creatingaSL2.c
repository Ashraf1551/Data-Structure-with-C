//hl This is 1st method to create 2more nodes
//! This method is not a good practice
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
    head->data=50;
    head->link=NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data=60;
    current->link=NULL;
    head->link=current;

    struct node *current2 = malloc(sizeof(struct node));
    current2->data=70;
    current2->link=NULL;
    current->link=current2;
    
    return 0;
}
*/

//hl This is 2nd method to create 2more nodes
//* It is good practice to follow method2
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
   head->data=50;
   head->link=NULL;

   struct node *current = malloc(sizeof(struct node));
   current->data=60;
   current->link=NULL;
   head->link=current;
   
   current = malloc(sizeof(struct node));
   current->data=70;
   current->link=NULL;

   head->link->link=current;

   return 0;
}
