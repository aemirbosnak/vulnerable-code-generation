//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: protected
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int isPalindrome(char *str);
void reverseString(char *str);

int main() {
    char input[MAX_SIZE];
    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline character

    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}

int isPalindrome(char *str) {
    int i, j;
    char *ptr;

    reverseString(str);

    ptr = str;
    while (*ptr) {
        if (*ptr!= *str) {
            return 0;
        }
        ptr++;
        str--;
    }

    return 1;
}

void reverseString(char *str) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}