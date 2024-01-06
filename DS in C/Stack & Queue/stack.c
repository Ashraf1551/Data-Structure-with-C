#include<stdio.h>
int stack[100]= {0},s_size=0,top=0;

void push(int item)
{
    if(top==s_size)
    {
        printf("Stack Overflow!!\n");
        return;
    }
    top++;
    stack[top]=item;
}

int pop()
{
    int item;
    if(top==0)
    {
        printf("Stack Underflow!!\n");
        return 0;
    }
    item=stack[top];
    stack[top]=0;
    top--;
    return item;
}
void display()
{
    int i;
    printf("The updated stack:\n");
    for(i=s_size; i>=1; i--)
    {
        printf("%d\n",stack[i]);
    }
}

int main()
{
    int item,a,b;
    printf("Enter the stack size:");
    scanf("%d",&s_size);
    do
    {
        printf("'1' for push.\n'2' for pop.\n'3' for display.\nEnter your choice:");
               scanf("%d",&a);
               if(a==1)
    {
        printf("Enter the value for insert:");
            scanf("%d",&item);//bookname, //book id
            push(item);
            display();
        }
        else if(a==2)
    {
        item=pop();
            if(item!=0)
            {
                printf("The deleted value is:%d",item);
            }
            display();
        }
        else if(a==3)
    {
        display();
        }
        else
        {
            printf("wrong choice. Enter the right choice.\n");
        }
        printf("'1' for run again.\n For exit press any key.\n");
        scanf("%d",&b);
    }
    while(b==1);
    return 0;
}