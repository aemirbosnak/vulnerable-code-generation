//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: curious
#include <stdio.h>
#include <string.h>

// function to check if given string is palindrome or not
int isPalindrome(char str[]) {

    // initialize variables
    int i = 0;
    int j = strlen(str) - 1;

    // iterate through the characters in the string
    while (i < j) {

        // ignore any non-alphanumeric characters
        while (!isalnum(str[i])) {
            i++;
        }
        while (!isalnum(str[j])) {
            j--;
        }

        // check if the corresponding characters in the string are equal
        if (tolower(str[i]) != tolower(str[j])) {
            return 0; // not a palindrome
        }

        // move to next pair of characters
        i++;
        j--;
    }

    return 1; // palindrome
}

int main() {

    // declare variables
    char str[100];

    // prompt user for input
    printf("Enter a string to check if it is a palindrome: ");
    fgets(str, sizeof(str), stdin);

    // remove newline character from input
    str[strcspn(str, "\n")] = 0;

    // check if input string is palindrome
    if (isPalindrome(str)) {
        printf("%s is a palindrome!\n", str);
    } else {
        printf("%s is not a palindrome :(\n", str);
    }

    return 0;
}