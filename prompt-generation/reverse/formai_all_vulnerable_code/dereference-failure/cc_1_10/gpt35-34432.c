//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100

char* removeSpecialChars(char* str);

int main()
{
    char str[MAX_STRING_LENGTH];

    printf("Enter a string: ");
    fgets(str, MAX_STRING_LENGTH, stdin);

    char* cleanedString = removeSpecialChars(str);

    int left = 0;
    int right = strlen(cleanedString) - 1;
    int isPalindrome = 1;

    while (right > left) {
        if (cleanedString[left++] != cleanedString[right--]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome) {
        printf("%s is a palindrome!\n", str);
    } else {
        printf("%s is not a palindrome :(\n", str);
    }

    free(cleanedString);

    return 0;
}

char* removeSpecialChars(char* str)
{
    char* cleanedString = malloc(MAX_STRING_LENGTH * sizeof(char));
    int j = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (isalnum(str[i])) {
            cleanedString[j++] = tolower(str[i]);
        }
    }

    cleanedString[j] = '\0';

    return cleanedString;
}