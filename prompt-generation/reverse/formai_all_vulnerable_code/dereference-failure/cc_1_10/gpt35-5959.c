//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: mathematical
#include <stdio.h>
#include <string.h>

// Function to check if a character is alphanumeric
int isAlphaNumeric(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
        return 1;
    }
    return 0;
}

// Function to convert a string to lowercase
void toLowerCase(char* str) {
    int i;
    for (i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int i, j;
    int len = strlen(str);
    // Create a new string with only alphanumeric characters
    char newStr[len];
    int k = 0;
    for (i = 0; i < len; i++) {
        if (isAlphaNumeric(str[i])) {
            newStr[k] = str[i];
            k++;
        }
    }
    newStr[k] = '\0';
    len = strlen(newStr);
    // Convert the new string to lowercase
    toLowerCase(newStr);
    // Check if the new string is a palindrome
    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (newStr[i] != newStr[j]) {
            return 0;
        }
    }
    return 1;
}

// Main function
int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    // Remove the newline character from fgets
    str[strcspn(str, "\n")] = '\0';
    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    return 0;
}