#include <stdio.h>
#include <conio.h>
#include <limits.h>

void diji(int n, int a[n][n],int v[],int d[], int start)
{
    d[start] = 0;
    for (int count = 0; count < n - 1; count++)
    {
        int min = INT_MAX;
       int u = -1;
        for (int i = 0; i < n; i++)
        {
            if (!v[i] && d[i] < min)
            {
                min = d[i];
                u = i;
            }
        }

        if (u == -1)
            break;
        v[u] = 1;
        for (int i = 0; i < n; i++)
        {

            if (!v[i] && a[u][i] != 0 && d[u] + a[u][i] < d[i])
            {
                d[i] = d[u] + a[u][i];
            }
        }
    }
}
int main()
{
    int n;
    printf("enter no of vertices: ");
    scanf("%d", &n);
    int start, a[n][n], v[n], d[n], i, j, u;
    for (i = 0; i < n; i++)
    {
        v[i] = 0;
        d[i] = INT_MAX;
    }
    printf("enter matrix:");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            if(a[i][j]==-1){
a[i][j]=0;
            }
        }
    }
    printf("enter starting vertex:");
    scanf("%d", &start);
    diji(n, a, v, d, start);
   
    for(int i=0;i<n;i++){

    if (d[i] == INT_MAX)
    {
        printf("node %d unreachable from %d",i,start);
    }
    else
    {
        printf("distance between %d is %d", i, d[i]);
    }
}
return 0;
}