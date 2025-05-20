//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove all occurrences of a given character from a string.
char *remove_character(char *str, char c) {
    char *new_str = malloc(strlen(str) + 1);
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (str[i] != c) {
            new_str[j++] = str[i];
        }
    }
    new_str[j] = '\0';
    return new_str;
}

// Function to reverse a string.
char *reverse_string(char *str) {
    int len = strlen(str);
    char *new_str = malloc(len + 1);
    int i, j;
    for (i = len - 1, j = 0; i >= 0; i--, j++) {
        new_str[j] = str[i];
    }
    new_str[j] = '\0';
    return new_str;
}

// Function to encode a string using the Atbash cipher.
char *atbash_encode(char *str) {
    char *new_str = malloc(strlen(str) + 1);
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            new_str[i] = 'z' - (str[i] - 'a');
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            new_str[i] = 'Z' - (str[i] - 'A');
        } else {
            new_str[i] = str[i];
        }
    }
    new_str[i] = '\0';
    return new_str;
}

int main() {
    // Read the input string from the user.
    char *input_str = malloc(100);
    printf("Enter the string you want to translate: ");
    scanf("%s", input_str);

    // Remove all spaces from the input string.
    char *no_spaces_str = remove_character(input_str, ' ');

    // Reverse the string.
    char *reversed_str = reverse_string(no_spaces_str);

    // Encode the string using the Atbash cipher.
    char *encoded_str = atbash_encode(reversed_str);

    // Print the encoded string to the user.
    printf("The encoded string is: %s\n", encoded_str);

    return 0;
}