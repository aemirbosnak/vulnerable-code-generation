//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function prototypes
bool isPalindrome(char str[], int start, int end);
void toLowerCase(char str[]);
void trimWhitespace(char str[]);

int main() {
    // Buffer to hold user input
    char input[256];

    // Collecting input from user
    printf("Enter a string to check if it is a palindrome:\n");
    fgets(input, sizeof(input), stdin);

    // Trim whitespace and convert to lowercase
    trimWhitespace(input);
    toLowerCase(input);

    // Calculate the length of the input
    int len = strlen(input);
    
    if (isPalindrome(input, 0, len - 1)) {
        printf("The string \"%s\" is a palindrome.\n", input);
    } else {
        printf("The string \"%s\" is not a palindrome.\n", input);
    }

    return 0;
}

// Function to check if a substring is a palindrome
bool isPalindrome(char str[], int start, int end) {
    // Base case: if the start index is greater than or equal to the end index, it's a palindrome
    if (start >= end) {
        return true;
    }
    
    // Check if characters at start and end index are the same
    if (str[start] != str[end]) {
        return false;
    }

    // Move towards the middle of the string
    return isPalindrome(str, start + 1, end - 1);
}

// Function to convert a string to lowercase
void toLowerCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to trim whitespace from the input string
void trimWhitespace(char str[]) {
    char *end;

    // Trim leading space
    while (isspace(*str)) str++;
    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) end--;
    *(end + 1) = '\0';  // Null terminate the trimmed string
}