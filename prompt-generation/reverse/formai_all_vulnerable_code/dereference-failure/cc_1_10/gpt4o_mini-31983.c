//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void reverseString(char *str);
int isPalindrome(char *str);
void countCharacterFrequency(char *str);
void concatenateStrings(char *str1, char *str2);
void printStringWithSpaces(char *str);
void introspectStringProcessing(char *str);

int main() {
    char str1[100], str2[100];
    
    printf("Welcome to the Introspective String Manipulation Program!\n");
    printf("Please enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';  // Remove newline character

    printf("Please enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';  // Remove newline character

    // Perform string manipulations
    introspectStringProcessing(str1);
    introspectStringProcessing(str2);
    
    // Concatenate strings
    concatenateStrings(str1, str2);
    
    return 0;
}

void introspectStringProcessing(char *str) {
    printf("\nProcessing the string: \"%s\"\n", str);
    
    // Length of the string
    int length = strlen(str);
    printf("The length of the string is: %d\n", length);
    
    // Reverse the string
    char *reversedStr = strdup(str);
    reverseString(reversedStr);
    printf("The reversed string is: \"%s\"\n", reversedStr);
    free(reversedStr);
    
    // Check for palindrome
    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    // Count character frequency
    countCharacterFrequency(str);
    
    // Print string with spaces
    printStringWithSpaces(str);
}

void reverseString(char *str) {
    int left = 0, right = strlen(str) - 1;
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

int isPalindrome(char *str) {
    int start = 0;
    int end = strlen(str) - 1;
    while (start < end) {
        if (tolower(str[start]) != tolower(str[end])) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

void countCharacterFrequency(char *str) {
    int frequency[256] = {0};
    for (int i = 0; str[i]; i++) {
        frequency[(unsigned char)str[i]]++;
    }
    
    printf("Character Frequency:\n");
    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            printf("'%c' : %d\n", i, frequency[i]);
        }
    }
}

void concatenateStrings(char *str1, char *str2) {
    char *result = malloc(strlen(str1) + strlen(str2) + 1);
    if (!result) {
        fprintf(stderr, "Memory allocation failed!\n");
        return;
    }
    strcpy(result, str1);
    strcat(result, str2);
    
    printf("The concatenated string is: \"%s\"\n", result);
    
    free(result);
}

void printStringWithSpaces(char *str) {
    for (int i = 0; str[i]; i++) {
        printf("%c ", str[i]);
    }
    printf("\n");
}