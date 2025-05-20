//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to remove leading and trailing whitespaces
void trimWhitespace(char *str) {
    int start = 0;
    int end = strlen(str) - 1;

    while (isspace(str[start])) start++;
    while (isspace(str[end])) end--;

    for (int i = start; i <= end; i++) {
        str[i - start] = str[i];
    }

    str[end - start + 1] = '\0';
}

// Function to check if a string is palindrome
int isPalindrome(char *str) {
    int start = 0;
    int end = strlen(str) - 1;

    // Handling special cases
    if (strlen(str) <= 1) return 1;
    if (str[start] != str[end]) return 0;

    while (start < end) {
        // Handling case-sensitive comparison
        if (tolower(str[start]) != tolower(str[end])) return 0;

        start++;
        end--;
    }

    return 1;
}

// Function to print error message and exit with error code
void printErrorAndExit(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// Main function
int main(int argc, char **argv) {
    if (argc != 2) printErrorAndExit("Usage: palindromeChecker <string>");

    trimWhitespace(argv[1]);

    if (isPalindrome(argv[1])) {
        printf("%s is a palindrome\n", argv[1]);
    } else {
        printf("%s is not a palindrome\n", argv[1]);
    }

    return 0;
}