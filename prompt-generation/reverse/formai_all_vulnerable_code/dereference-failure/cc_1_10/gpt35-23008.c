//FormAI DATASET v1.0 Category: Spam Detection System ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 1000

// This function checks if a given string contains spam words
bool contains_spam(char *input_string) {
    char *spam_words[] = {"free", "cash", "bonus", "offer", "subscribe"}; // List of known spam words
    int num_spam_words = sizeof(spam_words) / sizeof(char *); // Calculate the number of elements in the array

    for (int i = 0; i < num_spam_words; i++) {
        if (strstr(input_string, spam_words[i])) { // Check if the spam word is present in the input string
            return true;
        }
    }

    return false; // If no spam words are found, return false
}

// This function removes leading and trailing spaces from a string
char *trim_string(char *input_string) {
    int i = 0;
    int j = strlen(input_string) - 1;

    while (input_string[i] == ' ') { // Remove leading spaces
        i++;
    }

    while (input_string[j] == ' ') { // Remove trailing spaces
        j--;
    }

    input_string[j+1] = '\0'; // Terminate the string at the new end position

    return &input_string[i]; // Return a pointer to the first non-space character
}

int main() {
    char input_string[MAX_INPUT_LENGTH];

    printf("Enter the input string: ");
    fgets(input_string, MAX_INPUT_LENGTH, stdin); // Read input from user

    char *trimmed_string = trim_string(input_string); // Remove extra spaces from the input string

    if (contains_spam(trimmed_string)) { // Check if the input string contains spam
        printf("Spam detected! This message will not be sent.\n");
        return 1; // Exit with status code 1 to indicate spam was detected
    }

    printf("Message passed spam filter. This message will be sent.\n");
    return 0; // Exit with status code 0 to indicate no spam was detected
}