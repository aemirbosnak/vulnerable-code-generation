//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void *my_malloc(size_t size);
void my_free(void *ptr);

int main() {
    void *ptr1, *ptr2, *ptr3;
    int i;

    // Allocate memory using our custom malloc function
    ptr1 = my_malloc(10 * sizeof(int));
    ptr2 = my_malloc(20 * sizeof(int));
    ptr3 = my_malloc(30 * sizeof(int));

    // Initialize allocated memory
    for (i = 0; i < 10; i++) {
        ((int*)ptr1)[i] = i;
    }

    for (i = 0; i < 20; i++) {
        ((int*)ptr2)[i] = i;
    }

    for (i = 0; i < 30; i++) {
        ((int*)ptr3)[i] = i;
    }

    // Print allocated memory
    printf("Allocated memory:\n");
    printf("ptr1: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", ((int*)ptr1)[i]);
    }
    printf("\n");

    printf("ptr2: ");
    for (i = 0; i < 20; i++) {
        printf("%d ", ((int*)ptr2)[i]);
    }
    printf("\n");

    printf("ptr3: ");
    for (i = 0; i < 30; i++) {
        printf("%d ", ((int*)ptr3)[i]);
    }
    printf("\n");

    // Free allocated memory
    my_free(ptr1);
    my_free(ptr2);
    my_free(ptr3);

    return 0;
}

// Our custom malloc function
void *my_malloc(size_t size) {
    void *ptr;

    // Allocate memory using system malloc
    ptr = malloc(size);

    if (ptr == NULL) {
        printf("Error: Out of memory!\n");
        exit(1);
    }

    return ptr;
}

// Our custom free function
void my_free(void *ptr) {
    free(ptr);
}