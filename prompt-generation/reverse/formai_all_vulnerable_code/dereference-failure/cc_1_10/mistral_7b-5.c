//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1024

// Function to check if a string is palindrome
int is_palindrome(const char *str, size_t len) {
    size_t start = 0;
    size_t end = len - 1;

    while (start < end) {
        if (tolower(str[start]) != tolower(str[end])) {
            return 0;
        }
        start++;
        end--;
    }

    return 1;
}

// Function to remove leading and trailing whitespaces from a string
size_t remove_whitespaces(char *str, size_t len) {
    size_t start = 0;
    size_t index = 0;

    while (start < len && isspace((unsigned char)str[start])) {
        start++;
    }

    if (start >= len) {
        return 0;
    }

    while (index < len && (start < len || !isspace((unsigned char)str[index]))) {
        if (start < len && str[start] != str[index]) {
            str[index] = str[start];
            start++;
        }
        index++;
    }

    str[index] = '\0';

    return index;
}

// Function to read a line from standard input and check if it is a palindrome
int main() {
    char line[MAX_LEN];
    size_t len;

    while (1) {
        printf("Enter a string or type 'quit' to exit: ");
        fgets(line, MAX_LEN, stdin);

        len = remove_whitespaces(line, strlen(line));

        if (strcmp(line, "quit") == 0) {
            break;
        }

        if (len % 2 == 0 && is_palindrome(line, len)) {
            printf("Palindrome\n");
        } else {
            printf("Not a palindrome\n");
        }
    }

    return 0;
}