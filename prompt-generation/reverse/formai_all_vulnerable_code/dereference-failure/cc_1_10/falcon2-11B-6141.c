//Falcon2-11B DATASET v1.0 Category: Palindrome Checker ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a string is a palindrome
bool isPalindrome(char* str) {
    int i = 0, j = strlen(str) - 1;
    
    while (i < j) {
        if (str[i++]!= str[j--])
            return false;
    }
    
    return true;
}

// Function to reverse a string
char* reverseString(char* str) {
    char* reversed = malloc(strlen(str) + 1);
    
    for (int i = 0; i < strlen(str); i++) {
        reversed[i] = str[strlen(str) - i - 1];
    }
    
    reversed[strlen(str)] = '\0';
    
    return reversed;
}

// Main function
int main() {
    char* str = "racecar";
    
    // Check if the string is a palindrome
    if (isPalindrome(str)) {
        printf("The string '%s' is a palindrome.\n", str);
    } else {
        printf("The string '%s' is not a palindrome.\n", str);
    }
    
    // Reverse the string
    char* reversedStr = reverseString(str);
    
    // Check if the reversed string is a palindrome
    if (isPalindrome(reversedStr)) {
        printf("The reversed string '%s' is a palindrome.\n", reversedStr);
    } else {
        printf("The reversed string '%s' is not a palindrome.\n", reversedStr);
    }
    
    free(reversedStr);
    
    return 0;
}