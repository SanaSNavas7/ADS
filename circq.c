#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 20
int q[MAX];
int rear = -1;
int front = -1;

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
    int item;
    printf("enter element");
    scanf("%d", &item);
    if ((rear + 1) % MAX == front)
    {
        printf("overflow");
    }
    else
    {
        if (front ==-1)
        {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        q[rear] = item;
    }
}
void dequeue(){
    int item;
    if(front==-1){
        printf("underflow");
    }else{
        item=q[front];
        if(front==rear){
            front=-1;
            rear=-1;

        }else{
            front=(front+1)%MAX;
        }

    }
    printf("elementsed deletedv is %d",item);

}
void display(){
    int i;
    if(front==-1){
        printf("queue is empty");
    }
    else{
        int i=front;
        while(i!=rear){
            printf("%d",q[i]);
            i=(i+1)%MAX;
        }
        printf("%d",q[rear]);
    }
}