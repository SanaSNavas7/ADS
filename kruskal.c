#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 10
int adj[MAX][MAX] = {0}, par[MAX] = {0}, i, j, e = 1, cost = 0, min = 999, u, v;
int find(int x)
{
    while (x != par[x])
    {
        x = par[x];
    }
    return x;
}
int uniona(int x, int y)
{
    int u = find(x);
    int v = find(y);
    par[v] = u;
}
void main()
{
    int n;
    printf("enter n: ");
    scanf("%d", &n);
    printf("Adjacency matrix: ");
    if(n<=MAX){
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }}
    for (i = 0; i < n; i++)
    {
        par[i] = i;
    }
    while (e < n - 1)
    {
        min = 999;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (adj[i][j] < min && adj[i][j] != 0)
                {
                    min = adj[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        if (find(u) != find(v))
        {
            uniona(u, v);
            e += 1;
            cost += min;

            printf("Edge {%d,%d=%d}\n", u, v, min);
        }
        adj[i][j]=999;
        adj[j][i]=999;
    }
    printf("Total cost is %d",cost);
}