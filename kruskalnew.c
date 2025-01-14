#include <stdio.h>
#include <conio.h>
#define MAX 20
int adj[MAX][MAX] = {0}, par[MAX] = {0}, u, v, i, j, min = 999, cost = 0, e = 0;
int find(int x)
{
    if (x != par[x])
    {
        x = par[x];
    }
    return x;
}
int uni(int x, int y)
{
    int u = find(x);
    int v = find(y);
    if (find(x) != find(y))
    {
        par[u] = v;
    }
}
void main()
{
    int n;
    printf("enter no of vertices: ");
    scanf("%d", &n);
    if(n<MAX){
    printf("adj matrix: ");
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
        min=999;
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
            uni(u, v);
            cost += min;
            e += 1;
            printf("edges {%d-%d}={%d}", u, v, min);
        }
        adj[u][v]=999;
        adj[v][u]=999;
    }
    printf("cost is %d",cost);
}
