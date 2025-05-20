//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function to check whether a string is palindrome or not
bool isPalindrome(char *str) {
    // Find the length of the given string
    int len = strlen(str);
    
    // Loop through the string to check whether it is palindrome or not
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        // If the characters at i and j positions are different, return false
        if (str[i] != str[j]) {
            return false;
        }
    }
    
    // If all characters are checked and they are the same, return true
    return true;
}

// Function to handle asynchronous input
void handleInput(char *input) {
    // Allocate memory for the result message
    char *result = (char*) malloc(100 * sizeof(char));
    
    // Check whether the input is palindrome or not
    if (isPalindrome(input)) {
        strcpy(result, "The given string is a palindrome!");
    } else {
        strcpy(result, "The given string is not a palindrome!");
    }
    
    // Print the result
    printf("%s\n", result);
    
    // Free the result memory
    free(result);
}

int main() {
    // Allocate memory for the input string
    char *input = (char*) malloc(50 * sizeof(char));
    
    // Ask for user input
    printf("Enter a string: ");
    
    // Read the input asynchronously with fgets
    fgets(input, 50, stdin);
    
    // Call the function to handle input
    handleInput(input);
    
    // Free the input memory
    free(input);
    
    return 0;
}