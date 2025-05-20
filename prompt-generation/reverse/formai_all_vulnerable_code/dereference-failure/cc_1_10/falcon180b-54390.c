//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: future-proof
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function to check if a string is a palindrome
int is_palindrome(char* str) {
    int length = strlen(str);
    char* reversed_str = malloc(MAX_LENGTH * sizeof(char));

    int i = 0, j = length - 1;
    while (i < j) {
        if (!isalnum(str[i])) {
            i++;
            continue;
        }
        if (!isalnum(str[j])) {
            j--;
            continue;
        }

        if (tolower(str[i])!= tolower(str[j])) {
            free(reversed_str);
            return 0;
        }

        reversed_str[i] = str[j];
        i++;
        j--;
    }

    free(reversed_str);
    return 1;
}

int main() {
    char input[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    if (is_palindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}