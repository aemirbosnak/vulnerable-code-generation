//FormAI DATASET v1.0 Category: Memory management ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    printf("Welcome to my Memory Management example program!\n");
    printf("I am so excited to show you how memory allocation works in C!\n");

    int *ptr1, *ptr2, *ptr3;

    printf("\nFirst, I'm going to allocate 3 integer variables with malloc and print their values:\n");

    ptr1 = (int*)malloc(sizeof(int));
    ptr2 = (int*)malloc(sizeof(int));
    ptr3 = (int*)malloc(sizeof(int));

    *ptr1 = 1;
    *ptr2 = 2;
    *ptr3 = 3;

    printf("The value of ptr1 is %d\n", *ptr1);
    printf("The value of ptr2 is %d\n", *ptr2);
    printf("The value of ptr3 is %d\n", *ptr3);

    printf("\nNow, I'm going to free ptr1 and realloc ptr2 to be a larger array with calloc:\n");

    free(ptr1);
    ptr2 = (int*)calloc(4, sizeof(int));

    printf("The value of ptr1 is now invalid because it was freed.\n");

    printf("The value of ptr2[0] is %d\n", ptr2[0]);
    printf("The value of ptr2[1] is %d\n", ptr2[1]);
    printf("The value of ptr2[2] is %d\n", ptr2[2]);
    printf("The value of ptr2[3] is %d\n", ptr2[3]);
    
    printf("\nFinally, I'm going to use realloc to increase the size of ptr3 and print the new values:\n");

    ptr3 = (int*)realloc(ptr3, 2 * sizeof(int));

    *ptr3 = 4;
    *(ptr3 + 1) = 5;

    printf("The value of ptr3[0] is now %d\n", ptr3[0]);
    printf("The value of ptr3[1] is now %d\n", ptr3[1]);

    printf("\nI hope you enjoyed learning about memory management in C with me! Bye!\n");

    free(ptr2);
    free(ptr3);

    return 0;
}