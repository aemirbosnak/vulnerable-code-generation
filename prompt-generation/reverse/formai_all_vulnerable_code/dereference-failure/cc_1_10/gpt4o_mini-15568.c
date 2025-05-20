//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverseString(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to concatenate a string to another with a separator
char* concatenateWithSeparator(const char* str1, const char* str2, char separator) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // Allocate memory for the new string
    char* newStr = (char*)malloc(len1 + len2 + 2); // +2 for separator and null terminator
    if (newStr == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }

    // Copy the first string
    strcpy(newStr, str1);
    
    // Add the separator
    newStr[len1] = separator;
    
    // Copy the second string
    strcpy(newStr + len1 + 1, str2);
    
    return newStr;
}

// Function to find and replace a substring within a string
char* replaceSubstring(const char* str, const char* oldSub, const char* newSub) {
    char* pos = strstr(str, oldSub);
    if (pos == NULL) {
        return strdup(str); // Return a copy if substring not found
    }

    int lenStr = strlen(str);
    int lenOldSub = strlen(oldSub);
    int lenNewSub = strlen(newSub);
    
    // Create a new string with enough space
    char* newStr = (char*)malloc(lenStr - lenOldSub + lenNewSub + 1);
    if (newStr == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }

    // Copy the part before the old substring
    strncpy(newStr, str, pos - str);
    newStr[pos - str] = '\0';
    
    // Concatenate the new substring
    strcat(newStr, newSub);
    
    // Add the rest of the original string after the old substring
    strcat(newStr, pos + lenOldSub);
    
    return newStr;
}

// Function to count occurrences of a substring
int countOccurrences(const char* str, const char* sub) {
    int count = 0;
    const char* tmp = str;
    
    while ((tmp = strstr(tmp, sub)) != NULL) {
        count++;
        tmp += strlen(sub); // Move past the substring
    }
    
    return count;
}

// Function to print a string character by character
void printCharByChar(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c\n", str[i]);
    }
}

int main() {
    char str1[100], str2[100];
    
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove newline character
    
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove newline character
    
    // String reversal demonstration
    printf("\nOriginal first string: %s\n", str1);
    reverseString(str1);
    printf("Reversed first string: %s\n\n", str1);
    
    // String concatenation demonstration
    char separator = ' ';
    char* concatenatedStr = concatenateWithSeparator(str1, str2, separator);
    printf("Concatenated string: %s\n\n", concatenatedStr);
    
    // Substring replacement demonstration
    char* replacedStr = replaceSubstring(concatenatedStr, " ", "_");
    printf("Replaced substring (spaces with underscores): %s\n\n", replacedStr);
    
    // Count occurrences demonstration
    int count = countOccurrences(replacedStr, "_");
    printf("Occurrences of underscore in replaced string: %d\n\n", count);
    
    // Print string character by character
    printf("Character by character:\n");
    printCharByChar(replacedStr);
    
    // Clean up dynamically allocated memory
    free(concatenatedStr);
    free(replacedStr);
    
    return 0;
}