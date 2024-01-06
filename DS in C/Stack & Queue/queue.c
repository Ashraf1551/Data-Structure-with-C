#include <stdio.h>

int inp_arr[100] = {0};
int q_size = 0;
int Rear = - 1;
int Front = - 1;


void enqueue(int item)
{
    if (Rear == q_size - 1)
    {
        printf("Overflow \n");
    }
    else
    {
        if (Front == - 1)
        {
            Front = 0;
        }

        Rear = Rear + 1;
        inp_arr[Rear] = item;
    }
}

void dequeue()
{
    if (Front == - 1 || Front > Rear)
    {
        printf("Underflow \n");
        return;
    }
    else
    {
        printf("Element deleted from the Queue: %d\n", inp_arr[Front]);
        Front = Front + 1;
    }
}

void display()
{
    if (Front == - 1)
    {
        printf("Empty Queue \n");
    }
    else
    {
        printf("The Created & Updated Queue: \n");
        for (int i = Front; i <= Rear; i++)
        {
            printf("%d ", inp_arr[i]);
        }
        printf("\n");
    }
}
int main()
{
    int item, ch1, ch2;

    printf("Enter the size of QUEUE: ");
    scanf("%d", &q_size);

    do
    {
        printf("1.Enqueue Operation\n");
        printf("2.Dequeue Operation\n");
        printf("3.Display the Queue\n");

        printf("Enter your Choice: ");
        scanf("%d", &ch1);

        if(ch1==1)
        {
            printf("Enter the value for insert:");
            scanf("%d",&item);
            enqueue(item);
            display();
        }
        else if(ch1==2)
        {
            dequeue();
            display();
        }
        else if(ch1==3)
        {
            display();
        }
        else
        {
            printf("wrong choice. Enter the right choice.\n");
        }

        printf("'1' for run again.or For exit press any key.\n");
        scanf("%d",&ch2);

    }
    while(ch2==1);
}