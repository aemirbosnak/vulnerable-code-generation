//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char *reverseString(char *str) {
    int len = strlen(str);
    char *rev = malloc(len + 1);
    int i, j;
    for (i = 0, j = len - 1; i < len; i++, j--) {
        rev[i] = str[j];
    }
    rev[len] = '\0';
    return rev;
}

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to remove all occurrences of a character from a string
char *removeChar(char *str, char c) {
    int len = strlen(str);
    char *newStr = malloc(len + 1);
    int i, j;
    for (i = 0, j = 0; i < len; i++) {
        if (str[i] != c) {
            newStr[j++] = str[i];
        }
    }
    newStr[j] = '\0';
    return newStr;
}

// Function to count the number of words in a string
int countWords(char *str) {
    int len = strlen(str);
    int count = 0;
    int i;
    for (i = 0; i < len; i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            count++;
        }
    }
    return count + 1;
}

// Function to convert a string to uppercase
char *toUpper(char *str) {
    int len = strlen(str);
    char *newStr = malloc(len + 1);
    int i;
    for (i = 0; i < len; i++) {
        newStr[i] = toupper(str[i]);
    }
    newStr[len] = '\0';
    return newStr;
}

// Function to convert a string to lowercase
char *toLower(char *str) {
    int len = strlen(str);
    char *newStr = malloc(len + 1);
    int i;
    for (i = 0; i < len; i++) {
        newStr[i] = tolower(str[i]);
    }
    newStr[len] = '\0';
    return newStr;
}

// Function to test the text processing functions
int main() {
    char *str = "Hello World!";

    printf("Original string: %s\n", str);

    // Reverse the string
    char *revStr = reverseString(str);
    printf("Reversed string: %s\n", revStr);

    // Check if the string is a palindrome
    int isPal = isPalindrome(str);
    if (isPal) {
        printf("The string is a palindrome\n");
    } else {
        printf("The string is not a palindrome\n");
    }

    // Remove all occurrences of a character from the string
    char *newStr = removeChar(str, 'l');
    printf("String with 'l' removed: %s\n", newStr);

    // Count the number of words in the string
    int wordCount = countWords(str);
    printf("Word count: %d\n", wordCount);

    // Convert the string to uppercase
    char *upperStr = toUpper(str);
    printf("Uppercase string: %s\n", upperStr);

    // Convert the string to lowercase
    char *lowerStr = toLower(str);
    printf("Lowercase string: %s\n", lowerStr);

    free(revStr);
    free(newStr);
    free(upperStr);
    free(lowerStr);

    return 0;
}