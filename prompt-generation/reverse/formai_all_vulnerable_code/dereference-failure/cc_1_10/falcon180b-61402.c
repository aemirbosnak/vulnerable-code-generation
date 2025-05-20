//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int isPalindrome(char *str) {
    int length = strlen(str);
    if (length == 0 || length > MAX_LENGTH) {
        return 0;
    }

    char *reverse = malloc(length + 1);
    if (reverse == NULL) {
        return 0;
    }

    int i = 0;
    int j = length - 1;
    while (i < j) {
        if (!isalnum(str[i])) {
            i++;
        } else if (!isalnum(str[j])) {
            j--;
        } else if (tolower(str[i])!= tolower(str[j])) {
            free(reverse);
            return 0;
        } else {
            reverse[i] = tolower(str[i]);
            reverse[j] = tolower(str[j]);
            i++;
            j--;
        }
    }

    if (i >= j) {
        reverse[i] = tolower(str[i]);
    }

    int k = 0;
    while (str[k] == reverse[k]) {
        k++;
    }

    free(reverse);
    return (k == length);
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}