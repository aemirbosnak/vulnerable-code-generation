//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int isPalindrome(char* str);
char* reverseString(char* str);

int main() {
    char input[MAX_SIZE];
    int i, j;

    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);

    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}

int isPalindrome(char* str) {
    int len = strlen(str);
    char* reversed = reverseString(str);

    for (int i = 0; i < len; i++) {
        if (str[i]!= reversed[i]) {
            return 0;
        }
    }

    return 1;
}

char* reverseString(char* str) {
    int len = strlen(str);
    char* reversed = malloc(len + 1);

    for (int i = 0; i < len; i++) {
        reversed[i] = str[len - 1 - i];
    }

    reversed[len] = '\0';

    return reversed;
}