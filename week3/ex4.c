#include <stdio.h>

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

int partition(int *a, int l, int r)
{
    int pivot = a[r];
    int lowest = l - 1;
    for (int i = l; i < r; ++i)
    {
        if (a[i] <= pivot)
        {
            lowest++;
            swap(&a[i], &a[lowest]);
        }
    }
    swap(&a[lowest + 1], &a[r]);
    return (lowest + 1);
}

void quicksort(int *a, int l, int r)
{
    if (l < r)
    {
        int p = partition(a, l, r);
        quicksort(a, l, p - 1);
        quicksort(a, p + 1, r);
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

    quicksort(a, 0, n - 1);
    printf("Sorted array:\n");
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
