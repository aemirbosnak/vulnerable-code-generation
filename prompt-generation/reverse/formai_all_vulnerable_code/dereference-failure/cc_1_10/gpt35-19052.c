//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: peaceful
/**
 * @file palindrome.c
 * @brief This program checks whether a given string is a palindrome or not.
 *        A palindrome is a string that reads the same backwards as forwards.
 *        For example, "racecar" is a palindrome, but "hello" is not.
 * @author [Your Name]
 */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

/**
 * @brief This function strips non-alphanumeric characters from a string
 *        and converts all uppercase letters to lowercase.
 * @param str The string to clean
 * @return A pointer to the cleaned string
 */
char *clean_string(char *str) {
    int len = strlen(str);
    char *cleaned_str = (char *) malloc(len + 1);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isalnum(str[i])) { // If alphanumeric character
            cleaned_str[j++] = tolower(str[i]); // Convert to lowercase and add to new string
        }
    }
    cleaned_str[j] = '\0'; // Put null character at end of string
    return cleaned_str;
}

/**
 * @brief This function checks whether a string is a palindrome.
 *        It uses two pointers to compare the characters from the beginning
 *        and end of the string, moving inwards until they meet in the middle.
 * @param str The string to check
 * @return true if the string is a palindrome, false otherwise
 */
bool is_palindrome(char *str) {
    int len = strlen(str);
    char *start = str, *end = str + len - 1;
    while (start < end) {
        if (*start != *end) {
            return false; // Characters do not match
        }
        start++, end--;
    }
    return true; // All characters matched
}

int main() {
    printf("Welcome to the Peaceful Palindrome Checker!\n\n");
    printf("Please enter a string to check if it is a palindrome:\n");

    char str[MAX_STRING_LENGTH];
    fgets(str, MAX_STRING_LENGTH, stdin); // Read in user input string
    str[strcspn(str, "\n")] = '\0'; // Remove trailing newline character

    char *cleaned_str = clean_string(str);
    bool is_pal = is_palindrome(cleaned_str);

    if (is_pal) {
        printf("\n%s is a peaceful palindrome! 🌺🕊️\n", str);
    } else {
        printf("\n%s is not a peaceful palindrome. 😔\n", str);
    }

    free(cleaned_str); // Free memory allocated for cleaned string

    return 0;
}