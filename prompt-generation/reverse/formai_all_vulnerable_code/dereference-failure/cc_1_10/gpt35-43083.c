//FormAI DATASET v1.0 Category: String manipulation ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 100

void secure_string_copy(char *dest, const char *src, size_t n) {
    if (n < 1 || !dest || !src) {
        fprintf(stderr, "Invalid input parameters in 'secure_string_copy'\n");
        exit(EXIT_FAILURE);
    }

    size_t src_len = strlen(src);
    size_t num_of_copied_chars = n - 1 > src_len ? src_len : n - 1;

    // Copy the string
    for (size_t i = 0; i < num_of_copied_chars; i++) {
        dest[i] = src[i];
    }

    // Add null termination
    dest[num_of_copied_chars] = '\0';
}

int main() {
    // Allocate memory for strings
    char* original_string = (char*) malloc(MAX_STRING_LENGTH * sizeof(char));
    char* copied_string = (char*) malloc(MAX_STRING_LENGTH * sizeof(char));

    if (!original_string || !copied_string) {
        fprintf(stderr, "Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }

    // Read user input
    printf("Enter a string with max length %d: ", MAX_STRING_LENGTH - 1);
    fgets(original_string, MAX_STRING_LENGTH, stdin);

    // Copy the string in a secure manner
    secure_string_copy(copied_string, original_string, MAX_STRING_LENGTH);

    // Print the original string
    printf("\nOriginal string: %s", original_string);

    // Print the copied string
    printf("Copied string: %s", copied_string);

    // Free memory
    free(original_string);
    free(copied_string);

    return 0;
}