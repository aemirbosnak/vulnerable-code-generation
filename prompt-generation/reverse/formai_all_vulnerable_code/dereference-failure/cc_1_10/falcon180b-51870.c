//Falcon-180B DATASET v1.0 Category: Memory management ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to allocate memory
void* safe_malloc(size_t num_bytes) {
    void* ptr = malloc(num_bytes);

    if (ptr == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }

    return ptr;
}

// Function to copy a string
char* safe_strcpy(char* dest, const char* src) {
    size_t len = strlen(src);
    char* result = safe_malloc(len + 1);

    strcpy(result, src);
    return result;
}

// Function to concatenate two strings
char* safe_strcat(char* dest, const char* src) {
    size_t dest_len = strlen(dest);
    size_t src_len = strlen(src);
    char* result = safe_malloc(dest_len + src_len + 1);

    strcpy(result, dest);
    strcat(result, src);
    return result;
}

int main() {
    char* str1 = safe_strcpy("Hello", "Hello");
    printf("str1: %s\n", str1);

    char* str2 = safe_strcpy("World", "World");
    printf("str2: %s\n", str2);

    char* str3 = safe_strcat(str1, " ");
    printf("str3: %s\n", str3);

    char* str4 = safe_strcat(str3, str2);
    printf("str4: %s\n", str4);

    free(str1);
    free(str2);
    free(str3);
    free(str4);

    return 0;
}