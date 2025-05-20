//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get a string input from user
char* get_input(const char* prompt) {
    char* input = NULL;
    size_t len = 0;

    printf("%s", prompt);
    getline(&input, &len, stdin);

    // Remove newline character if exists
    size_t input_length = strlen(input);
    if (input_length > 0 && input[input_length - 1] == '\n') {
        input[input_length - 1] = '\0';
    }

    return input;
}

// Function to concatenate two strings
char* concatenate_strings(const char* str1, const char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char* result = malloc(len1 + len2 + 1); // +1 for null-terminator

    if (result) {
        strcpy(result, str1);
        strcat(result, str2);
    }
    
    return result;
}

// Function to count vowels in a string
int count_vowels(const char* str) {
    int count = 0;
    for (size_t i = 0; i < strlen(str); i++) {
        char ch = tolower(str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    return count;
}

// Function to reverse a string
char* reverse_string(const char* str) {
    size_t len = strlen(str);
    char* reversed = malloc(len + 1); // +1 for null-terminator
    
    if (reversed) {
        for (size_t i = 0; i < len; i++) {
            reversed[i] = str[len - 1 - i];
        }
        reversed[len] = '\0';
    }

    return reversed;
}

// Function to convert a string to uppercase
char* to_uppercase(const char* str) {
    size_t len = strlen(str);
    char* upper = malloc(len + 1); // +1 for null-terminator
    
    if (upper) {
        for (size_t i = 0; i < len; i++) {
            upper[i] = toupper(str[i]);
        }
        upper[len] = '\0';
    }

    return upper;
}

// Function to free allocated memory
void free_memory(char* ptr) {
    free(ptr);
}

int main() {
    // Get first string input from the user
    char* str1 = get_input("Enter the first string: ");
    
    // Get second string input from the user
    char* str2 = get_input("Enter the second string: ");

    // Concatenate the strings
    char* concatenated = concatenate_strings(str1, str2);
    printf("Concatenated String: %s\n", concatenated);

    // Count vowels in the concatenated string
    int vowel_count = count_vowels(concatenated);
    printf("Number of vowels in the concatenated string: %d\n", vowel_count);

    // Reverse the concatenated string
    char* reversed = reverse_string(concatenated);
    printf("Reversed String: %s\n", reversed);

    // Convert the concatenated string to uppercase
    char* uppercased = to_uppercase(concatenated);
    printf("Uppercase String: %s\n", uppercased);

    // Free allocated memory
    free_memory(str1);
    free_memory(str2);
    free_memory(concatenated);
    free_memory(reversed);
    free_memory(uppercased);

    return 0;
}