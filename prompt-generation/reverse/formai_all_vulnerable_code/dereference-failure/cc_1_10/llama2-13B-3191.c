//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMORY 1024

// Invasive memory management functions
void *malloc_invasive(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }
    // Invasively mark the memory as taken
    *(int *)ptr = 1;
    return ptr;
}

void free_invasive(void *ptr) {
    if (ptr == NULL) {
        printf("Error: Invalid memory pointer\n");
        return;
    }
    // Invasively mark the memory as free
    *(int *)ptr = 0;
}

int main() {
    // Allocate some memory
    void *ptr1 = malloc_invasive(100);
    void *ptr2 = malloc_invasive(200);
    void *ptr3 = malloc_invasive(300);

    // Use the memory
    char *str1 = (char *)ptr1;
    strcpy(str1, "Invasive memory management rocks!");

    char *str2 = (char *)ptr2;
    strcpy(str2, "This program is a beast!");

    char *str3 = (char *)ptr3;
    strcpy(str3, "The invasive memory management is the best!");

    // Free the memory
    free_invasive(ptr1);
    free_invasive(ptr2);
    free_invasive(ptr3);

    // Check if the memory is still marked as taken
    for (int i = 0; i < 3; i++) {
        if (*((int *)ptr1) != 0) {
            printf("Memory leak detected at %p\n", ptr1);
        }
        ptr1 = ptr2;
        ptr2 = ptr3;
        ptr3 = NULL;
    }

    return 0;
}