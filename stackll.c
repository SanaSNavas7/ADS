#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode;
struct node *top = NULL;
void push();
void pop();
void peek();
void display();

int main()
{
    while (1)
    {
        int choice;
        printf("\nEnter your choice:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
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
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
void push()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter  data: ");
    scanf("%d", &newnode->data);
    printf("element %d pushed to stack", newnode->data);
    newnode->next = top;
    top = newnode;
}
void pop()
{
    struct node *temp = top;
    if (top == NULL)
    {
        printf("stack empty");
    }
    else
    {
        printf("element %d popped", top->data);
        top = top->next;
    }
}
void peek()
{
    if (top == NULL)
    {
        printf("stack empty");
    }
    else
    {
        printf("top element is %d", top->data);
    }
}
void display()
{
    struct node *temp = top;
    if (top == NULL)
    {
        printf("stack empty");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ->", temp->data);
            temp = temp->next;
        }
    }
}