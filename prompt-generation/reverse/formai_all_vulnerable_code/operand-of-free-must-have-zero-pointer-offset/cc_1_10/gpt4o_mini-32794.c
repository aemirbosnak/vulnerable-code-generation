//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALLOCATIONS 10
#define ARRAY_SIZE 20
#define MEMORY_FENCE 0xDEADBEEF

typedef struct {
    void *address;
    size_t size;
    int is_allocated;
} Allocation;

Allocation allocations[MAX_ALLOCATIONS];

void init_allocations() {
    for(int i = 0; i < MAX_ALLOCATIONS; i++) {
        allocations[i].address = NULL;
        allocations[i].size = 0;
        allocations[i].is_allocated = 0;
    }
}

void* paranoid_malloc(size_t size) {
    if (size <= 0) {
        fprintf(stderr, "Error: Invalid allocation size requested: %zu\n", size);
        return NULL;
    }

    void *ptr = malloc(size + sizeof(int));
    if (!ptr) {
        fprintf(stderr, "Error: malloc failed for size: %zu\n", size);
        return NULL;
    }
    
    *(int *)ptr = MEMORY_FENCE; // Memory fence
    void* user_ptr = (char *)ptr + sizeof(int);
    
    for(int i = 0; i < MAX_ALLOCATIONS; i++) {
        if (!allocations[i].is_allocated) {
            allocations[i].address = ptr;
            allocations[i].size = size;
            allocations[i].is_allocated = 1;
            return user_ptr;
        }
    }
    
    fprintf(stderr, "Warning: Maximum allocations reached, cannot track allocations anymore\n");
    free(ptr); // Freeing the allocated memory if we can't track it
    return user_ptr; // This returns a user pointer but it will not be tracked
}

void paranoid_free(void *ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "Warning: Attempted to free a NULL pointer\n");
        return;
    }
    
    void *real_ptr = (char *)ptr - sizeof(int);
    
    // Check for memory fence
    if (*(int *)real_ptr != MEMORY_FENCE) {
        fprintf(stderr, "Error: Invalid pointer being freed, possible corruption detected\n");
        return;
    }

    free(real_ptr);
    
    for(int i = 0; i < MAX_ALLOCATIONS; i++) {
        if (allocations[i].address == real_ptr) {
            allocations[i].is_allocated = 0;
            allocations[i].address = NULL;
            allocations[i].size = 0;
            return;
        }
    }
    
    fprintf(stderr, "Warning: Unknown pointer freed, cannot track de-allocation\n");
}

void print_allocations() {
    printf("Current active allocations:\n");
    for (int i = 0; i < MAX_ALLOCATIONS; i++) {
        if (allocations[i].is_allocated) {
            printf("Allocation[%d]: Address: %p, Size: %zu\n",
                   i, allocations[i].address, allocations[i].size);
        }
    }
}

int main() {
    init_allocations();
    
    printf("Paranoid Memory Management App\n");
    
    // Allocate some memory
    char *data1 = (char *)paranoid_malloc(ARRAY_SIZE);
    if (data1) {
        strcpy(data1, "Hello");
        printf("Allocated string: %s\n", data1);
        print_allocations();
    }

    int *data2 = (int *)paranoid_malloc(sizeof(int) * 5);
    if(data2) {
        for (int i = 0; i < 5; i++) {
            data2[i] = i + 1;
        }
        printf("Allocated int array: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", data2[i]);
        }
        printf("\n");
        print_allocations();
    }

    // Free the allocated memory
    paranoid_free(data1);
    print_allocations();

    paranoid_free(data2);
    print_allocations();

    // Invalid operations to test robustness
    paranoid_free(NULL);
    char *invalid_ptr = (char *)malloc(10);
    paranoid_free(invalid_ptr); // Not managed by our paranoid

    return 0;
}