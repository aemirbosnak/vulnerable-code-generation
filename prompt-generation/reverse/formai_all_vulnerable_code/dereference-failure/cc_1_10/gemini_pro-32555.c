//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is a palindrome
int is_palindrome(char *str, int len) {
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

// Function to find the length of a string
int str_len(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Function to get a string from the user
char *get_string(void) {
    char *str = NULL;
    size_t len = 0;
    getline(&str, &len, stdin);
    return str;
}

// Function to print a message
void print_message(char *msg) {
    printf("%s", msg);
}

int main(void) {
    // Get a string from the user
    char *str = get_string();

    // Find the length of the string
    int len = str_len(str);

    // Check if the string is a palindrome
    int is_pal = is_palindrome(str, len);

    // Print the result
    if (is_pal) {
        print_message("The string is a palindrome\n");
    } else {
        print_message("The string is not a palindrome\n");
    }

    // Free the memory allocated for the string
    free(str);

    return 0;
}