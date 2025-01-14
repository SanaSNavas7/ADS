#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 20
int q[MAX];
int front = -1;
int rear = -1;
int i;
void enqueue();
void dequeue();
void display();
int main() {
    while (1) {
        int choice;
        printf("\nEnter:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid entry\n");
        }
    }
    return 0;
}
void enqueue()
{
    int a;
    printf("enter element: ");
    scanf("%d", &a);
    if (front > MAX - 1)
    {
        printf("overflow");
    }
    else if (front == -1)
    {
        front = 0;
    }
    rear++;
    q[rear] = a;
}
void dequeue()
{
    int item;
    item = q[front];
    if (front == -1)
    {
        printf("underflow");
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
    printf("element deleted is %d", item);
}
void display()
{
    if (front == -1)
    {
        printf("List empty");
    }
    else
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d", q[i]);
        }
    }
}