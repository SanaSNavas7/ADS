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
int main()
{
    while (1)
    {
        int choice;
        printf("\nEnter:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
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
    printf("enter data: ");
    scanf("%d",&newnode->data);
    if (front == NULL && rear == NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}
void dequeue(){
    struct node *temp=front;
    int a=temp->data;
    if(front==-1){
        printf("empty");
    }else if(front==rear){
        printf("element deleted is %d",a);
        front=NULL;
        rear=NULL;
    }
    
    else{
         printf("element deleted is %d",a);
        front=front->next;
       
    }
}
void display(){
    struct node *temp=front;
    if(front==-1){
        printf("empty");}
        else{
            while(temp!=NULL){
                printf("%d",temp->data);
                temp=temp->next;
            }
        }

}