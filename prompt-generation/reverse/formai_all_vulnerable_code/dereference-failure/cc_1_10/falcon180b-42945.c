//Falcon-180B DATASET v1.0 Category: Memory management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to allocate memory dynamically
void* safeMalloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    return ptr;
}

// Function to copy a string
char* strcpy(char* dest, const char* src) {
    size_t len = strlen(src);
    char* result = safeMalloc(len + 1);
    strcpy(result, src);
    return result;
}

// Function to concatenate two strings
char* strcat(char* dest, const char* src) {
    size_t destLen = strlen(dest);
    size_t srcLen = strlen(src);
    char* result = safeMalloc(destLen + srcLen + 1);
    strcpy(result, dest);
    strcat(result, src);
    return result;
}

int main() {
    // Example usage of safeMalloc
    int* arr = safeMalloc(10 * sizeof(int));
    memset(arr, 0, 10 * sizeof(int));

    // Example usage of strcpy
    char* str1 = strcpy("Hello", "World");
    printf("str1 = %s\n", str1);

    // Example usage of strcat
    char* str2 = strcat("Hello, ", "World");
    printf("str2 = %s\n", str2);

    // Free dynamically allocated memory
    free(arr);
    free(str1);
    free(str2);

    return 0;
}