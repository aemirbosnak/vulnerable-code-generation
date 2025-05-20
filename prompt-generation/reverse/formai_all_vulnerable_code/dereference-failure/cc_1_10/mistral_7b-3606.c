//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: Cryptic
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    if (str[0] != str[length - 1])
        return 0;
    return isPalindrome(str + 1, length - 2);
}

void encrypt(char *str) {
    int i, j, len;
    char temp;

    len = strlen(str);
    for (i = 0, j = len - 1; i < len / 2; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    if (len % 2 == 1)
        str[len / 2] ^= 0x2A; // XOR with '*' for odd-length palindromes
}

int main(int argc, char *argv[]) {
    char str[MAX_LENGTH];

    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    strcpy(str, argv[1]);

    // Check if the given string is a palindrome
    if (isPalindrome(str, strlen(str))) {
        printf("%s is a palindrome.\n", str);

        // If it's a palindrome, encrypt it in place and print the result
        encrypt(str);
        printf("Encrypted palindrome: %s\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}