//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1000

// Function to remove all vowels from a string
char* removeVowels(char* str) {
    int len = strlen(str);
    char* newStr = (char*)malloc(len + 1);
    int j = 0;

    for (int i = 0; i < len; i++) {
        if (str[i]!= 'a' && str[i]!= 'e' && str[i]!= 'i' && str[i]!= 'o' && str[i]!= 'u' && str[i]!= 'A' && str[i]!= 'E' && str[i]!= 'I' && str[i]!= 'O' && str[i]!= 'U') {
            newStr[j++] = str[i];
        }
    }

    newStr[j] = '\0';
    return newStr;
}

// Function to reverse a string
char* reverseString(char* str) {
    int len = strlen(str);
    char* newStr = (char*)malloc(len + 1);
    int j = 0;

    for (int i = len - 1; i >= 0; i--) {
        newStr[j++] = str[i];
    }

    newStr[j] = '\0';
    return newStr;
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int len = strlen(str);
    char* reversedStr = reverseString(str);

    for (int i = 0; i < len; i++) {
        if (reversedStr[i]!= str[i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char inputStr[MAX_STR_LEN];
    printf("Enter a string: ");
    scanf("%s", inputStr);

    // Remove all vowels from the input string
    char* newStr = removeVowels(inputStr);
    printf("String without vowels: %s\n", newStr);

    // Reverse the input string
    char* reversedStr = reverseString(inputStr);
    printf("Reversed string: %s\n", reversedStr);

    // Check if the input string is a palindrome
    if (isPalindrome(inputStr)) {
        printf("The input string is a palindrome.\n");
    } else {
        printf("The input string is not a palindrome.\n");
    }

    return 0;
}