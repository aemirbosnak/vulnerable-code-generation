//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 1000

// Function to remove all spaces from a string
void removeSpaces(char *str) {
    int len = strlen(str);
    char *newStr = malloc(len + 1);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (!isspace(str[i])) {
            newStr[j++] = str[i];
        }
    }
    newStr[j] = '\0';
    strcpy(str, newStr);
    free(newStr);
}

// Function to reverse a string
void reverseString(char *str) {
    int len = strlen(str);
    char *newStr = malloc(len + 1);
    int j = 0;
    for (int i = len - 1; i >= 0; i--) {
        newStr[j++] = str[i];
    }
    newStr[j] = '\0';
    strcpy(str, newStr);
    free(newStr);
}

// Function to check if two strings are anagrams of each other
bool areAnagrams(char *str1, char *str2) {
    removeSpaces(str1);
    removeSpaces(str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1!= len2) {
        return false;
    }
    char *copy1 = strdup(str1);
    char *copy2 = strdup(str2);
    reverseString(copy1);
    reverseString(copy2);
    bool result = strcmp(copy1, copy2) == 0;
    free(copy1);
    free(copy2);
    return result;
}

int main() {
    char str1[MAX_STRING_LENGTH];
    char str2[MAX_STRING_LENGTH];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    if (areAnagrams(str1, str2)) {
        printf("The strings are anagrams of each other.\n");
    } else {
        printf("The strings are not anagrams of each other.\n");
    }

    return 0;
}