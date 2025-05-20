//Falcon2-11B DATASET v1.0 Category: String manipulation ; Style: sophisticated
#include <stdio.h>

// Function to reverse a string
char* reverseString(char* str) {
    char* reversed = (char*) malloc(strlen(str) + 1);
    int i, j;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        reversed[i] = str[j];
    }
    reversed[i] = '\0';
    return reversed;
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int i, j;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if (str[i]!= str[j]) {
            return 0;
        }
    }
    return 1;
}

// Main function to print reversed palindromes of some strings
int main() {
    char* str1 = "racecar";
    char* str2 = "hello";
    char* str3 = "12321";

    printf("Reversed String 1: %s\n", reverseString(str1));
    printf("Reversed String 2: %s\n", reverseString(str2));
    printf("Reversed String 3: %s\n", reverseString(str3));

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