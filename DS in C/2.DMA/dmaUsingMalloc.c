#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n, i;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    int *p = (int *)malloc(n*sizeof(int));
    //IN calloc===>
    // int *p = (int *)calloc(n, sizeof(int));

    if(p == NULL)
    {
        printf("Memory not available.");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter %d st integer: ", i+1);
        scanf("%d", p + i);//pointer contains address itself so we don't need to use & sign.
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(p + i));
    }
    return 0;
}