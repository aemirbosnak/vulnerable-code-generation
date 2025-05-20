//FormAI DATASET v1.0 Category: Memory management ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr1, *ptr2;
    ptr1 = (int*)malloc(5*sizeof(int));
    if(ptr1==NULL)
    {
        printf("Memory allocation failed for ptr1.\n");
        exit(0);
    }
    else
    {
        printf("Memory allocation at %p was successful for ptr1.\n", ptr1);
        for(int i=0;i<5;i++)
            *(ptr1+i) = i+1;
    }
    
    ptr2 = (int*)calloc(4, sizeof(int));
    if(ptr2==NULL)
    {
        printf("Memory allocation failed for ptr2.\n");
        exit(0);
    }
    else
    {
        printf("Memory allocation at %p was successful for ptr2.\n", ptr2);
        for(int i=0;i<4;i++)
            *(ptr2+i) = i+10;
    }
    
    printf("Contents of ptr1: ");
    for(int i=0;i<5;i++)
        printf("%d ",*(ptr1+i));
    printf("\n");
    
    printf("Contents of ptr2: ");
    for(int i=0;i<4;i++)
        printf("%d ",*(ptr2+i));
    printf("\n");
    
    ptr1 = (int*)realloc(ptr1, 8*sizeof(int));
    if(ptr1==NULL)
    {
        printf("Memory reallocation failed for ptr1.\n");
    }
    else
    {
        printf("Memory reallocation from %p to %p was successful for ptr1.\n",ptr1,ptr1+8);
        for(int i=5;i<8;i++)
            *(ptr1+i) = i+1;
    }
    
    printf("Contents of ptr1 after reallocation: ");
    for(int i=0;i<8;i++)
        printf("%d ",*(ptr1+i));
    printf("\n");
    
    free(ptr1);
    free(ptr2);
    
    return 0;
}