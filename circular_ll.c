#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;
struct node *newnode;
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
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {
        head = tail = newnode;
        newnode->next = head;
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
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {
        head = tail = newnode;
        newnode->next = head;
    }
    else
    {
        tail->next = newnode;
        newnode->next = head;
        tail = newnode;
    }
}

void insertpos()
{
    int i, pos;
    struct node *temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    printf("Enter pos: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        insertbeg();
    }
    else
    {

        for (i = 1; i < pos - 1 && temp->next != head; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void deletebeg()
{
    struct node *temp = head;

    if (head == tail)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        head = head->next;
        tail->next = head;
        free(temp);
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
    int i, pos;
    struct node *temp = head;
    printf("Enter pos: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        deletebeg();
    }
    if (temp->next == head)
    {
        printf("Invalid");
    }

    else
    {
        for (i = 1; i < pos - 1 && temp->next != head; i++)
        {
            temp = temp->next;
        }

        struct node *del = temp->next;
        if (del == tail)
        {
            temp->next = head;
            tail = temp;
        }
        temp->next = temp->next->next;
    }
}

void search()
{
    int flag = 0, key;
    struct node *temp = head;
    printf("enter key: ");
    scanf("%d", &key);
    do
    {
        if (temp->data == key)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    } while (temp != head);
    if (flag == 0)
    {
        printf("Element not found");
    }
    else
    {
        printf("Element found");
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
        do
        {
            printf("%d-> ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}