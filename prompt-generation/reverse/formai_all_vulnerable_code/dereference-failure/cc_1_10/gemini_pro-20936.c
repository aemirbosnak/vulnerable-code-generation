//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024

// Function to reverse a string
void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to find the longest palindrome in a string
char *longest_palindrome(char *str) {
    int len = strlen(str);
    int max_len = 1;
    int start = 0;

    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            int sub_len = j - i + 1;
            if (sub_len > max_len && is_palindrome(str + i)) {
                max_len = sub_len;
                start = i;
            }
        }
    }

    char *palindrome = malloc(max_len + 1);
    strncpy(palindrome, str + start, max_len);
    palindrome[max_len] = '\0';

    return palindrome;
}

// Function to test the string manipulation functions
int main() {
    char str1[] = "racecar";
    char str2[] = "kayak";
    char str3[] = "stressed";

    printf("Original string: %s\n", str1);
    reverse(str1);
    printf("Reversed string: %s\n", str1);
    printf("Is palindrome: %d\n", is_palindrome(str1));

    printf("\nOriginal string: %s\n", str2);
    printf("Longest palindrome: %s\n", longest_palindrome(str2));

    printf("\nOriginal string: %s\n", str3);
    printf("Longest palindrome: %s\n", longest_palindrome(str3));

    return 0;
}