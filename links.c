#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
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
void insertion();
int main()
{
    int choice;
    while (1)
    {

        printf("Enter choice:\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n");
        printf("4. Delete from beginning\n5. Delete from end\n6. Delete from position\n");
        printf("7. Search\n8. Display\n9.insertion \n  10.Exit\n");
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
            insertion();
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
int i, pos;
struct node *newnode;
struct node *temp;
struct node *head = NULL;
void insertion()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        newnode->next = NULL;
    }
    else
    {
        head->next = newnode;
        newnode->next = NULL;
    }
}
void insertbeg()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        newnode->next = NULL;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}
void insertend()
{
    struct node *temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d", &newnode->data);
  
    if (head == NULL)
    {
        head = newnode;
        newnode->next = NULL;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
    }
}
void insertpos()
{
    struct node *temp=head;

    printf("enter pos:");
    scanf("%d", &pos);
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d", &newnode->data);
    if (pos == 1)
    {
        insertbeg();
    }
    else
    {
        for (i = 1; i < pos - 1; i++)
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
    else if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        head = head->next;
    }
}
void deleteend()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("list empty");
    }
    else if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
    }
}

void deletepos()
{
    struct node *temp = head;
    int pos;
    printf("enter pos: ");
    scanf("%d", &pos);
    if (head == NULL)
    {
        printf("list empty");
    }
    else
    {
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }
}

void search()
{
    struct node *temp = head;
    int key;
    int flag = 0;
    printf("enter key: ");
    scanf("%d", &key);
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("element found");
    }
    else
    {
        printf("not found");
    }
}
void display(){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}