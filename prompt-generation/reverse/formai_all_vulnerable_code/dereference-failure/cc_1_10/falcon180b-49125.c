//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000 // Maximum length of input string

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
    int len = strlen(str);
    int i = 0;
    int j = len - 1;
    
    // Ignore non-alphabetic characters and spaces
    while (!isalpha(str[i]) &&!isspace(str[i])) {
        i++;
    }
    
    while (!isalpha(str[j]) &&!isspace(str[j])) {
        j--;
    }
    
    // Compare characters from both ends of the string
    while (i < j) {
        if (tolower(str[i])!= tolower(str[j])) {
            return 0; // Not a palindrome
        }
        i++;
        j--;
    }
    
    return 1; // Palindrome
}

int main() {
    char input[MAX_LENGTH];
    
    printf("Enter a string to check if it's a palindrome: ");
    fgets(input, MAX_LENGTH, stdin);
    
    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';
    
    // Check if input is a palindrome
    if (isPalindrome(input)) {
        printf("%s is a palindrome.\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }
    
    return 0;
}