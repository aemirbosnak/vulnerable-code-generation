//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverse_string(char *str) {
    int len = strlen(str);
    char *rev_str = malloc(len + 1); // Allocate memory for the reversed string

    int i = 0;
    for (int j = len - 1; j >= 0; j--) {
        rev_str[i++] = str[j];
    }

    printf("Reversed string: %s\n", rev_str); // Print the reversed string
    free(rev_str); // Free the memory allocated for the reversed string
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int len = strlen(str);
    char *rev_str = malloc(len + 1); // Allocate memory for the reversed string

    int i = 0;
    for (int j = len - 1; j >= 0; j--) {
        rev_str[i++] = str[j];
    }

    for (int k = 0; k < len; k++) {
        if (str[k]!= rev_str[k]) {
            return 0; // Not a palindrome
        }
    }

    return 1; // Palindrome
}

int main() {
    char str1[100] = "racecar";
    char str2[100] = "hello world";
    char str3[100] = "A man a plan a canal Panama";

    printf("Original string 1: %s\n", str1);
    reverse_string(str1); // Reverse string 1

    printf("Original string 2: %s\n", str2);
    if (is_palindrome(str2)) {
        printf("%s is a palindrome\n", str2);
    } else {
        printf("%s is not a palindrome\n", str2);
    }

    printf("Original string 3: %s\n", str3);
    if (is_palindrome(str3)) {
        printf("%s is a palindrome\n", str3);
    } else {
        printf("%s is not a palindrome\n", str3);
    }

    return 0;
}