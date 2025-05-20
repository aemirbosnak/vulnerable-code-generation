//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: portable
#include <stdlib.h>
#include <stdio.h>

// Define a custom memory allocator
void *my_malloc(size_t size) {
    void *ptr;
    // Allocate memory using malloc()
    ptr = malloc(size);
    // Check if the allocation succeeded
    if (ptr == NULL) {
        // Allocation failed, handle error
        perror("malloc failed");
        return NULL;
    }
    // Return the allocated memory
    return ptr;
}

// Define a custom memory deallocator
void my_free(void *ptr) {
    // Check if the pointer is valid
    if (ptr == NULL) {
        // Pointer is invalid, handle error
        fprintf(stderr, "invalid pointer passed to my_free\n");
        return;
    }
    // Deallocate the memory using free()
    free(ptr);
}

// Define a custom memory reallocator
void *my_realloc(void *ptr, size_t size) {
    void *new_ptr;
    // Check if the pointer is valid
    if (ptr == NULL) {
        // Pointer is invalid, handle error
        fprintf(stderr, "invalid pointer passed to my_realloc\n");
        return NULL;
    }
    // Reallocate memory using realloc()
    new_ptr = realloc(ptr, size);
    // Check if the reallocation succeeded
    if (new_ptr == NULL) {
        // Reallocation failed, handle error
        perror("realloc failed");
        return NULL;
    }
    // Return the reallocated memory
    return new_ptr;
}

// Define a data structure
typedef struct {
    int num1;
    int num2;
} MyStruct;

// Main function
int main() {
    // Allocate memory for a MyStruct using my_malloc()
    MyStruct *my_struct = my_malloc(sizeof(MyStruct));
    // Set the values of the MyStruct
    my_struct->num1 = 10;
    my_struct->num2 = 20;
    // Print the values of the MyStruct
    printf("MyStruct values: %d, %d\n", my_struct->num1, my_struct->num2);
    // Reallocate memory for the MyStruct using my_realloc()
    my_struct = my_realloc(my_struct, sizeof(MyStruct) * 2);
    // Set the values of the MyStruct
    my_struct[0].num1 = 30;
    my_struct[0].num2 = 40;
    my_struct[1].num1 = 50;
    my_struct[1].num2 = 60;
    // Print the values of the MyStruct
    printf("MyStruct values: \n");
    for (int i = 0; i < 2; i++) {
        printf("%d, %d\n", my_struct[i].num1, my_struct[i].num2);
    }
    // Deallocate memory for the MyStruct using my_free()
    my_free(my_struct);
    return 0;
}