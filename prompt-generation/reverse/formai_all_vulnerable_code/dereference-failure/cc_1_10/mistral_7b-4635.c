//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 101

typedef struct Palindrome {
    char str[MAX_SIZE];
    int length;
    int is_palindrome;
} Palindrome;

void str_to_lower(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = tolower(str[i]);
        i++;
    }
}

int is_palindrome_helper(char *str, int start, int end) {
    if (start >= end) {
        return 1;
    }

    if (str[start] != str[end]) {
        return 0;
    }

    return is_palindrome_helper(str, start + 1, end - 1);
}

int is_palindrome(Palindrome *palindrome) {
    if (palindrome->length <= 0 || palindrome->length % 2 == 1) {
        palindrome->is_palindrome = 0;
        return 0;
    }

    str_to_lower(palindrome->str);

    palindrome->is_palindrome = is_palindrome_helper(palindrome->str, 0, palindrome->length - 1);

    return palindrome->is_palindrome;
}

void print_palindrome(Palindrome palindrome) {
    if (palindrome.is_palindrome) {
        printf("\"%s\" is a palindrome.\n", palindrome.str);
    } else {
        printf("\"%s\" is not a palindrome.\n", palindrome.str);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    Palindrome palindrome;
    strcpy(palindrome.str, argv[1]);
    palindrome.length = strlen(argv[1]);

    is_palindrome(&palindrome);

    print_palindrome(palindrome);

    return 0;
}