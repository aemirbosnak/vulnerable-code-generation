//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: random
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

// Function to remove non-alphanumeric characters and convert to lowercase
void clean_string(char* str) {
    int i = 0;
    while (*(str+i)!= '\0') {
        if (isalnum(*(str+i))) {
            *(str+i) = tolower(*(str+i));
            i++;
        } else {
            // Remove non-alphanumeric character
            memmove(str+i, str+i+1, strlen(str)-i-1);
            i--;
        }
    }
}

// Function to check if a string is a palindrome
int is_palindrome(char* str) {
    int i = 0;
    int j = strlen(str)-1;
    while (i < j) {
        if (*(str+i)!= *(str+j)) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove newline character from input
    int len = strlen(input);
    if (len > 0 && input[len-1] == '\n') {
        input[len-1] = '\0';
    }

    // Clean input string
    clean_string(input);

    // Check if input string is a palindrome
    if (is_palindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}