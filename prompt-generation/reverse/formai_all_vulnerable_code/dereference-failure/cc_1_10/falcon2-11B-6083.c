//Falcon2-11B DATASET v1.0 Category: Palindrome Checker ; Style: future-proof
#include <stdio.h>
#include <string.h>

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
    // Create a temporary array to hold the reversed string
    char temp[strlen(str)];

    // Copy the string to the temporary array
    strcpy(temp, str);

    // Reverse the string
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        char tempChar = temp[i];
        temp[i] = temp[j];
        temp[j] = tempChar;
        i++;
        j--;
    }

    // Compare the original string with the reversed string
    int k = 0;
    while (str[k] == temp[k]) {
        k++;
    }

    // If the strings are equal, the original string is a palindrome
    return (k == strlen(str));
}

int main() {
    // Read a string from the user
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the newline character at the end of the string
    int i = strlen(str) - 1;
    while (str[i] == '\n') {
        str[i] = '\0';
        i--;
    }

    // Check if the string is a palindrome
    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}