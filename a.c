#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int a[50], n, i, j, pos;
void insert();
void delete();
void search();
void display();
void sort();
void main()
{
    printf("enter size of array: ");
    scanf("%d", &n);
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
}
void insert()
{
    int e;
    printf("enter position: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > n + 1)
    {
        printf("invalid");
    }
    else
    {
        printf("enter element: ");
        scanf("%d", &e);
        n++;
        for (i = n; i >= pos; i--)
        {
            a[i] = a[i - 1];
        }
        a[pos - 1] = e;
    }
}
void delete()
{
    int e;
    printf("enter position: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > n)
    {
        printf("invalid");
    }
    else
    {
        for (i = pos - 1; i < n - 1; i++)
        {
            a[i] = a[i + 1];
        }
        n--;
    }
}
void sort()
{
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void display()
{
    printf("enter array elements");
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
}
void search(){
    int flag=0;
    int key;
    printf("enter key ");
    scanf("%d",&key);
    for(i=0;i<n;i++){
        if(a[i]==key){
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("not found");
    }
    else{
        printf("found");
    }
}