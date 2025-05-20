//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: Dennis Ritchie
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1000 // Maximum length of input string

int isPalindrome(char *str); // Function to check if a string is a palindrome

int main() {
    char input[MAX_LENGTH]; // Input string
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin); // Read input string from user
    input[strcspn(input, "\n")] = '\0'; // Remove newline character from input string
    
    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    
    return 0;
}

int isPalindrome(char *str) {
    int length = strlen(str); // Length of input string
    char *reverse = (char *) malloc(length + 1); // Allocate memory for reversed string
    int i = 0, j = length - 1; // Indexes for input and reversed strings
    
    while (i < j) {
        if (!isalnum(str[i])) { // If input character is not alphanumeric, skip it
            i++;
        } else if (!isalnum(str[j])) { // If input character is not alphanumeric, skip it
            j--;
        } else if (tolower(str[i])!= tolower(str[j])) { // If input characters are not equal (case-insensitive), return false
            free(reverse); // Free memory allocated for reversed string
            return 0;
        } else {
            reverse[i] = str[j]; // Copy input character to reversed string
            i++;
            j--;
        }
    }
    
    reverse[i] = '\0'; // Terminate reversed string
    
    if (strcmp(str, reverse) == 0) { // If input and reversed strings are equal, return true
        free(reverse); // Free memory allocated for reversed string
        return 1;
    } else {
        free(reverse); // Free memory allocated for reversed string
        return 0;
    }
}