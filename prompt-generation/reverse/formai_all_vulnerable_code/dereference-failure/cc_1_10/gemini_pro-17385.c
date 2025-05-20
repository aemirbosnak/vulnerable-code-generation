//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1024

char *remove_non_alphanumeric_characters(char *string);
int check_if_palindrome(char *string);

int main() {
    char string[MAX_LENGTH];

    printf("Enter a string to check if it is a palindrome: ");
    fgets(string, MAX_LENGTH, stdin);

    char *cleaned_string = remove_non_alphanumeric_characters(string);
    int is_palindrome = check_if_palindrome(cleaned_string);

    if (is_palindrome) {
        printf("%s is a palindrome\n", string);
    } else {
        printf("%s is not a palindrome\n", string);
    }

    free(cleaned_string);
    return 0;
}

char *remove_non_alphanumeric_characters(char *string) {
    char *cleaned_string = malloc(strlen(string) + 1);
    int index = 0;

    for (int i = 0; string[i] != '\0'; i++) {
        if (isalnum(string[i])) {
            cleaned_string[index++] = tolower(string[i]);
        }
    }

    cleaned_string[index] = '\0';
    return cleaned_string;
}

int check_if_palindrome(char *string) {
    int length = strlen(string);

    for (int i = 0; i < length / 2; i++) {
        if (string[i] != string[length - i - 1]) {
            return 0;
        }
    }

    return 1;
}