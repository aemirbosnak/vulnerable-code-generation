//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 10000

// Function to clean the input string
void clean_string(char* str) {
    int i, j;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if (!isalnum(str[i]) &&!isalnum(str[j])) {
            memmove(str + i, str + j, strlen(str + j) + 1);
            str[strlen(str) - 1] = '\0';
            j--;
        }
    }
}

// Function to check if a string is a palindrome
bool is_palindrome(char* str) {
    int i, j;
    clean_string(str);
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if (str[i]!= str[j]) {
            return false;
        }
    }
    return true;
}

// Function to read input from user
char* read_input() {
    char* input = malloc(MAX_LENGTH * sizeof(char));
    printf("Enter a string to check if it's a palindrome: ");
    fgets(input, MAX_LENGTH, stdin);
    return input;
}

int main() {
    char* input;
    bool is_palindrome_result;

    input = read_input();
    is_palindrome_result = is_palindrome(input);

    if (is_palindrome_result) {
        printf("The input string is a palindrome.\n");
    } else {
        printf("The input string is not a palindrome.\n");
    }

    free(input);
    return 0;
}