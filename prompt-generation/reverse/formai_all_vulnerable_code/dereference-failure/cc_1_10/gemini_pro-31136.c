//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a function to count the number of words in a string.
int count_words(char *string);

// Declare a function to reverse a string.
char *reverse_string(char *string);

// Declare a function to remove duplicate characters from a string.
char *remove_duplicate_characters(char *string);

// Declare a function to check if a string is a palindrome.
int is_palindrome(char *string);

// Define the main function.
int main() {
    // Get a string from the user.
    char string[100];
    printf("Enter a string: ");
    scanf("%s", string);

    // Count the number of words in the string.
    int word_count = count_words(string);
    printf("The string contains %d words.\n", word_count);

    // Reverse the string.
    char *reversed_string = reverse_string(string);
    printf("The reversed string is: %s\n", reversed_string);

    // Remove duplicate characters from the string.
    char *unique_string = remove_duplicate_characters(string);
    printf("The string with duplicate characters removed is: %s\n", unique_string);

    // Check if the string is a palindrome.
    int is_palindrome_result = is_palindrome(string);
    if (is_palindrome_result) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    // Free the memory allocated for the reversed and unique strings.
    free(reversed_string);
    free(unique_string);

    return 0;
}

// Define the function to count the number of words in a string.
int count_words(char *string) {
    int word_count = 0;
    int in_word = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == ' ' || string[i] == '\n' || string[i] == '\t') {
            in_word = 0;
        } else if (!in_word) {
            word_count++;
            in_word = 1;
        }
    }
    return word_count;
}

// Define the function to reverse a string.
char *reverse_string(char *string) {
    int length = strlen(string);
    char *reversed_string = malloc(length + 1);
    int j = 0;
    for (int i = length - 1; i >= 0; i--) {
        reversed_string[j++] = string[i];
    }
    reversed_string[j] = '\0';
    return reversed_string;
}

// Define the function to remove duplicate characters from a string.
char *remove_duplicate_characters(char *string) {
    int length = strlen(string);
    char *unique_string = malloc(length + 1);
    int index = 0;
    for (int i = 0; i < length; i++) {
        int j;
        for (j = 0; j < index; j++) {
            if (string[i] == unique_string[j]) {
                break;
            }
        }
        if (j == index) {
            unique_string[index++] = string[i];
        }
    }
    unique_string[index] = '\0';
    return unique_string;
}

// Define the function to check if a string is a palindrome.
int is_palindrome(char *string) {
    int length = strlen(string);
    for (int i = 0; i < length / 2; i++) {
        if (string[i] != string[length - i - 1]) {
            return 0;
        }
    }
    return 1;
}