//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function to check if two strings are equal
int str_eq(const char *str1, const char *str2, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        if (str1[i] != str2[len - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

// Function to reverse a string recursively
void str_reverse(char *str, size_t len, size_t start, size_t end) {
    if (start >= end) {
        return;
    }
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    str_reverse(str, len, start + 1, end - 1);
}

// Function to check if a given string is a palindrome
int is_palindrome(const char *str, size_t len) {
    if (len <= 1) {
        return 1;
    }
    if (str[0] != str[len - 1]) {
        return 0;
    }
    str_reverse(str, len, 0, len - 1);
    return str_eq(str, str, len);
}

int main() {
    char str[MAX_LENGTH];
    size_t len;

    printf("Enter a string: ");
    scanf("%s", str);
    len = strlen(str);

    // Allocate memory for the reversed string
    char reversed[MAX_LENGTH];
    strcpy(reversed, str);
    str_reverse(reversed, len, 0, len - 1);

    if (is_palindrome(str, len)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}