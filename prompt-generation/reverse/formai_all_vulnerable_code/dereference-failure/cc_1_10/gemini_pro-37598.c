//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to safely concatenate two strings
char *safe_strcat(char *dest, size_t dest_size, const char *src) {
    size_t src_len = strlen(src);
    if (dest_size < src_len + 1) {
        return NULL;  // Destination buffer is too small
    }
    memcpy(dest + strlen(dest), src, src_len + 1);
    return dest;
}

// Function to safely copy a string
char *safe_strcpy(char *dest, size_t dest_size, const char *src) {
    size_t src_len = strlen(src);
    if (dest_size < src_len + 1) {
        return NULL;  // Destination buffer is too small
    }
    memcpy(dest, src, src_len + 1);
    return dest;
}

// Function to safely compare two strings
int safe_strcmp(const char *str1, const char *str2) {
    if (str1 == NULL || str2 == NULL) {
        return -1;  // Invalid arguments
    }
    return strcmp(str1, str2);
}

int main() {
    // Example usage of the safe string manipulation functions

    char name[100];
    if (safe_strcpy(name, sizeof(name), "John Doe") == NULL) {
        printf("Error: Destination buffer too small for 'John Doe'\n");
        return EXIT_FAILURE;
    }
    printf("Name: %s\n", name);

    char greeting[100];
    if (safe_strcat(greeting, sizeof(greeting), "Hello, ") == NULL) {
        printf("Error: Destination buffer too small for 'Hello, '\n");
        return EXIT_FAILURE;
    }
    if (safe_strcat(greeting, sizeof(greeting), name) == NULL) {
        printf("Error: Destination buffer too small for '%s'\n", name);
        return EXIT_FAILURE;
    }
    printf("Greeting: %s\n", greeting);

    int comparison_result = safe_strcmp("John Doe", "Jane Doe");
    if (comparison_result == 0) {
        printf("Strings are equal\n");
    } else if (comparison_result < 0) {
        printf("First string is less than second string\n");
    } else {
        printf("First string is greater than second string\n");
    }

    return EXIT_SUCCESS;
}