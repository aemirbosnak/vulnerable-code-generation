//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1024

// Function to reverse a string
void reverse(char *str, int len) {
    char temp;
    int start = 0;
    int end = len - 1;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Function to check if a string is a palindrome
int is_palindrome(char *str, int len) {
    char *reversed_str = malloc(len + 1);
    strcpy(reversed_str, str);
    reverse(reversed_str, len);
    int result = strcmp(str, reversed_str);
    free(reversed_str);
    return result == 0;
}

// Function to get the length of a string
int get_length(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Function to get a string from the user
char *get_string() {
    char *str = malloc(MAX_LEN);
    printf("Enter a string: ");
    fgets(str, MAX_LEN, stdin);
    return str;
}

// Main function
int main() {
    char *str = get_string();
    int len = get_length(str);
    if (is_palindrome(str, len)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    return 0;
}