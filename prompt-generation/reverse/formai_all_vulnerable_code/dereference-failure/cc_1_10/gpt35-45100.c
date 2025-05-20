//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a function to check if a string is palindrome
int is_palindrome(char *str) {
    int len = strlen(str);
    int i, j;

    // loop through the string from both ends
    for (i = 0, j = len - 1; i < j; i++, j--) {
        // if any characters don't match, return false
        if (str[i] != str[j]) {
            return 0;
        }
    }

    // if we reached here, it means the string is a palindrome
    return 1;
}

// define a function to print a welcome message
void print_welcome() {
    printf("Welcome to the Palindrome Checker!\n");
    printf("Enter a word or phrase to check if it's a palindrome:\n");
}

// define a function to read input from the user
char* get_input() {
    // allocate memory for the input buffer
    char *input = (char*) malloc(sizeof(char) * 100);

    // read input from the user
    fgets(input, 100, stdin);

    // remove the newline character at the end of the input
    input[strlen(input) - 1] = '\0';

    // return the input buffer
    return input;
}

// define a function to print the result of the palindrome check
void print_result(int is_palindrome) {
    if (is_palindrome) {
        printf("Congratulations, the input is a palindrome!\n");
    } else {
        printf("Sorry, the input is not a palindrome.\n");
    }
}

int main() {
    // print a welcome message
    print_welcome();

    // read input from the user
    char *input = get_input();

    // check if the input is a palindrome
    int result = is_palindrome(input);

    // print the result of the palindrome check
    print_result(result);

    // free the memory allocated for the input buffer
    free(input);

    return 0;
}