//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int len;
    char *str;
} String;

String createString(char *input) {
    String str;
    str.len = strlen(input);
    str.str = malloc(str.len * sizeof(char));
    strcpy(str.str, input);
    return str;
}

int isPalindrome(String str) {
    int left = 0, right = str.len - 1;
    while (left < right) {
        if (str.str[left++] != str.str[right--]) {
            free(str.str);
            return 0;
        }
    }
    free(str.str);
    return 1;
}

void reverseString(String *str) {
    int len = (*str).len;
    char *ptr1 = (*str).str, *ptr2 = malloc(len * sizeof(char));

    for (int i = 0; i < len; ++i) {
        ptr2[len - i - 1] = ptr1[i];
    }

    free((*str).str);
    (*str).str = ptr2;
}

int checkPalindromeRecursive(String str, int start, int end) {
    if (start >= end) {
        return 1;
    }

    if (str.str[start++] != str.str[end--]) {
        return 0;
    }

    return checkPalindromeRecursive(str, start, end);
}

int main() {
    char input[100];
    String str;

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    str = createString(input);

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        reverseString(&str);
        if (isPalindrome(str)) {
            printf("The string is a palindrome after reversing.\n");
        } else {
            printf("The string is not a palindrome.\n");
        }
        free(str.str);
    }

    if (checkPalindromeRecursive(str, 0, str.len - 1)) {
        printf("The string is a palindrome recursively.\n");
    } else {
        printf("The string is not a palindrome recursively.\n");
    }

    free(str.str);
    return 0;
}