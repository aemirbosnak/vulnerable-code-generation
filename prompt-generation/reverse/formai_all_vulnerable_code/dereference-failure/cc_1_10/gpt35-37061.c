//FormAI DATASET v1.0 Category: Memory management ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Structure for storing memory block information
struct memblock {
    int size;
    struct memblock *next;
    int free;
};

// Function to allocate memory using First Fit algorithm
void *ff_alloc(int size, struct memblock *head) {
    struct memblock *current = head;
    while (current != NULL) {
        if (current->free == 1 && current->size >= size) {
            current->free = 0;
            if (current->size > size + sizeof(struct memblock)) {
                struct memblock *new = (struct memblock *)((char *)current + size + sizeof(struct memblock));
                new->size = current->size - size - sizeof(struct memblock);
                new->next = current->next;
                new->free = 1;
                current->next = new;
            }
            return (void *)(current + 1);
        }
        current = current->next;
    }
    return NULL;
}

// Function to free memory
void ff_free(void *ptr, struct memblock *head) {
    struct memblock *current = (struct memblock *)ptr - 1;
    struct memblock *prev = NULL;
    struct memblock *next = NULL;
    if (current == head) {
        if (current->next != NULL && current->next->free == 1) {
            next = current->next;
            current->size += next->size + sizeof(struct memblock);
            current->next = next->next;
        } else {
            current->free = 1;
        }
    } else {
        prev = head;
        while (prev->next != current) {
            prev = prev->next;
        }
        if (current->next != NULL && current->next->free == 1) {
            next = current->next;
            current->size += next->size + sizeof(struct memblock);
            current->next = next->next;
        }
        if (prev->free == 1) {
            prev->size += current->size + sizeof(struct memblock);
            prev->next = current->next;
        } else {
            current->free = 1;
        }
    }
}

// Function to print memory block information
void print_memblock(struct memblock *head) {
    struct memblock *current = head;
    while (current != NULL) {
        printf("Start Address: %p\n", current);
        printf("Memory Size: %d\n", current->size);
        printf("Is Free?: %d\n", current->free);
        printf("\n");
        current = current->next;
    }
}

int main() {
    // Allocate initial memory block
    struct memblock *head = (struct memblock *)malloc(1024);
    head->size = 1024 - sizeof(struct memblock);
    head->next = NULL;
    head->free = 1;

    // Allocate some memory blocks
    int *ptr1 = (int *)ff_alloc(sizeof(int), head);
    *ptr1 = 10;
    char *ptr2 = (char *)ff_alloc(sizeof(char) * 10, head);
    strcpy(ptr2, "Hello");

    // Print memory block information
    print_memblock(head);

    // Free a memory block
    ff_free(ptr2, head);

    // Print memory block information
    print_memblock(head);

    // Allocate some more memory blocks
    float *ptr3 = (float *)ff_alloc(sizeof(float), head);
    *ptr3 = 3.14;
    double *ptr4 = (double *)ff_alloc(sizeof(double) * 5, head);
    for (int i = 0; i < 5; i++) {
        ptr4[i] = ((double)i + 0.5) * 2.0;
    }

    // Print memory block information
    print_memblock(head);

    // Free all memory blocks
    ff_free(ptr1, head);
    ff_free(ptr3, head);
    ff_free(ptr4, head);

    // Print memory block information
    print_memblock(head);

    // Free the initial memory block
    free(head);
    
    return 0;
}