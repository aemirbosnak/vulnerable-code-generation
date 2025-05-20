//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define a custom data structure
typedef struct {
    int x;
    float y;
    char *name;
} my_struct;

// Define a macro to allocate memory
#define MALLOC(type, n) (type *)malloc(sizeof(type) * n)

// Define a function to create a new instance of my_struct
my_struct *my_struct_new(int x, float y, char *name) {
    // Allocate memory for the new instance
    my_struct *instance = MALLOC(my_struct, 1);

    // Initialize the fields
    instance->x = x;
    instance->y = y;
    instance->name = name;

    // Return the new instance
    return instance;
}

// Define a function to free the memory allocated for an instance of my_struct
void my_struct_free(my_struct *instance) {
    // Free the name field
    free(instance->name);

    // Free the instance itself
    free(instance);
}

// Define a function to print an instance of my_struct
void my_struct_print(my_struct *instance) {
    // Print the fields
    printf("x: %d\n", instance->x);
    printf("y: %.2f\n", instance->y);
    printf("name: %s\n", instance->name);
}

// Main function
int main() {
    // Create a new instance of my_struct
    my_struct *instance = my_struct_new(10, 3.14, "John Doe");

    // Print the instance
    my_struct_print(instance);

    // Free the memory allocated for the instance
    my_struct_free(instance);

    return 0;
}