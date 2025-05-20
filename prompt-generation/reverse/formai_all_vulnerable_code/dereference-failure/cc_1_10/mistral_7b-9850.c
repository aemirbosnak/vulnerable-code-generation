//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is palindrome
int is_palindrome(char *str, int start, int end) {
    while (start < end) {
        if (tolower(str[start]) != tolower(str[end])) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

// Function to remove spaces from a string
char *remove_spaces(char *str) {
    char *result = malloc(strlen(str) + 1);
    int i = 0, j = 0;

    for (; str[i] != '\0'; i++) {
        if (isspace(str[i]) == 0) {
            result[j++] = str[i];
        }
    }

    result[j] = '\0';
    free(str);
    return result;
}

int main() {
    char input[1024];
    char *input_processed;

    printf("Welcome to the Palindrome Checker!\n");
    printf("Enter a string (max length 1023 characters): ");
    fgets(input, sizeof(input), stdin);

    input_processed = remove_spaces(input);

    if (is_palindrome(input_processed, 0, strlen(input_processed) - 1)) {
        printf("%s is a palindrome!\n", input_processed);
    } else {
        printf("%s is not a palindrome.\n", input_processed);
    }

    free(input_processed);

    return 0;
}

// Here ends our Enthusiastic Palindrome Checker in C!