#include <stdio.h>
#include <stdbool.h>

int main()
{
    // freopen("input_ok.txt", "r", stdin);
    // freopen("output_ok.txt", "w", stdout);
    freopen("input_dl.txt", "r", stdin);
    freopen("output_dl.txt", "w", stdout);
    int n = 3;
    int m = 5;
    int e[n];
    int a[n];
    int c[m][n];
    int r[m][n];

    // Reading input
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &e[i]);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &c[i][j]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &r[i][j]);
        }
    }

    bool flag = false;
    while (!flag)
    {
        flag = true;
        bool flag1 = false;
        for (int j = 0; j < m; j++)
        {
            bool ok = true;
            bool linezeroes = true;
            for (int k = 0; k < n; k++)
            {
                if (r[j][k] != 0)
                {
                    linezeroes = false;
                }

                if (r[j][k] > a[k])
                {
                    ok = false;
                    break;
                }
            }
            if (!linezeroes)
            {
                flag = false;
            }
            if (ok && !linezeroes)
            {
                flag1 = true;
                for (int k = 0; k < n; k++)
                {
                    r[j][k] = 0;
                    a[k] += c[j][k];
                    c[j][k] = 0;
                }
            }
        }

        if (!flag1)
        {
            if (flag)
            {
                printf("NO DEADLOCK\n");
            }
            else
            {
                printf("DEADLOCK. Processes deadlocked:\n");
                for (int i = 0; i < m; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (r[i][j] != 0)
                        {
                            printf("%d ", (i + 1));
                            break;
                        }
                    }
                }
                printf("\n");
            }
            return 0;
        }
    }
}