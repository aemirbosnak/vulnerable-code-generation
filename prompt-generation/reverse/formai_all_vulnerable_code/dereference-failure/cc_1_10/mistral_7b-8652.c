//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is palindrome
int is_palindrome(char *str, int start, int end) {
    while (start < end) {
        // If the characters don't match, return false
        if (tolower(str[start]) != tolower(str[end])) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

// Function to remove leading and trailing whitespaces
void remove_whitespaces(char *str) {
    int start = 0;
    int end = strlen(str) - 1;

    // Remove leading whitespaces
    while (isspace(str[start])) {
        str[start] = '\0';
        memmove(str, str + 1, end - start + 1);
        start--;
    }

    // Remove trailing whitespaces
    while (isspace(str[end])) {
        str[end] = '\0';
        memmove(&str[end], &str[end - 1], strlen(str + end) + 1);
        end--;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    remove_whitespaces(argv[1]);

    if (strlen(argv[1]) % 2 == 0) {
        int mid = strlen(argv[1]) / 2;
        if (is_palindrome(argv[1], 0, mid - 1) && is_palindrome(argv[1], mid, strlen(argv[1]))) {
            printf("%s is a palindrome.\n", argv[1]);
        } else {
            printf("%s is not a palindrome.\n", argv[1]);
        }
    } else {
        int mid = strlen(argv[1]) / 2;
        if (is_palindrome(argv[1], 0, mid) && is_palindrome(argv[1], mid + 1, strlen(argv[1]))) {
            printf("%s is a palindrome.\n", argv[1]);
        } else {
            printf("%s is not a palindrome.\n", argv[1]);
        }
    }

    return 0;
}