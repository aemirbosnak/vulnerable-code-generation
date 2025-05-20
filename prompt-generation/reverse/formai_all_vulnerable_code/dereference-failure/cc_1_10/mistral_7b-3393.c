//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a palindrome
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

// Function to remove whitespaces from a string
char *remove_whitespaces(char *str) {
    char *result = malloc(strlen(str) + 1);
    int index = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i])) {
            result[index++] = str[i];
        }
    }

    result[index] = '\0';
    free(str);
    return result;
}

int main(void) {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    char *clean_str = remove_whitespaces(str);

    if (is_palindrome(clean_str, 0, strlen(clean_str) - 1)) {
        printf("%s is a palindrome.\n", clean_str);
    } else {
        printf("%s is not a palindrome.\n", clean_str);
    }

    free(clean_str);

    return EXIT_SUCCESS;
}