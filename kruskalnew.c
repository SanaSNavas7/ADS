#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 20
int adj[MAX][MAX] = {0}, par[MAX] = {0}, i, j, u, v, cost = 0, e = 0, min = 999;
int find(int x)
{
    while (par[x] != x)
    {
        x = par[x];
    }
    return x;
}
int uni(int x, int y)
{
    u = find(x);
    v = find(y);
    if(find(u)!=find(v)){
    par[u] = v;
    }
}
void main()
{
    int n;
    printf("enter no of vertices: ");
    scanf("%d", &n);
    printf("enter adj matrix:");
    if (n < MAX)
    {
        for (i = 0; i < n; i++)
        {
          
            for (j = 0; j < n; j++)
            {
                
                scanf("%d", &adj[i][j]);
            }
        }
    }
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
        if (par[u] != par[v])
        {
            uni(u, v);
            e += 1;
            cost += min;
            printf("Edge {%d-%d=%d}",u,v,min);
        }
        adj[u][v]=999;
        adj[v][u]=999;
    }
    printf("Total cost is %d",cost);
}