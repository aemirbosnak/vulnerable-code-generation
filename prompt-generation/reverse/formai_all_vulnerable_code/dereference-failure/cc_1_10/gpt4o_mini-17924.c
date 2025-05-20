//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to clean and normalize the string
void cleanString(char *str) {
    char *src = str, *dst = str;
    while (*src) {
        if (isalnum((unsigned char)*src) || isspace((unsigned char)*src)) {
            *dst++ = (char)tolower((unsigned char)*src); // Convert to lowercase
        }
        src++;
    }
    *dst = '\0'; // Null-terminate the cleaned string
}

// Function to check if the words in the string form a palindrome
int isPalindrome(const char *str) {
    const char *start = str;
    const char *end = str + strlen(str) - 1;
    while (start < end) {
        if (*start != *end) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

// Function to count the occurrence of a word in the text
int countOccurrences(const char *text, const char *word) {
    int count = 0;
    const char *tmp = text;
    while ((tmp = strstr(tmp, word)) != NULL) {
        count++;
        tmp += strlen(word);
    }
    return count;
}

// Main function to drive the program
int main() {
    char inputText[256];
    char wordToFind[50];

    printf("Welcome to the Sherlock Holmes Text Analysis Tool!\n");
    
    // Input the text for analysis
    printf("Enter the text to analyze (up to 255 characters): ");
    fgets(inputText, sizeof(inputText), stdin);
    inputText[strcspn(inputText, "\n")] = '\0'; // Remove trailing newline

    // Clean the input text
    char cleanedText[256];
    strcpy(cleanedText, inputText);
    cleanString(cleanedText);
    
    // Check for palindrome
    if (isPalindrome(cleanedText)) {
        printf("The cleaned text is a palindrome!\n");
    } else {
        printf("The cleaned text is not a palindrome.\n");
    }

    // Input the word to find
    printf("Enter the word you wish to search for: ");
    fgets(wordToFind, sizeof(wordToFind), stdin);
    wordToFind[strcspn(wordToFind, "\n")] = '\0'; // Remove trailing newline

    // Clean the word for search
    cleanString(wordToFind);
    
    // Count occurrences of the word
    int occurrences = countOccurrences(cleanedText, wordToFind);
    
    // Output the result
    if (occurrences > 0) {
        printf("The word '%s' was found %d time(s) in the text.\n", wordToFind, occurrences);
    } else {
        printf("The word '%s' was not found in the text.\n", wordToFind);
    }

    // Exit message
    printf("Thank you for using the Sherlock Holmes Text Analysis Tool.\n");
    return 0;
}