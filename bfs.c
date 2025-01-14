#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int q[20], adj[20][20], vi[20], i, j, n, start, front = -1, rear = -1;
void bfs(int start);
void enqueue(int node);
int dequeue();
int main()
{
    printf("Enter no of vertices: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        vi[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Enter A[%d][%d]", i, j);
            scanf("%d", &adj[i][j]);
        }
    }
    printf("enter starting vertex: ");
    scanf("%d", &start);
    if (start < 0 || start >= n)
    {
        printf("invalid");
    }
    else
    {
        bfs(start);
    }
    return 0;
}

void bfs(int start)
{
    enqueue(start);
    vi[start] = 1;
    printf("%d", start);
    while(front!=-1){
    int node = dequeue();
    for (i = 0; i < n; i++)
    {
        if (adj[node][i] == 1 && vi[i] != 1)
        {
            vi[i] = 1;
            printf("%d", i);
            enqueue(i);
        }
    }
    }
}
void enqueue(int node)
{
    if (rear == 19)
    {
        printf("Overflow");
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear++;
        q[rear] = node;
    }
}

int dequeue()
{
    int node = q[front];
    if (front == -1)
    {
        printf("Underflow");
    }

    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
    return node;
}