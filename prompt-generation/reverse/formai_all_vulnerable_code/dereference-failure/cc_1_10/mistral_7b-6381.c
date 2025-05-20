//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

// Function to check if a character is alphanumeric
int is_alnum(char c) {
    return (isalpha(c) || isdigit(c));
}

// Function to remove spaces and convert to lowercase
void process_input(char *str) {
    int i = 0, j = 0;

    while (str[i] != '\0') {
        if (is_alnum(str[i])) {
            str[j++] = tolower(str[i]);
        }
        i++;
    }

    str[j] = '\0';
}

// Function to compare two strings from both ends
int compare_strings(char *str1, char *str2, int len) {
    int start1 = 0, start2 = len - 1;

    while (start1 < len && start2 >= 0) {
        if (str1[start1] != str2[start2]) {
            return 0;
        }
        start1++;
        start2--;
    }

    return 1;
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int len = strlen(str);

    if (len <= 1) {
        return 1;
    }

    process_input(str);
    process_input(str + len - 1);

    return compare_strings(str, str + len - 1, len);
}

int main(int argc, char *argv[]) {
    char input[MAX_SIZE];

    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    strcpy(input, argv[1]);

    if (is_palindrome(input)) {
        printf("%s is a palindrome.\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }

    return 0;
}