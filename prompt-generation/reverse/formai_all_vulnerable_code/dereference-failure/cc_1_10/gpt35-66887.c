//FormAI DATASET v1.0 Category: Memory management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define the size of memory for our example
#define MEMORY_SIZE 100

int main(void) {

    // Allocate memory using malloc()
    void *ptr = malloc(MEMORY_SIZE);
    
    // Set memory to zero
    memset(ptr, 0, MEMORY_SIZE);
    
    // Write values to memory using pointers
    int *int_ptr = (int*) ptr;
    float *float_ptr = (float*) (int_ptr + 10);
    double *double_ptr = (double*) (float_ptr + 10);
    
    *int_ptr = 42;
    *float_ptr = 3.14;
    *double_ptr = 2.718;
    
    // Read values from memory using pointers
    printf("The integer value stored in memory is: %d\n", *int_ptr);
    printf("The float value stored in memory is: %f\n", *float_ptr);
    printf("The double value stored in memory is: %f\n", *double_ptr);
    
    // Reallocate memory using realloc()
    ptr = realloc(ptr, MEMORY_SIZE * 2);
    
    // Check if reallocation was successful
    if (ptr == NULL) {
        printf("Error: Could not reallocate memory.\n");
        return 1;
    }
    
    // Write new values to memory using pointers
    int_ptr = (int*) ptr;
    float_ptr = (float*) (int_ptr + 20);
    double_ptr = (double*) (float_ptr + 10);
    
    *int_ptr = 2;
    *float_ptr = 4.20;
    *double_ptr = 3.14159;
    
    // Read new values from memory using pointers
    printf("The new integer value stored in memory is: %d\n", *int_ptr);
    printf("The new float value stored in memory is: %f\n", *float_ptr);
    printf("The new double value stored in memory is: %f\n", *double_ptr);
    
    // Free memory using free()
    free(ptr);
    
    return 0;
}