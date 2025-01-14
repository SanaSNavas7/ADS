#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int a[50], i, j, pos, n;
void insert();
void delete();
void search();
void sort();
void display();
int main()
{

    printf("enter size of array: ");
    scanf("%d", &n);
    printf("enter elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int choice;
    while (1)
    {
        printf("\nEnter choice: \n1. Insert\n2. Delete\n3. Search\n4. Sort\n5. Display\n6. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            search();
            break;
        case 4:
            sort();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}
void insert()
{
    int e;
    printf("enter element: ");
    scanf("%d", &e);
    printf("enter pos: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > n + 1)
    {
        printf("invalid");
    }
    else
    {
        n++;
        for (i = n; i >= pos; i--)
        {
             a[i]=a[i-1];
        }
    }
    a[pos - 1] = e;
}
void delete()
{
    printf("enter pos: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > n)
    {
        printf("invalid");
    }
    else
    {
        for (i = pos - 1; i < n - 1; i++)
        {
          a[i]=a[i+1];
        }
        n--;
    }
}
void sort()
{
    int i, j, temp;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void search()
{
    int key;
    int flag = 0;
    printf("enter key: ");
    scanf("%d", &key);
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            flag = 1;
            break;
        }
    }
    if(flag==1){
        printf("element found at %d",i);
        
    }
    else{
        printf("element not found");
    }
}
void display(){
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}