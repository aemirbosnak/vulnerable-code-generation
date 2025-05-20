//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 1000
typedef struct {
    int is_palindrome;
    char str[MAX_LEN];
} PalindromeChecker;
void reverse_string(char *str, int start, int end) {
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
void check_palindrome(PalindromeChecker *checker, char *str) {
    int len = strlen(str);
    if (len <= 1) {
        checker->is_palindrome = 1;
        strcpy(checker->str, str);
        return;
    }
    checker->is_palindrome = 0;
    reverse_string(checker->str, 0, len - 1);
    int i = 0;
    for (; i < len / 2; i++) {
        if (str[i] != checker->str[len - i - 1]) {
            return;
        }
    }
    checker->is_palindrome = 1;
    strcpy(checker->str, str);
}
int main(int argc, char *argv[]) {
    PalindromeChecker checker;
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }
    check_palindrome(&checker, argv[1]);
    if (checker.is_palindrome) {
        printf("%s is a palindrome.\n", checker.str);
    } else {
        printf("%s is not a palindrome.\n", checker.str);
    }
    return 0;
}