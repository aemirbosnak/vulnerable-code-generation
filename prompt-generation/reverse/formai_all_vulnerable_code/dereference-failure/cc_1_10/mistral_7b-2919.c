//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

void reverse(char* str, int start, int end) {
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int isPalindrome(char* str) {
    int len = strlen(str);
    if (len < 2)
        return 1;

    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i]) != tolower(str[len - i - 1]))
            return 0;
    }

    return 1;
}

int main() {
    char str[MAX_SIZE];

    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Is '%s' a palindrome? ", str);

    if (isPalindrome(str))
        printf("Yes\n");
    else {
        int len = strlen(str);
        char revStr[MAX_SIZE];

        printf("Let's check if '%s' is a palindrome after removing non-alphanumeric characters.\n");

        for (int i = 0; i < len; i++) {
            if (isalpha(str[i]) || isdigit(str[i])) {
                revStr[i] = str[len - i - 1];
                reverse(str, 0, i - 1);
                reverse(str, i, len - i - 1);
                reverse(revStr, 0, i);
            }
        }

        if (strcmp(str, revStr) == 0)
            printf("Yes, it's a palindrome after removing non-alphanumeric characters.\n");
        else
            printf("No, it's not a palindrome.\n");

        free(revStr);
    }

    return 0;
}