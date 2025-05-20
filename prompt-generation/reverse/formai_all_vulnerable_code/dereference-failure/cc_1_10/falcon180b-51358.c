//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Function to reverse a string using bitwise operations
void reverseString(char* str, int length) {
    char* start = str;
    char* end = str + length - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// Function to check if a string is a palindrome using bitwise operations
bool isPalindrome(char* str, int length) {
    char* start = str;
    char* end = str + length - 1;
    while (start < end) {
        if (*start!= *end) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);
    int length = strlen(str);

    // Reverse the string using bitwise operations
    reverseString(str, length);
    printf("Reversed string: %s\n", str);

    // Check if the reversed string is a palindrome using bitwise operations
    if (isPalindrome(str, length)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}