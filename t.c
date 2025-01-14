#include <stdio.h>
#include <stdio.h>
#define MAX 20
int adj[MAX][MAX], vi[MAX], i, j, n, current;
void main()
{
    printf("enter no of vertices: ");
    scanf("%d", &n);
    printf("enter adj matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("A[%d][%d]", i, j);
            scanf("%d", &adj[i][j]);
        }
    }
    int count = 0;
    int flag = 0;
    while (count != n)
    {
        for (i = 0; i < n; i++)
        {
            if (vi[i] == 0)
            {
                for (j = 0; j < n; j++)
                {
                    if (adj[j][i] == 1)
                    {
                        flag = 1;
                        break;
                    }
                    if (flag == 0)
                    {
                        current = i;
                        printf("%d", current);
                        vi[current] = 1;
                        for (i = 0; i < n; i++)
                        {
                            adj[current][i] = 0;
                        }
                        break;
                    }
                }
            }
        }
    }
}
