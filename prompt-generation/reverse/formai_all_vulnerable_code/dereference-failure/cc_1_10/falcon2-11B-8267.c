//Falcon2-11B DATASET v1.0 Category: Palindrome Checker ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a string is a palindrome
bool isPalindrome(char *str) {
    int length = strlen(str);
    int i, j;
    
    // Traverse the string and check if it's a palindrome
    for (i = 0, j = length - 1; i < j; i++, j--) {
        if (str[i]!= str[j]) {
            return false;
        }
    }
    
    return true;
}

// Function to check if a string is a palindrome in a multiplayer style
bool isPalindromeMultiplayer(char *str, int n) {
    // Check if the length of the string is odd
    if (n % 2 == 1) {
        return false;
    }
    
    // Split the string into two halves
    int mid = n / 2;
    char *half1 = (char *)malloc(sizeof(char) * mid);
    char *half2 = (char *)malloc(sizeof(char) * mid);
    
    // Copy the first half of the string to half1
    strncpy(half1, str, mid);
    half1[mid] = '\0';
    
    // Copy the second half of the string to half2
    strncpy(half2, str + mid, mid);
    half2[mid] = '\0';
    
    // Check if each half is a palindrome
    if (!isPalindrome(half1) ||!isPalindrome(half2)) {
        return false;
    }
    
    // Free memory allocated for half1 and half2
    free(half1);
    free(half2);
    
    return true;
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove the newline character from the end of the string
    str[strcspn(str, "\n")] = '\0';
    
    if (isPalindromeMultiplayer(str, strlen(str))) {
        printf("The string is a palindrome in a multiplayer style.\n");
    } else {
        printf("The string is not a palindrome in a multiplayer style.\n");
    }
    
    return 0;
}