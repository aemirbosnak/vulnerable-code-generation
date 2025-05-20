//FormAI DATASET v1.0 Category: Memory management ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int* ptr1 = (int*)malloc(10 * sizeof(int));
    for (i = 0; i < 10; i++) {
        *(ptr1 + i) = i + 1;
    }
    printf("ptr1 before realloc operation:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", *(ptr1 + i));
    }
    printf("\n");

    int* ptr2 = (int*)calloc(5, sizeof(int));
    for (i = 0; i < 5; i++) {
        *(ptr2 + i) = (i + 1) * 2;
    }
    printf("ptr2 before realloc operation:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", *(ptr2 + i));
    }
    printf("\n");

    ptr1 = (int*)realloc(ptr1, 15 * sizeof(int));
    for (i = 10; i < 15; i++) {
        *(ptr1 + i) = i + 1;
    }
    printf("ptr1 after realloc operation:\n");
    for (i = 0; i < 15; i++) {
        printf("%d ", *(ptr1 + i));
    }
    printf("\n");

    ptr2 = (int*)realloc(ptr2, 10 * sizeof(int));
    for (i = 5; i < 10; i++) {
        *(ptr2 + i) = (i + 1) * 2;
    }
    printf("ptr2 after realloc operation:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", *(ptr2 + i));
    }
    printf("\n");

    free(ptr1);
    free(ptr2);

    return 0;
}