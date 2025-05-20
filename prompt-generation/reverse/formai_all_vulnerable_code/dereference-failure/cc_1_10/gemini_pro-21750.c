//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char *reverseString(char *str) {
    int len = strlen(str);
    char *rev = malloc(len + 1);
    int i, j;
    for (i = len - 1, j = 0; i >= 0; i--, j++) {
        rev[j] = str[i];
    }
    rev[j] = '\0';
    return rev;
}

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
    int len = strlen(str);
    char *rev = reverseString(str);
    int result = strcmp(str, rev);
    free(rev);
    return result == 0;
}

// Function to count the number of words in a string
int countWords(char *str) {
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ' && str[i + 1] != ' ') {
            count++;
        }
        i++;
    }
    if (str[i - 1] != ' ') {
        count++;
    }
    return count;
}

// Function to count the number of characters in a string
int countCharacters(char *str) {
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        count++;
        i++;
    }
    return count;
}

// Function to convert a string to uppercase
char *toUppercase(char *str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
    return str;
}

// Function to convert a string to lowercase
char *toLowercase(char *str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
    return str;
}

// Function to remove all spaces from a string
char *removeSpaces(char *str) {
    int len = strlen(str);
    int i, j;
    char *newstr = malloc(len + 1);
    for (i = 0, j = 0; i < len; i++) {
        if (str[i] != ' ') {
            newstr[j++] = str[i];
        }
    }
    newstr[j] = '\0';
    return newstr;
}

// Function to remove all punctuation from a string
char *removePunctuation(char *str) {
    int len = strlen(str);
    int i, j;
    char *newstr = malloc(len + 1);
    for (i = 0, j = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            newstr[j++] = str[i];
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            newstr[j++] = str[i];
        } else if (str[i] >= '0' && str[i] <= '9') {
            newstr[j++] = str[i];
        } else if (str[i] == ' ') {
            newstr[j++] = str[i];
        }
    }
    newstr[j] = '\0';
    return newstr;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str);

    printf("Reversed string: %s\n", reverseString(str));
    printf("Is palindrome: %d\n", isPalindrome(str));
    printf("Number of words: %d\n", countWords(str));
    printf("Number of characters: %d\n", countCharacters(str));
    printf("Uppercase string: %s\n", toUppercase(str));
    printf("Lowercase string: %s\n", toLowercase(str));
    printf("String without spaces: %s\n", removeSpaces(str));
    printf("String without punctuation: %s\n", removePunctuation(str));

    return 0;
}