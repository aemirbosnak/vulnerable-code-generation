//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char *str);

int main() {
    char input[100];
    int result;

    printf("Enter a string: ");
    fgets(input, 100, stdin);

    // Remove newline character from input if present
    if(input[strlen(input)-1] == '\n')
        input[strlen(input)-1] = '\0';

    // Convert input to lowercase
    for(int i=0; i<strlen(input); i++) {
        input[i] = tolower(input[i]);
    }

    // Check if input is a palindrome
    result = isPalindrome(input);

    if(result) {
        printf("The input string is a palindrome.\n");
    } else {
        printf("The input string is not a palindrome.\n");
    }

    return 0;
}

int isPalindrome(char *str) {
    int len = strlen(str);
    char *temp = (char*)malloc(sizeof(char)*(len+1));  // allocate memory for temporary string

    // Copy string in reverse order to temp string
    for(int i=0; i<len; i++) {
        temp[len-1-i] = str[i];
    }

    temp[len] = '\0';  // Add null character at end of temp string

    // Compare original and temp string to check for palindrome
    int result = strcmp(str, temp);

    free(temp);  // free allocated memory for temp string

    if(result == 0) {
        return 1;
    } else {
        return 0;
    }
}