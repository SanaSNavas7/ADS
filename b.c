#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int set1[20], set2[20], uni[20], bitset1[20], bitset2[20], unio[40], inter[40], i, j = 0, temp, exists, size, size1, size2;
void uniona();
void intersa();
void main()
{
    printf("enter size of universal set: ");
    scanf("%d", &size);
    while (j < size)
    {
        exists = 0;
        printf("enter elements: ");
        scanf("%d", &temp);

        for (i = 0; i < size; i++)
        {
            if (temp == uni[i])
            {
                exists = 1;
                
            }
        }
        if (exists == 0)
        {
            uni[j] = temp;
            j++;
        }
    }
    printf("universal set is: ");
    for (i = 0; i < size; i++)
    {
        printf("%d", uni[i]);
    }
    printf("enter size of  set 1: ");
    scanf("%d", &size1);
    j = 0;
    while (j < size1)
    {
        exists = 0;
        printf("enter elements: ");
        scanf("%d", &temp);

        for (i = 0; i < size; i++)
        {
            if (temp == set1[i])
            {
                exists = 1;
                
            }
        }
        if (exists == 0)
        {
            set1[j] = temp;
            j++;
        }
    }
    printf("set1 is: ");
    for (i = 0; i < size1; i++)
    {
        printf("%d", set1[i]);
    }
    printf("enter size of  set 2: ");
    scanf("%d", &size2);
    j = 0;
    while (j < size2)
    {
        exists = 0;
        printf("enter elements: ");
        scanf("%d", &temp);

        for (i = 0; i < size2; i++)
        {
            if (temp == set2[i])
            {
                exists = 1;
                
            }
        }
        if (exists ==0)
        {
            set2[j] = temp;
            j++;
        }
    }
    printf("set 2 is: ");
    for (i = 0; i < size2; i++)
    {
        printf("%d", set2[i]);
    }
    printf("bitstring set 1: ");
    for (i = 0; i < size; i++)
    {
        bitset1[i] = 0;
        
    
    for (j = 0; j < size; j++)
    {
        if (uni[i] == set1[j])
        {
            bitset1[i] = 1;
            break;
        }
    }}
    for (i = 0; i < size; i++)
    {
        printf("%d", bitset1[i]);
    }
    printf("bitstring set 2: ");
    for (i = 0; i < size; i++)
    {
        bitset2[i] = 0;
        
    
    for (j = 0; j < size; j++)
    {
        if (uni[i] == set2[j])
        {
            bitset2[i] = 1;
            break;
        }
    }}
    for (i = 0; i < size; i++)
    {
        printf("%d", bitset2[i]);
    }
    int choice;
    while (1)
    {
        printf("enter 1.union \n 2.intersection \n");
        printf("\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            uniona();
            break;
        case 2:
            intersa();
            break;
        }
    }}
    void uniona()
    {
        printf("union: ");
        for (i = 0; i < size; i++)
        {
            unio[i] = bitset1[i] || bitset2[i];
        
        printf("%d",unio[i]);
        }
    }
    void intersa()
    {
        printf("intersection: ");
        for (i = 0; i < size; i++)
        {
            inter[i] = bitset1[i] && bitset2[i];
        
        
            printf("%d", inter[i]);
        }
    }
