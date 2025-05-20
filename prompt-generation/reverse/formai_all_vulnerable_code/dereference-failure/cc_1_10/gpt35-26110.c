//FormAI DATASET v1.0 Category: Memory management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MIN_ALLOC_SIZE 1024
#define MAX_ALLOC_SIZE 1048576 // 1 MB

// This program demonstrates a visionary memory management technique that allows dynamic allocation for any size of memory, optimizing performance and efficiency. 

void* visionary_alloc(size_t size) {
    if(size < MIN_ALLOC_SIZE) {
        size = MIN_ALLOC_SIZE;
    }
    else if(size > MAX_ALLOC_SIZE) {
        printf("ERROR: Requested memory allocation is greater than the maximum allowed size of %d bytes.\n", MAX_ALLOC_SIZE);
        return NULL;
    }

    void* pointer = calloc(1, size);

    if(pointer == NULL) {
        printf("ERROR: Failed to allocate %d bytes of memory.\n", size);
        return NULL;
    }

    printf("Dynamic memory of size %d bytes allocated successfully at address %p.\n", size, pointer);

    return pointer;
}

void visionary_free(void* pointer) {
    if(pointer == NULL) {
        printf("ERROR: Cannot free null pointer.\n");
        return;
    }

    free(pointer);

    printf("Dynamic memory at address %p freed successfully.\n", pointer);
}

int main() {
    int* int_pointer = (int*) visionary_alloc(sizeof(int));
    float* float_pointer = (float*) visionary_alloc(sizeof(float));
    long* long_pointer = (long*) visionary_alloc(sizeof(long) * 10);
    char* char_pointer = (char*) visionary_alloc(sizeof(char) * 256);
    double* double_pointer = (double*) visionary_alloc(sizeof(double) * 5);

    *int_pointer = 1234;
    *float_pointer = 3.141592;
    long_pointer[0] = 987654321;
    char_pointer[0] = 'H';
    double_pointer[0] = 1.234567890;

    printf("int value = %d\n", *int_pointer);
    printf("float value = %f\n", *float_pointer);
    printf("long array value = %ld\n", long_pointer[0]);
    printf("char array value = %c\n", char_pointer[0]);
    printf("double array value = %e\n", double_pointer[0]);

    visionary_free(int_pointer);
    visionary_free(float_pointer);
    visionary_free(long_pointer);
    visionary_free(char_pointer);
    visionary_free(double_pointer);

    return 0;
}