//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

int isPalindrome(char* str);

int main() {
    char input[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    if (isPalindrome(input)) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }

    return 0;
}

int isPalindrome(char* str) {
    int i, j;
    char cleanStr[MAX_LENGTH];
    char* temp = strdup(str);

    for (i = 0, j = strlen(temp) - 1; i < j; i++, j--) {
        if (!isalnum(temp[i])) {
            i++;
        } else if (!isalnum(temp[j])) {
            j--;
        } else {
            cleanStr[i] = tolower(temp[i]);
            cleanStr[j] = tolower(temp[j]);
        }
    }

    cleanStr[i] = '\0';

    for (i = 0, j = strlen(cleanStr) - 1; i < j; i++, j--) {
        if (cleanStr[i]!= cleanStr[j]) {
            return 0;
        }
    }

    return 1;
}