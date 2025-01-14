#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int set1[50], set2[50], uni[200], size, size1, size2, bitset1[50], bitset2[50], uniarray[100], interarray[50], exists, j = 0, i, temp;
void unionoperation();
void intersection();
int main()
{
    printf("Enter size of universal set");
    printf("\n");
    scanf("%d", &size);
    while (j < size)
    {
        exists = 0;
        printf("enter element: ");
        scanf("%d", &temp);
        for (i = 0; i < size; i++)
        {
            if (temp == uni[i])
            {
                exists = 1;
                printf("element exists");
                break;
            }
        }
        if (exists == 0)
        {
            uni[j] = temp;
            j++;
        }
    }
    printf("elements of universal set: ");
    printf("\n");
    for (i = 0; i < size; i++)
    {
        printf("%d", uni[i]);
    }
    j = 0;
    printf("Enter size of  set 1");
    printf("\n");
    scanf("%d", &size1);
    while (j < size1)
    {
        exists = 0;
        printf("enter element: ");
        scanf("%d", &temp);
        for (i = 0; i < size1; i++)
        {
            if (temp == set1[i])
            {
                exists = 1;
                printf("element exists");
                break;
            }
        }
        if (exists == 0)
        {
            set1[j] = temp;
            j++;
        }
    }
    printf("elements of set 1: ");
    printf("\n");
    for (i = 0; i < size1; i++)
    {
        printf("%d", set1[i]);
    }
    j = 0;
    printf("Enter size of set 2");
    printf("\n");
    scanf("%d", &size2);
    while (j < size2)
    {
        exists = 0;
        printf("enter element: ");
        printf("\n");
        scanf("%d", &temp);
        for (i = 0; i < size2; i++)
        {
            if (temp == set2[i])
            {
                exists = 1;
                printf("element exists");
                break;
            }
        }
        if (exists == 0)
        {
            set2[j] = temp;
            j++;
        }
    }
    printf("elements of  set 2: ");
    printf("\n");
    for (i = 0; i < size2; i++)
    {
        printf("%d", set2[i]);
    }

    printf("Bit string of set 1");
    printf("\n");
    for (i = 0; i < size; i++)
    {
        bitset1[i] = 0;

        for (j = 0; j < size1; j++)
        {
            if (uni[i] == set1[j])
            {
                bitset1[i] = 1;
                break;
            }
        }
    }
    for (i = 0; i < size; i++)
    {
        printf("%d", bitset1[i]);
    }
    printf("Bit string of set 2: ");
    printf("\n");
    for (i = 0; i < size; i++)
    {
        bitset2[i] = 0;

        for (j = 0; j < size2; j++)
        {
            if (uni[i] == set2[j])
            {
                bitset2[i] = 1;
                break;
            }
        }
    }
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
            unionoperation();
            break;
        case 2:
            intersection();
            break;
        }
    }
    return 0;
}
void unionoperation()
{
    printf("Union operation");
    for (i = 0; i < size; i++)
    {
        uniarray[i] = bitset1[i] || bitset2[i];
        printf("%d", uniarray[i]);
    }
}
void intersection()
{
    printf("Intersection operation");
    for (i = 0; i < size; i++)
    {
        interarray[i] = bitset1[i] && bitset2[i];
        printf("%d", interarray[i]);
    }
}
