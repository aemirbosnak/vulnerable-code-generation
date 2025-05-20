//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: Cryptic
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    char *str;
    int len;
} string_t;

int is_palindrome(string_t str);

int main(int argc, char **argv) {
    if (argc <= 1) {
        printf("Usage: %s <string>\n", argv[0]);
        exit(1);
    }

    string_t input_str = {.str = argv[1],.len = strlen(argv[1])};

    if (is_palindrome(input_str)) {
        printf("%s is a palindrome.\n", argv[1]);
    } else {
        printf("%s is not a palindrome.\n", argv[1]);
    }

    return 0;
}

int is_palindrome(string_t str) {
    int i = 0, j = str.len - 1;

    while (i < j) {
        if (!isalnum(str.str[i])) {
            i++;
        } else if (!isalnum(str.str[j])) {
            j--;
        } else if (tolower(str.str[i])!= tolower(str.str[j])) {
            return FALSE;
        } else {
            i++;
            j--;
        }
    }

    return TRUE;
}