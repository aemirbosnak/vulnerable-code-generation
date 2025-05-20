//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct String {
    char data[MAX_SIZE];
    int length;
} String;

void initString(String* str) {
    str->length = 0;
}

void appendChar(String* str, char c) {
    str->data[str->length++] = c;
}

int isPalindrome(String str) {
    int left = 0;
    int right = str.length - 1;

    while (left < right) {
        if (str.data[left++] != str.data[right--]) {
            return 0;
        }
    }

    return 1;
}

void printString(String str) {
    for (int i = 0; i < str.length; i++) {
        printf("%c", str.data[i]);
    }

    printf("\n");
}

int main(int argc, char* argv[]) {
    String inputStr;
    initString(&inputStr);

    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    for (int i = 0; i < argc - 1; i++) {
        appendChar(&inputStr, argv[i + 1][i]);
    }

    appendChar(&inputStr, '\0');

    if (isPalindrome(inputStr)) {
        printf("The given string is a palindrome.\n");
    } else {
        printf("The given string is not a palindrome.\n");
    }

    printString(inputStr);

    return 0;
}