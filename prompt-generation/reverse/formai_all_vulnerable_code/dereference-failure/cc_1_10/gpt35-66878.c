//FormAI DATASET v1.0 Category: Memory management ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

int main() {
    int *ptr, *ptr2, *ptr3;
    int num, i;
    
    printf("Enter number of elements: ");
    scanf("%d", &num);
    
    // dynamic memory allocation using malloc()
    ptr = (int*)malloc(num * sizeof(int));
    
    // initializing values
    for(i = 0; i < num; i++) {
        *(ptr + i) = i;
    }
    
    // displaying values
    printf("The elements are: ");
    for(i = 0; i < num; i++) {
        printf("%d ", *(ptr + i));
    }
    
    // reallocating memory using realloc()
    printf("\nEnter the new size of the array: ");
    scanf("%d", &num);
    ptr2 = (int*)realloc(ptr, num * sizeof(int));
    
    // adding new elements to the array
    for(i = num/2; i < num; i++) {
        *(ptr2 + i) = i;
    }
    
    // displaying values again
    printf("The new elements are: ");
    for(i = 0; i < num; i++) {
        printf("%d ", *(ptr2 + i));
    }
    
    // freeing memory using free()
    free(ptr2);
    
    // assigning NULL to the pointer
    ptr3 = NULL;
    
    // accessing invalid memory
    printf("\nThe elements are: ");
    for(i = 0; i < num; i++) {
        printf("%d ", *(ptr3 + i));
    }
    
    return 0;
}