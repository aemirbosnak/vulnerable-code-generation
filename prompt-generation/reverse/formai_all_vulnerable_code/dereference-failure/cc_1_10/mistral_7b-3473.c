//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to check if a given string is palindrome
int is_palindrome(char *str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

// Function to reverse a given string
void reverse_string(char *str, int start, int end) {
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Function to remove leading and trailing spaces from a given string
void trim_whitespace(char *str) {
    int start = 0;
    int end = strlen(str) - 1;

    while (str[start] == ' ') {
        start++;
    }

    while (str[end] == ' ') {
        end--;
    }

    for (int i = 0; i <= end - start; i++) {
        str[i] = str[start + i];
    }

    str[end - start + 1] = '\0';
}

// Function to check if a given character is alphanumeric
int is_alphanumeric(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
        return 1;
    }
    return 0;
}

// Function to check if a given string is palindrome recursively
int recursive_palindrome_checker(char *str, int start, int end) {
    if (start >= end) {
        return 1;
    }

    if (!is_alphanumeric(str[start])) {
        return 0;
    }

    if (!recursive_palindrome_checker(str, start + 1, end - 1)) {
        return 0;
    }

    return 1;
}

int main() {
    char str[MAX_SIZE];
    int length;

    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);

    trim_whitespace(str);

    length = strlen(str);

    if (length <= 1) {
        printf("The given string is empty or contains only whitespaces.\n");
        return 0;
    }

    if (recursive_palindrome_checker(str, 0, length - 1)) {
        printf("The given string is a palindrome.\n");
    } else {
        printf("The given string is not a palindrome.\n");
    }

    return 0;
}