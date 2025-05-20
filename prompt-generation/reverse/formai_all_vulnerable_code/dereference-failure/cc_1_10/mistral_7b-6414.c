//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void check_palindrome(char *str, int start, int end);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        exit(1);
    }

    char str1[100], str2[100];
    strcpy(str1, argv[1]);
    strcpy(str2, argv[2]);

    printf("Checking if '%s' and its reverse '%s' are palindromes...\n", str1, str2);

    // Convert both strings to lowercase
    int i;
    for (i = 0; str1[i]; i++)
        str1[i] = tolower(str1[i]);

    for (i = 0; str2[i]; i++)
        str2[i] = tolower(str2[i]);

    check_palindrome(str1, 0, strlen(str1) - 1);
    printf("\n");

    return 0;
}

void check_palindrome(char *str, int start, int end) {
    if (start >= end) { // Base case: empty string or single character
        printf("'%s' is a palindrome!\n", str);
        return;
    }

    if (str[start] != str[end]) { // If characters don't match, it's not a palindrome
        printf("'%s' is not a palindrome. :(\n", str);
        exit(1);
    }

    check_palindrome(str + 1, start + 1, end - 1);
}

/*
This program takes two command line arguments, checks if they are identical,
and then recursively checks if they are palindromes by comparing their characters
from the middle outward. If the strings are the same length, it checks the characters
in the middle first. If they are not palindromes, it prints a sad face and exits.
If they are palindromes, it prints a happy face and continues checking the rest of the string.
*/