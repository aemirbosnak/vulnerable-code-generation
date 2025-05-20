//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LINE_LEN 1024
#define MAX_WORD_LEN 32

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to reverse a string
char *reverse_string(char *str) {
    size_t len = strlen(str);
    char *reversed = malloc(len * sizeof(char));
    for (size_t i = 0; i < len; i++) {
        reversed[i] = str[len - i - 1];
    }
    return reversed;
}

int main() {
    char line[MAX_LINE_LEN];
    char word[MAX_WORD_LEN];
    size_t len = 0;

    // Read input from standard input
    while (fgets(line, MAX_LINE_LEN, stdin) != NULL) {
        // Tokenize the line into words
        char *token = strtok(line, " ");
        while (token != NULL) {
            // Check if the word is a palindrome
            if (is_palindrome(token)) {
                // Reverse the word and print it
                char *reversed = reverse_string(token);
                printf("%s\n", reversed);
            }
            // Get the next token
            token = strtok(NULL, " ");
        }
        // Print a newline character
        printf("\n");
    }
    return 0;
}