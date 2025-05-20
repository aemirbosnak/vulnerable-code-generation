//FormAI DATASET v1.0 Category: Memory management ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>

#define MAX_MEM 1024 // Maximum size of memory
#define MAX_ALLOCATIONS 10 // Maximum allocations allowed

// Node structure for allocation
struct allocation{
    void *ptr; // Pointer to memory chunk
    size_t size; // Size of memory chunk
};

// Allocate memory function
void* allocate_memory(size_t size, struct allocation *allocations, int *allocated) {
    if(*allocated >= MAX_ALLOCATIONS) { // Check if the maximum allocations limit has been reached
        printf("Error: Cannot allocate more memory. Maximum allocations limit has been reached.\n");
        return NULL;
    }
    void *ptr = malloc(size); // Allocate memory
    if(ptr == NULL) { // Check if allocation was successful
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }
    allocations[*allocated].ptr = ptr; // Store allocation information
    allocations[*allocated].size = size;
    (*allocated)++; // Increment the number of allocations
    printf("Memory allocated successfully. Address: %p, Size: %zu\n", ptr, size);
    return ptr; // Return the pointer to allocated memory
}

// Free memory function
void free_memory(void *ptr, struct allocation *allocations, int *allocated) {
    int found = 0;
    for(int i=0; i<*allocated; i++) { // Loop through all allocations
        if(allocations[i].ptr == ptr) { // Check if the memory chunk has been allocated previously
            found = 1;
            free(ptr); // Free memory
            printf("Memory freed successfully. Address: %p, Size: %zu\n", ptr, allocations[i].size);
            for(int j=i; j<*allocated-1; j++) { // Shift the allocations leftwards
                allocations[j] = allocations[j+1];
            }
            (*allocated)--; // Decrement the number of allocations
            break;
        }
    }
    if(!found) {
        printf("Error: Invalid memory chunk provided. Cannot free memory.\n");
    }
}

// Main function
int main() {
    struct allocation allocations[MAX_ALLOCATIONS]; // Array to store allocation information
    int allocated = 0; // Number of allocations
    printf("Memory management program\n");
    void *ptr1 = allocate_memory(64, allocations, &allocated); // Allocate memory
    void *ptr2 = allocate_memory(128, allocations, &allocated); // Allocate memory
    void *ptr3 = allocate_memory(256, allocations, &allocated); // Allocate memory
    void *ptr4 = allocate_memory(512, allocations, &allocated); // Allocate memory
    void *ptr5 = allocate_memory(1024, allocations, &allocated); // Allocate memory
    free_memory(ptr1, allocations, &allocated); // Free memory
    free_memory(ptr3, allocations, &allocated); // Free memory
    free_memory(ptr5, allocations, &allocated); // Free memory
    void *ptr6 = allocate_memory(128, allocations, &allocated); // Allocate memory
    void *ptr7 = allocate_memory(256, allocations, &allocated); // Allocate memory
    void *ptr8 = allocate_memory(512, allocations, &allocated); // Allocate memory
    free_memory(ptr6, allocations, &allocated); // Free memory
    free_memory(ptr2, allocations, &allocated); // Free memory
    free_memory(ptr7, allocations, &allocated); // Free memory
    free_memory(ptr4, allocations, &allocated); // Free memory
    free_memory(ptr8, allocations, &allocated); // Free memory
}