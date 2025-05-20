//Falcon-180B DATASET v1.0 Category: Memory management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to allocate memory dynamically
void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return ptr;
}

// Function to free memory dynamically
void my_free(void *ptr) {
    free(ptr);
}

// Function to copy a string
char *my_strcpy(char *dest, const char *src) {
    size_t len = strlen(src);
    char *new_dest = my_malloc(len + 1);
    strcpy(new_dest, src);
    my_free(dest);
    return new_dest;
}

// Function to concatenate two strings
char *my_strcat(char *dest, const char *src) {
    size_t len1 = strlen(dest);
    size_t len2 = strlen(src);
    char *new_dest = my_malloc(len1 + len2 + 1);
    strcpy(new_dest, dest);
    strcat(new_dest, src);
    my_free(dest);
    return new_dest;
}

int main() {
    // Test my_malloc
    void *ptr1 = my_malloc(10);
    printf("Allocated memory: %p\n", ptr1);

    // Test my_free
    my_free(ptr1);

    // Test my_strcpy
    char *str1 = "Hello";
    char *str2 = my_strcpy(str1, "World");
    printf("Copied string: %s\n", str2);

    // Test my_strcat
    char *str3 = "Hello";
    char *str4 = my_strcat(str3, "World");
    printf("Concatenated string: %s\n", str4);

    return 0;
}