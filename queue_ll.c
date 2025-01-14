#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void enqueue();
void dequeue();
void display();
struct node *newnode;
struct node *front = NULL;
struct node *rear = NULL;
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
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}
void dequeue()
{
    struct node *temp = front;
    if (front == NULL)
    {
        printf("underflow");
    }
    else if (front == rear)
    {
        printf("deleted is %d", temp->data);
        front=NULL;
        rear=NULL;
    }
    else{ printf("deleted is %d", temp->data);
    front=front->next;
        
    }
}
void display()
{
    struct node *temp = front;
    if (front == NULL)
    {
        printf("underflow");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
    }
}
