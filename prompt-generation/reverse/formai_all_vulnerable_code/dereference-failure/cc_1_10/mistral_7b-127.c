//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int length;
    char *str;
} String;

void toLowerCase(String *str) {
    for (int i = 0; str->str[i]; i++) {
        str->str[i] = tolower(str->str[i]);
    }
}

int isPalindrome(String str) {
    int left = 0, right = str.length - 1;
    while (left < right) {
        if (str.str[left] != str.str[right]) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

void inputString(String *str) {
    fputs("Enter a string: ", stdout);
    fgets(str->str, 100, stdin);
    str->length = strlen(str->str);
    toLowerCase(str);
}

int main() {
    String input;
    int result;

    inputString(&input);
    result = isPalindrome(input);

    if (result) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    free(input.str);
    return 0;
}