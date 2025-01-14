#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int a[50], i, j, n;
void reverse(int a[], int n);
int main()
{
    int n;
    printf("enter size :");
    scanf("%d", &n);
    printf("enter elements of array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    reverse(a, n);
    return 0;
}
void reverse(int a[], int n)
{
    i = 0;
    j = n - 1;
    while (i < j)
    {

        int temp;
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }

    printf("elements of revresed array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
}