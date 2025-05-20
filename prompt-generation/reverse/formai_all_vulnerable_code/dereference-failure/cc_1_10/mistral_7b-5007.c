//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void reverse(char *str, int start, int end) {
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int isPalindrome(char *str, int length) {
    if (length <= 0)
        return 1;

    if (tolower(str[0]) != tolower(str[length - 1]))
        return 0;

    return isPalindrome(str + 1, length - 2);
}

int main(void) {
    char input[MAX_LENGTH];
    int length;

    printf("Enter a string: ");
    scanf("%s", input);

    length = strlen(input);

    // Reverse a copy of the input string
    char reversed[MAX_LENGTH];
    strcpy(reversed, input);
    reverse(reversed, 0, length - 1);

    if (isPalindrome(input, length)) {
        printf("The string '%s' is a palindrome.\n", input);
    } else {
        printf("The string '%s' is not a palindrome.\n", input);
    }

    if (strcmp(input, reversed) == 0) {
        printf("The given string '%s' is a mathematical palindrome.\n", input);
    } else {
        printf("The given string '%s' is not a mathematical palindrome.\n", input);
    }

    free(reversed);

    return 0;
}