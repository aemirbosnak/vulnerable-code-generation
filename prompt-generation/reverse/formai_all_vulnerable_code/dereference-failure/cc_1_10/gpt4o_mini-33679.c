//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to safely read a string from stdin, paranoid programming is a must
void safe_read_string(char *buffer, size_t size) {
    if (fgets(buffer, size, stdin) == NULL) {
        fprintf(stderr, "Error reading input! Please try again.\n");
        exit(EXIT_FAILURE);
    }
    
    // Remove newline character if present
    size_t length = strlen(buffer);
    if (length > 0 && buffer[length - 1] == '\n') {
        buffer[length - 1] = '\0';
    }
}

// Function to concatenate two strings with paranoia in memory management
char *safe_strcat(const char *str1, const char *str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    
    char *result = malloc(len1 + len2 + 1); // +1 for null terminator
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed! Exiting.\n");
        exit(EXIT_FAILURE);
    }
    
    strcpy(result, str1);
    strcat(result, str2);
    
    return result;
}

// Function to transform a string paranoidly, making it uppercase
void to_uppercase(char *str) {
    for (size_t i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;  // or str[i] = str[i] - 'a' + 'A';
        }
    }
}

// Function to reverse a string
void reverse_string(char *str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to check if a string is a palindrome
int is_palindrome(const char *str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}

int main() {
    const size_t BUFFER_SIZE = 256;
    char input_string[BUFFER_SIZE];
    
    printf("Welcome to the paranoid string manipulation program!\n");
    printf("Please enter a string (max length is %zu characters):\n", BUFFER_SIZE - 1);
    
    safe_read_string(input_string, BUFFER_SIZE);
    
    // Show the original string
    printf("Original String: %s\n", input_string);
    
    // Transform the string to uppercase
    char *upper_string = strdup(input_string); // Using strdup for safe copying of string
    if (upper_string == NULL) {
        fprintf(stderr, "Memory allocation failed! Exiting.\n");
        return EXIT_FAILURE;
    }
    to_uppercase(upper_string);
    printf("Uppercase String: %s\n", upper_string);
    
    // Reverse the string
    char *reversed_string = strdup(input_string);
    if (reversed_string == NULL) {
        free(upper_string); // Remember to free memory
        fprintf(stderr, "Memory allocation failed! Exiting.\n");
        return EXIT_FAILURE;
    }
    reverse_string(reversed_string);
    printf("Reversed String: %s\n", reversed_string);
    
    // Check if the original string is a palindrome
    if (is_palindrome(input_string)) {
        printf("The original string is a palindrome.\n");
    } else {
        printf("The original string is not a palindrome.\n");
    }
    
    // Concatenate the original string with its uppercase version
    char *concatenated_string = safe_strcat(input_string, upper_string);
    printf("Concatenated String: %s\n", concatenated_string);
    
    // Cleanup: Free allocated memory
    free(upper_string);
    free(reversed_string);
    free(concatenated_string);
    
    printf("Program completed successfully without errors!\n");
    return EXIT_SUCCESS;
}