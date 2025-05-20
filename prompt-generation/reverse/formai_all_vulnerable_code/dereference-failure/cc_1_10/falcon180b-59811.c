//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

int isPalindrome(char *str);

int main(int argc, char **argv) {
    char input[MAX_LENGTH];

    printf("Enter a string to check if it is a palindrome: ");
    fgets(input, MAX_LENGTH, stdin);

    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}

int isPalindrome(char *str) {
    int length = strlen(str);
    char *reverse = malloc(length * sizeof(char));
    int i, j;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        if (!isalnum(str[i])) {
            i++;
        }
        if (!isalnum(str[j])) {
            j--;
        }
        if (tolower(str[i])!= tolower(str[j])) {
            free(reverse);
            return 0;
        }
        reverse[i] = str[j];
    }

    if (tolower(reverse[length - 1])!= tolower(reverse[0])) {
        free(reverse);
        return 0;
    }

    free(reverse);
    return 1;
}