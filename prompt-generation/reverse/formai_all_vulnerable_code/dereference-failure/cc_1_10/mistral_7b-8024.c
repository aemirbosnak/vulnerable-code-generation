//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: calm
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is alphanumeric
int is_alnum(char c) {
    return (isalnum(c) || isspace(c) || ispunct(c) || c == '_');
}

// Function to check if a string is a palindrome
int is_palindrome(const char *str) {
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        if (!is_alnum(str[start])) start++;
        else if (!is_alnum(str[end])) end--;
        else if (tolower(str[start]) != tolower(str[end])) return 0;

        start++;
        end--;
    }

    return 1;
}

// Function to remove leading and trailing whitespaces
void trim_whitespace(char *str) {
    int start = 0;
    int end = strlen(str) - 1;

    while (isspace(str[start])) start++;
    while (isspace(str[end])) end--;

    memmove(str, str + start, end - start + 1);
    str[end - start + 1] = '\0';
}

int main() {
    char input[1024];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    trim_whitespace(input);

    if (is_palindrome(input))
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");

    return 0;
}