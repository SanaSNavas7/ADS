#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int i;
struct node
{
    int data;
    struct node *next;
};
void insertbeg();
void insertend();
void insertpos();
void deletebeg();
void deleteend();
void deletepos();
void search();
void display();
void creation();

int main()
{
    int choice;
    while (1)
    {

        printf("Enter choice:\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n");
        printf("4. Delete from beginning\n5. Delete from end\n6. Delete from position\n");
        printf("7. Search\n8. Display\n9.creation \n 10.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertbeg();
            break;
        case 2:
            insertend();
            break;
        case 3:
            insertpos();
            break;
        case 4:
            deletebeg();
            break;
        case 5:
            deleteend();
            break;
        case 6:
            deletepos();
            break;
        case 7:
            search();
            break;
        case 8:
            display();
            break;
        case 9:
            creation();
            break;
        case 10:
            exit(0);
            break;
        default:
            printf("Invalid");
        }
    }
    return 0;
}
struct node *head = NULL;
struct node *tail = NULL;
struct node *newnode;
void creation()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if(head==NULL){
        head=newnode;
        tail=newnode;
        newnode->next=head;
    }
    else{
        tail->next=newnode;
        tail=newnode;
        tail->next=head;
    }
}
void insertbeg()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = head;
        tail->next = newnode;
        head = newnode;
    }
}
void insertend()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->next = head;
    }
}

void insertpos()
{
    int pos;
    struct node *temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d", &newnode->data);
    printf("enter pos to insert: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        insertbeg();
    }
    else
    {
        for (i = 1; i < pos - 1 && temp != head; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void deletebeg()
{
    if (head == NULL)
    {
        printf("list empty");
    }
    else if (head == tail)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        head = head->next;
        tail->next = head;
    }
}
void deleteend()
{
    struct node *temp = head;
    if (head == tail)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = head;
        tail = temp;
    }
}
void deletepos()
{
    int pos;
    struct node *temp = head;
    printf("enter pos to delete: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        deletebeg();
    }
    else
    {
        for (i = 1; i < pos - 1 && temp != head; i++)
        {
            temp = temp->next;
        }
        struct node *del = temp->next;
        if (del == tail)
        {
            temp->next = NULL;
            tail = temp;
        }
        temp->next = temp->next->next;
    }
}
void display()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("empty list");
    }
    else
    {

        while (temp->next != head)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("%d->", temp->data);
    }
}
void search()
{
    int flag = 0;
    int key;
    printf("enter eemenet");
    scanf("%d", &key);
    struct node *temp = head;
   do{
    if(temp->data==key){
        flag=1;
        break;
    }
    temp=temp->next;
   }while(temp!=head);
    if (flag == 0)
    {
        printf("element not found");
    }
    else
    {
        printf("element found");
    }
}