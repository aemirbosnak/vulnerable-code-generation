//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STR_LEN 1024

// Function to reverse a string
void reverse_string(char *str) {
    int i, j, len = strlen(str);
    char temp[len];

    for (i = 0; i < len; i++) {
        temp[i] = str[len - i - 1];
    }

    strcpy(str, temp);
}

// Function to find the longest common prefix of two strings
void find_lcp(char *str1, char *str2) {
    int i, j, len1 = strlen(str1), len2 = strlen(str2);
    char temp[len1 + len2];

    for (i = 0; i < len1 && i < len2; i++) {
        if (str1[i] == str2[i]) {
            temp[i] = str1[i];
        } else {
            break;
        }
    }

    strcpy(str1, temp);
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int i, len = strlen(str);

    for (i = 0; i < len; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str1[MAX_STR_LEN], str2[MAX_STR_LEN];
    char *p;

    printf("Enter two strings: ");
    fgets(str1, MAX_STR_LEN, stdin);
    fgets(str2, MAX_STR_LEN, stdin);

    // Reverse the strings
    reverse_string(str1);
    reverse_string(str2);

    // Find the longest common prefix of the two strings
    find_lcp(str1, str2);

    // Check if the strings are palindromes
    if (is_palindrome(str1) && is_palindrome(str2)) {
        printf("The strings are palindromes!\n");
    } else {
        printf("At least one of the strings is not a palindrome.\n");
    }

    return 0;
}