#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void bubbleSort(int *a, int n)
{
    int i, j;
    int changed = 1;
    while (changed)
    {
        changed = 0;
        for (j = 1; j < n; j++)
        {

            if (a[j] < a[j - 1])
            {
                changed = 1;
                swap(&a[j], &a[j - 1]);
            }
        }
    }
}

int main()
{
    printf("Print size of the array\n");
    int n;
    scanf("%d", &n);
    printf("Print the elements of array\n");

    //creation of array of n elements
    int *a = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    bubbleSort(a, n);

    printf("Sorted array:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}