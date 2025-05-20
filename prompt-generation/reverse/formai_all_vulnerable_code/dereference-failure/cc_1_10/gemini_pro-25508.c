//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char *reverse(char *str) {
    int len = strlen(str);
    char *rev = malloc(len + 1);
    int i, j;

    for (i = len - 1, j = 0; i >= 0; i--, j++) {
        rev[j] = str[i];
    }
    rev[j] = '\0';

    return rev;
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int len = strlen(str);
    char *rev = reverse(str);

    if (strcmp(str, rev) == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to find the longest palindrome in a string
char *longest_palindrome(char *str) {
    int len = strlen(str);
    int max_len = 0;
    char *start = NULL;
    char *end = NULL;

    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            char *sub = strndup(str + i, j - i + 1);

            if (is_palindrome(sub) && j - i + 1 > max_len) {
                max_len = j - i + 1;
                start = str + i;
                end = str + j;
            }

            free(sub);
        }
    }

    char *longest = malloc(max_len + 1);
    strncpy(longest, start, max_len);
    longest[max_len] = '\0';

    return longest;
}

int main() {
    char str[] = "racecar";
    char *rev = reverse(str);
    printf("The original string is %s.\n", str);
    printf("The reversed string is %s.\n", rev);
    printf("Is the string a palindrome? %s.\n", is_palindrome(str) ? "Yes" : "No");
    char *longest = longest_palindrome(str);
    printf("The longest palindrome in the string is %s.\n", longest);

    free(rev);
    free(longest);

    return 0;
}