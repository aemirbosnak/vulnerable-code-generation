//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to reverse a string
void reverseString(char *str) {
    int len = strlen(str);
    char *rev = malloc(len + 1); // allocate memory for the reversed string
    int j = 0;

    for (int i = len - 1; i >= 0; i--) {
        rev[j++] = str[i];
    }

    rev[j] = '\0'; // add null terminator to the end of the reversed string

    printf("Reversed string: %s\n", rev);
    free(rev); // free the memory allocated for the reversed string
}

// function to check if a string is a palindrome
int isPalindrome(char *str) {
    int len = strlen(str);
    char *rev = malloc(len + 1); // allocate memory for the reversed string
    int j = 0;

    for (int i = len - 1; i >= 0; i--) {
        rev[j++] = str[i];
    }

    rev[j] = '\0'; // add null terminator to the end of the reversed string

    int isPal = 1; // assume the string is a palindrome

    for (int i = 0; i < len / 2; i++) {
        if (rev[i]!= str[i]) {
            isPal = 0; // if characters don't match, set isPal to 0 (not a palindrome)
            break;
        }
    }

    free(rev); // free the memory allocated for the reversed string

    return isPal;
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    // call reverseString function to reverse the input string
    reverseString(input);

    // call isPalindrome function to check if the input string is a palindrome
    int isPal = isPalindrome(input);

    if (isPal) {
        printf("%s is a palindrome.\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }

    return 0;
}