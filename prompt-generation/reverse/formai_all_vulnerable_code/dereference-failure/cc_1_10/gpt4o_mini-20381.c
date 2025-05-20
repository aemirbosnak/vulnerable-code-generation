//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void strip_non_alphanum(char *src, char *dest) {
    while (*src) {
        if (isalnum((unsigned char)*src)) {
            *dest++ = tolower((unsigned char)*src);
        }
        src++;
    }
    *dest = '\0'; // Terminate the destination string
}

int is_palindrome(const char *str) {
    int len = strlen(str);
    int left = 0, right = len - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }
    return 1; // It is a palindrome
}

char* get_input() {
    char *buffer = NULL;
    size_t size = 0;

    printf("Enter a string to check for palindrome: ");
    if (getline(&buffer, &size, stdin) == -1) {
        perror("Error reading input");
        exit(EXIT_FAILURE);
    }

    // Remove the newline character, if present
    buffer[strcspn(buffer, "\n")] = 0;
    
    return buffer;
}

int main() {
    char *input = get_input();

    // Allocate memory for the stripped string
    char *stripped_input = (char *)malloc(strlen(input) + 1);
    if (!stripped_input) {
        perror("Failed to allocate memory");
        free(input);
        exit(EXIT_FAILURE);
    }

    // Strip non-alphanumeric characters and convert to lowercase
    strip_non_alphanum(input, stripped_input);

    // Check if the stripped string is a palindrome
    if (is_palindrome(stripped_input)) {
        printf("The input is a palindrome.\n");
    } else {
        printf("The input is not a palindrome.\n");
    }

    // Free allocated memory
    free(input);
    free(stripped_input);

    return 0;
}