//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverseString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to concatenate two strings
char* concatenateStrings(char *str1, char *str2) {
    char *result = malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

// Function to find length of string without using strlen
int manualStrlen(const char *str) {
    int length = 0;
    while (*str++) length++;
    return length;
}

// Function to count vowels in a string
int countVowels(const char *str) {
    int count = 0;
    while (*str) {
        char c = *str++;
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }
    return count;
}

// Function to convert string to uppercase
void toUpperCase(char *str) {
    while (*str) {
        if (*str >= 'a' && *str <= 'z') {
            *str -= 32; // Convert to uppercase
        }
        str++;
    }
}

// Function to convert string to lowercase
void toLowerCase(char *str) {
    while (*str) {
        if (*str >= 'A' && *str <= 'Z') {
            *str += 32; // Convert to lowercase
        }
        str++;
    }
}

// Function to print string details
void printStringInfo(const char *str) {
    printf("String: '%s'\n", str);
    printf("Length: %d\n", manualStrlen(str));
    printf("Vowel Count: %d\n", countVowels(str));
}

int main() {
    char str1[100], str2[100];

    // Input two strings
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove newline character

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove newline character

    // Print initial string info
    printf("\n--- Initial String Info ---\n");
    printStringInfo(str1);
    printStringInfo(str2);

    // Concatenation
    char *concatenated = concatenateStrings(str1, str2);
    printf("\nConcatenated String: '%s'\n", concatenated);

    // Reverse the concatenated string
    reverseString(concatenated);
    printf("Reversed Concatenated String: '%s'\n", concatenated);

    // Convert to uppercase
    toUpperCase(concatenated);
    printf("Uppercase Concatenated String: '%s'\n", concatenated);

    // Convert to lowercase
    toLowerCase(concatenated);
    printf("Lowercase Concatenated String: '%s'\n", concatenated);

    // Clean up memory
    free(concatenated);
    
    return 0;
}