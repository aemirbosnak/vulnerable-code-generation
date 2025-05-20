//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

// Function to remove whitespaces from string
void remove_whitespaces(char *str) {
    int i = 0, j = 0;

    while (str[i] != '\0') {
        if (!isspace(str[i])) {
            str[j++] = str[i];
        }
        i++;
    }

    str[j] = '\0';
}

// Function to check if the given string is a palindrome
int is_palindrome(char *str) {
    int start = 0, end = strlen(str) - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            return 0;
        }
        start++;
        end--;
    }

    return 1;
}

int main(int argc, char *argv[]) {
    char input_str[MAX_LENGTH];

    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    strcpy(input_str, argv[1]);

    remove_whitespaces(input_str);

    if (strlen(input_str) > MAX_LENGTH) {
        printf("Error: String too long.\n");
        return 1;
    }

    if (is_palindrome(input_str)) {
        printf("%s is a palindrome.\n", input_str);
    } else {
        printf("%s is not a palindrome.\n", input_str);
    }

    return 0;
}