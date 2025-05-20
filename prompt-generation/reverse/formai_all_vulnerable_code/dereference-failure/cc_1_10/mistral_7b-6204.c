//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 101
#define IS_ALPHANUM(x) ((x) >= 'A' && (x) <= 'Z' || (x) >= 'a' && (x) <= 'z' || (x) >= '0' && (x) <= '9')

typedef struct _palindrome {
    char str[MAX_LENGTH];
    int len;
} palindrome;

void reverse(char* str, int len) {
    int i = 0, j = len - 1;
    char temp;
    while (i < len / 2) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        ++i;
        --j;
    }
}

palindrome* create_palindrome(char* str) {
    int len = 0;
    while (str[len] != '\0') {
        ++len;
    }
    palindrome* p = (palindrome*) malloc(sizeof(palindrome));
    strncpy(p->str, str, len);
    p->len = len;
    return p;
}

int is_palindrome(palindrome* p) {
    int mid = p->len / 2;
    for (int i = 0; i < mid; ++i) {
        if (p->str[i] != p->str[p->len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", input);

    palindrome* p = create_palindrome(input);

    if (is_palindrome(p)) {
        printf("%s is a palindrome.\n", p->str);
    } else {
        printf("%s is not a palindrome.\n", p->str);
    }

    free(p);
    return 0;
}