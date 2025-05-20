//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct Palindrome {
    char *str;
    int len;
} Palindrome;

Palindrome reverse(Palindrome p) {
    int i;
    char *rev_str = malloc(p.len * sizeof(char));
    for (i = p.len - 1; i >= 0; i--) {
        rev_str[p.len - 1 - i] = p.str[i];
    }
    Palindrome rev_p = {rev_str, p.len};
    return rev_p;
}

int are_equal(char a, char b) {
    if (isalpha(a) && isalpha(b)) {
        return tolower(a) == tolower(b);
    }
    return a == b;
}

int is_palindrome(Palindrome p) {
    int mid = p.len / 2;
    if (p.len % 2 == 1) {
        mid++;
    }

    Palindrome left = p;
    Palindrome right = reverse(p);

    for (int i = 0; i < mid; i++) {
        if (!are_equal(left.str[i], right.str[p.len - 1 - i])) {
            free(right.str);
            return 0;
        }
        left.str++;
        right.str++;
    }

    free(right.str);
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string to check>\n", argv[0]);
        return 1;
    }

    Palindrome input = {argv[1], strlen(argv[1])};

    if (is_palindrome(input)) {
        printf("%s is a palindrome.\n", argv[1]);
    } else {
        printf("%s is not a palindrome.\n", argv[1]);
    }

    free(input.str);
    return 0;
}