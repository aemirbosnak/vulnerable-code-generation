//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// A twist in the mind-bending algorithm: the recursive way to check for palindrome
int isPalindromeRecursive(const char *str, int start, int end) {
    // Ignore non-alphabetic characters by advancing start and reducing end
    while (start < end && !isalpha(str[start])) {
        start++;
    }
    while (start < end && !isalpha(str[end])) {
        end--;
    }
    
    // Base case for recursion
    if (start >= end) {
        return 1; // It's a palindrome
    }
    
    // Compare the characters case-insensitively
    if (tolower(str[start]) != tolower(str[end])) {
        return 0; // Not a palindrome
    }
    
    // Move inward in recursion
    return isPalindromeRecursive(str, start + 1, end - 1);
}

// A helper function to initiate the recursive palindrome check
int isPalindrome(const char *str) {
    int len = strlen(str);
    return isPalindromeRecursive(str, 0, len - 1);
}

// Function to read an input string from the user
void readInput(char *inputBuffer, size_t size) {
    printf("Enter a string to check for palindrome: ");
    if (fgets(inputBuffer, size, stdin) != NULL) {
        // Remove newline character if present
        size_t newlineIndex = strlen(inputBuffer) - 1;
        if (inputBuffer[newlineIndex] == '\n') {
            inputBuffer[newlineIndex] = '\0';
        }
    }
}

// The main function wraps around our mind-bending palindrome checker
int main() {
    char inputString[256]; // To hold user input, a spacious dwelling for thoughts
    printf("Welcome to the mind-bending Palindrome Checker!\n");
    
    while (1) {
        readInput(inputString, sizeof(inputString));
        if (strcmp(inputString, "exit") == 0) {
            printf("Exiting the program. Bye-bye!\n");
            break; // Exit the loop if the user types "exit"
        }
        
        // Analyze the string and determine if it's a palindrome
        if (isPalindrome(inputString)) {
            printf("The string \"%s\" is a Palindrome! \n", inputString);
        } else {
            printf("The string \"%s\" is NOT a Palindrome. \n", inputString);
        }
        
        printf("Would you like to check another string? (Y/N): ");
        char response = getchar();
        while (getchar() != '\n'); // Clear input buffer
        
        if (tolower(response) != 'y') {
            printf("Thank you for playing with palindromes, farewell!\n");
            break; // Exit if the user does not want to continue
        }
    }
    return 0; // Program executed successfully!
}