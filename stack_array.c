#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 20
int s[MAX], i;
int top = -1;
void push();
void pop();
void display();
void peek();
int main()
{
    while (1)
    {
        int choice;
        printf("enter 1.push \n 2.pop \n 3.peek \n 4.display \n 5.exit");
        printf("\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("invalid");
        }
    }
    return 0;
}

void push()
{
    int a;
    printf("enter the element: ");
    scanf("%d", &a);
    if (top == MAX - 1)
    {
        printf("overflow");
    }
    else
    {
        top = top + 1;
        s[top] = a;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("underflow");
    }
    else
    {
        printf("popped element is %d", s[top]);
        top--;
    }
}
void peek()
{
    if (top == -1)
    {
        printf("underflow");
    }
    else
    {
        printf("top element is %d", s[top]);
    }
}

void display()
{
    for (i = top;i>=0;i--)
    {
        printf("%d", s[i]);
    }
}