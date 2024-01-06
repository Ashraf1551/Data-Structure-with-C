#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    int *p = (int *)malloc(2*sizeof(int));

    if (p == NULL)
    {
        printf("Memory not available.");
        exit(1);
    }

    printf("Enter two numbers: ");
    for (int i = 0; i < 2; i++)
    {
        scanf("%d", p + 1);
    }

    p = (int *)realloc(p, 4*sizeof(int));

    if (p == NULL)
    {
        printf("Memory not available.");
        exit(1);
    }

    printf("Enter two more integer: ");
    for (int i = 2; i < 4; i++)
    {
        scanf("%d", p + i);
    }
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", *(p + i));
    }
    return 0;
}