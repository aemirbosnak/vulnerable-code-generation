//Falcon-180B DATASET v1.0 Category: Educational ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

// Function to check if a given string is a palindrome
int is_palindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i])!= tolower(str[len - i - 1])) {
            return 0;
        }
    }
    return 1;
}

// Function to remove non-alphanumeric characters from a string
void remove_non_alphanumeric(char* str) {
    int len = strlen(str);
    char* new_str = malloc(len + 1);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isalnum(str[i])) {
            new_str[j++] = tolower(str[i]);
        }
    }
    new_str[j] = '\0';
    strcpy(str, new_str);
    free(new_str);
}

// Function to reverse a string
void reverse_string(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to check if a given string is a pangram
int is_pangram(char* str) {
    int len = strlen(str);
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            count++;
        }
    }
    return count == 26;
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove non-alphanumeric characters
    remove_non_alphanumeric(input);

    // Reverse the string
    reverse_string(input);

    // Check if it's a palindrome
    if (is_palindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    // Check if it's a pangram
    if (is_pangram(input)) {
        printf("The string is a pangram.\n");
    } else {
        printf("The string is not a pangram.\n");
    }

    return 0;
}