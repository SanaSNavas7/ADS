#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int a[50],b[50],c[100],i,j,l,m,n;
int main(){
    printf("enter size of array 1: ");
    scanf("%d",&l);
    for(i=0;i<l;i++){
        scanf("%d",&a[i]);
    }
      printf("enter size of array 2: ");
    scanf("%d",&m);
    for(j=0;j<m;j++){
        scanf("%d",&b[j]);
    }
    printf("array 1 is: ");
    for(i=0;i<l;i++){
        printf("%d",a[i]);
    }
     printf("array 2 is: ");
    for(j=0;j<m;j++){
        printf("%d",b[j]);
    }
    n=l+m;
    for(i=0;i<n;i++){
        c[i]=a[i];
    }
    for(j=0;j<n;j++){
        c[l+j]=b[j];
    }
    printf("Merged array is: ");
    for(i=0;i<n;i++){
        printf("%d",c[i]);
    }
    
}