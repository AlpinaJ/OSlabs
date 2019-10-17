#include <stdio.h>
#include <stdlib.h>

int aging(int **arr, int size)
{
    int mi = 0;
    int ms = 100000000;
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = 7; j > 0; j--)
        {
            sum = sum + arr[i][j] * (1 << (8 - j));
        }
        if (sum < ms)
        {
            ms = sum;
            mi = i;
        }
    }
    return mi;
}

void shift(int **arr, int size, int pos)
{
    //shift and put zeroes everywhere
    for (int i = 0; i < size; i++)
    {
        for (int j = 7; j > 1; j--)
        {
            arr[i][j] = arr[i][j - 1];
        }
    }

    //set R on the corresponding position
    arr[pos][1] = 1;
}

int find(int **arr, int size, int curr)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i][0] == curr)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int counter = 0, n, hits = 0, miss = 0;

    //Read number of page frames
    printf("Write the number of page frames: ");
    scanf("%d", &n);
    printf("\n");

    freopen("Lab 09 input.txt", "r", stdin);

    int **arr = malloc(sizeof(int *) * n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = malloc(sizeof(int) * 8);
        for (int j = 0; j < 8; ++j)
        {
            arr[i][j] = 0;
        }
    }

    while (1)
    {
        int curr = -1;
        scanf("%d", &curr);

        if (curr == EOF)
            break;
        printf("current page frame%d\n", curr);
        int pos_for_shift = 0;

        if (counter < n)
        {
            miss++;
            arr[counter][0] = curr;
            pos_for_shift = counter;
        }
        else
        {
            int pos = find(arr, n, curr);
            if (pos == -1)
            {
                miss++;

                int deli = aging(arr, n);
                arr[deli][0] = curr;
                pos_for_shift = deli;
            }
            else
            {
                hits++;
                pos_for_shift = pos;
            }
        }

        shift(arr, n, pos_for_shift);
        counter++;
    }

    //final output
    printf("hits = %d\n", hits);
    printf("miss = %d\n", miss);

    printf("hit/miss ratio = %f\n", ((double)hits / miss));
}