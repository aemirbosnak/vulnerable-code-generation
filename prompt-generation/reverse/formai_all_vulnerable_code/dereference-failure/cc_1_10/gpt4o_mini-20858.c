//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse the input string
char* reverseString(const char* str) {
    size_t len = strlen(str);
    char* reversed = (char*)malloc(len + 1);
    if (!reversed) {
        perror("Unable to allocate memory for reversed string");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < len; i++) {
        reversed[i] = str[len - i - 1];
    }
    reversed[len] = '\0';
    return reversed;
}

// Function to concatenate two strings
char* concatenateStrings(const char* str1, const char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char* concatenated = (char*)malloc(len1 + len2 + 1);
    if (!concatenated) {
        perror("Unable to allocate memory for concatenated string");
        exit(EXIT_FAILURE);
    }
    strcpy(concatenated, str1);
    strcat(concatenated, str2);
    return concatenated;
}

// Function to find a substring
int findSubstring(const char* haystack, const char* needle) {
    char* position = strstr(haystack, needle);
    return position ? (position - haystack) : -1;
}

// Function to count occurrences of a character in a string
int countCharacter(const char* str, char ch) {
    int count = 0;
    while (*str) {
        if (*str == ch) {
            count++;
        }
        str++;
    }
    return count;
}

// Function to display the manipulated results
void displayResults(const char* original, const char* reversed, const char* concatenated, int substringIndex, int characterCount) {
    printf("Original String: %s\n", original);
    printf("Reversed String: %s\n", reversed);
    printf("Concatenated String: %s\n", concatenated);
    if (substringIndex != -1) {
        printf("Substring found at index: %d\n", substringIndex);
    } else {
        printf("Substring not found.\n");
    }
    printf("Character count: %d\n", characterCount);
}

int main() {
    char original[256];
    char toConcatenate[256];
    char substring[256];
    char characterToCount;

    printf("Enter the original string (max 255 characters): ");
    fgets(original, sizeof(original), stdin);
    original[strcspn(original, "\n")] = 0; // Remove the newline character

    printf("Enter a string to concatenate: ");
    fgets(toConcatenate, sizeof(toConcatenate), stdin);
    toConcatenate[strcspn(toConcatenate, "\n")] = 0; // Remove the newline character

    printf("Enter a substring to find: ");
    fgets(substring, sizeof(substring), stdin);
    substring[strcspn(substring, "\n")] = 0; // Remove the newline character

    printf("Enter a character to count: ");
    scanf(" %c", &characterToCount);
    
    // Perform string operations
    char* reversed = reverseString(original);
    char* concatenated = concatenateStrings(original, toConcatenate);
    int substringIndex = findSubstring(original, substring);
    int characterCount = countCharacter(original, characterToCount);

    // Display results
    displayResults(original, reversed, concatenated, substringIndex, characterCount);

    // Clean up allocated memory
    free(reversed);
    free(concatenated);

    return 0;
}