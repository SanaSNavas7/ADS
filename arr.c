#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int a[20], b[20], c[40], i, j, l, m, n;
int main()
{
    printf("enter size of arr1: ");
    scanf("%d", &l);
    for (i = 0; i < l; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("first array is: ");
    for (i = 0; i < l; i++)
    {
        printf("%d", a[i]);
    }
    printf("enter size of arr2: ");
    scanf("%d", &m);
    for (j = 0; j < m; j++)
    {
        scanf("%d", &b[j]);
    }
    printf("second array is: ");
    for (j = 0; j < m; j++)
    {
        printf("%d", b[j]);
    }

    n = l + m;
    for (i = 1; i < n; i+2)
    {
        c[i]=a[i];
    }
    for(j=0;j<n;j+2){
        c[n+i]=b[j];
    }
    printf("merged array is: ");
    for(i=0;i<n;i++){
        printf("%d",c[i]);
    }
    return 0;
}