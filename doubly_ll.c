#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next, *prev;
};
struct node *temp, *newnode;
struct node *head = NULL;
void insertbeg();
void insertend();
void insertpos();
void deletebeg();
void deleteend();
void deletepos();
void search();
void display();
int main()
{
    int choice;
    while (1)
    {

        printf("Enter choice:\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n");
        printf("4. Delete from beginning\n5. Delete from end\n6. Delete from position\n");
        printf("7. Search\n8. Display\n9. Exit\n");
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
            exit(0);
            break;
        default:
            printf("Invalid");
        }
    }
    return 0;
}
void insertbeg()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {
        head = newnode;
        newnode->prev = NULL;
        newnode->next = NULL;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}

void insertend()
{
    struct node *temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d", &newnode->data);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    temp->next->prev = temp;
    newnode->prev = temp;
    newnode->next=NULL;
}

void insertpos()
{
    int i, pos;
    struct node *temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d", &newnode->data);
    printf("Enter position to insert: ");
    scanf("%d", &pos);
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
        newnode->next->prev = newnode;
        newnode->prev = temp;
        temp->next = newnode;
    }
}

void deletebeg()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List empty");
    }
    else if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        head = head->next;
        free(temp);
    }
}

void deleteend()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List empty");
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

    int i, pos;
    struct node *temp = head;

    printf("Enter position to insert: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        deletebeg();
    }
    else
    {
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        temp->next->prev = temp;
    }
}
void search()
{
    int flag = 0;
    struct node *temp = head;
    int key;
    printf("enter key: ");
    scanf("%d", &key);
    do{
        if(temp->data==key){
            flag=1;
            break;
        }
        temp=temp->next;
    }while(temp!=NULL);
    if(flag==0){
        printf("elemeent not found");
    }else{
        printf("element found");
    }
}

void display()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List empty");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d-> ", temp->data);
            temp = temp->next;
        }
        printf("NULL");
        
    }
}