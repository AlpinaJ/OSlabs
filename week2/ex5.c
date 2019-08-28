#include <stdio.h>
int main()
{
    printf("Choose 1,2 or 3\n");
    int choice;
    scanf("%d", &choice);
    printf("Print 1 more number\n");
    int n;
    scanf("%d", &n);

    if (choice == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                printf("* ");
            }
            printf("\n");
        }
    }

    if (choice == 2)
    {
        for (int i = n; i >= 1; i--)
        {
            for (int j = 1; j <= i; j++)
            {
                printf("* ");
            }
            printf("\n");
        }
    }

    if (choice == 3)
    {
        for (int i = n; i >= 1; i--)
        {
            for (int j = 0; j < n - i; j++)
                printf("  ");
            for (int l = i; l <= 2 * i - 1; l++)
                printf("* ");
            for (int l = 0; l < i - 1; l++)
                printf("* ");
            printf("\n");
        }
    }
    return 0;
}