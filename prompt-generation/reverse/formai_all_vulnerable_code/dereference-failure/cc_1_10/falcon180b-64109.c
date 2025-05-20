//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverse(char* str) {
    int len = strlen(str);
    char* reversed = malloc(len + 1); // Allocate memory for the reversed string
    char* ptr = reversed; // Set pointer to the end of the reversed string
    for (int i = len - 1; i >= 0; i--) {
        *ptr++ = str[i]; // Copy characters from the original string to the reversed string
    }
    *ptr = '\0'; // Add null terminator to the end of the reversed string
    printf("Reversed string: %s\n", reversed); // Print the reversed string
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i]!= str[len - 1 - i]) { // Compare characters from the beginning and end of the string
            return 0; // If any characters do not match, return 0 (not a palindrome)
        }
    }
    return 1; // If all characters match, return 1 (palindrome)
}

int main() {
    char str1[] = "racecar";
    reverse(str1); // Reverse the string
    printf("String 1 reversed: %s\n", str1);

    char str2[] = "hello";
    reverse(str2); // Reverse the string
    printf("String 2 reversed: %s\n", str2);

    char str3[] = "A man a plan a canal Panama";
    reverse(str3); // Reverse the string
    printf("String 3 reversed: %s\n", str3);

    if (isPalindrome(str1)) {
        printf("String 1 is a palindrome\n");
    } else {
        printf("String 1 is not a palindrome\n");
    }

    if (isPalindrome(str2)) {
        printf("String 2 is a palindrome\n");
    } else {
        printf("String 2 is not a palindrome\n");
    }

    if (isPalindrome(str3)) {
        printf("String 3 is a palindrome\n");
    } else {
        printf("String 3 is not a palindrome\n");
    }

    return 0;
}