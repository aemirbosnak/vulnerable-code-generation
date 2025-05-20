//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to concatenate two strings
void concatenate(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *result = (char *) malloc((len1 + len2 + 1) * sizeof(char));

    strcpy(result, str1);
    strcat(result, str2);

    printf("Concatenated string: %s\n", result);
    free(result);
}

// Function to reverse a string
void reverse(char *str) {
    int len = strlen(str);
    char *result = (char *) malloc((len + 1) * sizeof(char));

    for (int i = len - 1; i >= 0; i--) {
        result[i] = str[len - 1 - i];
    }

    printf("Reversed string: %s\n", result);
    free(result);
}

// Function to check if two strings are equal
int compare(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1!= len2) {
        return 0;
    }

    for (int i = 0; i < len1; i++) {
        if (str1[i]!= str2[i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str1[MAX_SIZE] = "Hello";
    char str2[MAX_SIZE] = "World";

    // Concatenate two strings
    concatenate(str1, str2);

    // Reverse a string
    reverse(str1);

    // Check if two strings are equal
    int result = compare(str1, str2);

    if (result) {
        printf("Strings are equal.\n");
    } else {
        printf("Strings are not equal.\n");
    }

    return 0;
}