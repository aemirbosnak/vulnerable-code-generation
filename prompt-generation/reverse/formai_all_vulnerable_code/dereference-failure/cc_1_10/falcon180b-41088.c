//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

/* Function to concatenate two strings */
void concatenateStrings(char* str1, char* str2) {
    int length1 = strlen(str1);
    int length2 = strlen(str2);
    char* result = malloc(length1 + length2 + 1);
    strcpy(result, str1);
    strcat(result, str2);
    printf("Concatenated string: %s\n", result);
    free(result);
}

/* Function to reverse a string */
void reverseString(char* str) {
    int length = strlen(str);
    char* reversed = malloc(length + 1);
    int i;
    for (i = 0; i < length; i++) {
        reversed[i] = str[length - 1 - i];
    }
    reversed[i] = '\0';
    printf("Reversed string: %s\n", reversed);
    free(reversed);
}

/* Function to check if a string is a palindrome */
int isPalindrome(char* str) {
    int length = strlen(str);
    int i;
    for (i = 0; i < length / 2; i++) {
        if (str[i]!= str[length - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];

    /* Prompt user to enter two strings */
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    /* Concatenate the two strings */
    concatenateStrings(str1, str2);

    /* Reverse the concatenated string */
    char* reversed = malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(reversed, str1);
    strcat(reversed, str2);
    reverseString(reversed);

    /* Check if the reversed string is a palindrome */
    if (isPalindrome(reversed)) {
        printf("The concatenated string is a palindrome.\n");
    } else {
        printf("The concatenated string is not a palindrome.\n");
    }

    free(reversed);
    return 0;
}