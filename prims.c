#include <stdio.h>
#include <conio.h>
void main()
{
    int n;
    printf("enter no of vertices: ");
    scanf("%d", &n);
    int A[n][n], vi[n], i, j, u, v, min = 999, e = 1, cost = 0;
    for (i = 0; i < n; i++)
    {
        vi[i] = 0;
    }
    printf("enter adj matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("A[%d][%d]", i, j);
            scanf("%d", &A[i][j]);
            if (A[i][j] == 0)
            {
                A[i][j] = 999;
            }
        }
    }

    min = 999;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (A[i][j] < min)
            {
                min = A[i][j];
                u = i;
                v = j;
            }
        }
    }
    cost += min;
    vi[u] = 1;
    vi[v] = 1;
    printf("Edges {%d-%d}={%d}", u, v, min);

    while (e < n - 1)
    {
        min = 999;
        for (i = 0; i < n; i++)
        {
            if (vi[i] == 1)
                for (j = 0; j < n; j++)
                {
                    if (A[i][j] < min && vi[j] != 1)
                    {
                        min = A[i][j];
                        u = i;
                        v = j;
                    }
                }
        }
        cost += min;
        vi[v] = 1;
        e += 1;
        printf("Edges {%d-%d}={%d}", u, v, min);
    }
    printf("cost is %d", cost);
}