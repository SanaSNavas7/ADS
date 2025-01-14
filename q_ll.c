#include <stdio.h>
#include <stdlib.h>

void enqueue();
void dequeue();
void display();

struct node {
    int data;
    struct node *next;
};

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

void enqueue() {
    int d;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    printf("Enter a value: ");
    scanf("%d", &d);
    newnode->data = d;
    newnode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    printf("Element %d enqueued\n", d);
}

void dequeue() {
    struct node *temp = front;
    if (front == NULL) {
        printf("Queue underflow (empty queue)\n");
    } else if (front == rear) {
        printf("Element %d dequeued\n", front->data);
        free(front);  // Free the only node
        front = rear = NULL;  // Both front and rear should be NULL
    } else {
        printf("Element %d dequeued\n", front->data);
        front = front->next;  // Move front to the next node
        free(temp);  // Free the old front node
    }
}

void display() {
    struct node *temp = front;
    if (temp == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
