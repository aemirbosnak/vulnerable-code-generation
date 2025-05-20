//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: excited
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_STRING_SIZE 1024

typedef struct {
    char *str;
    int len;
} string_t;

void init_string(string_t *s) {
    s->str = malloc(MAX_STRING_SIZE);
    s->len = 0;
}

void append_char(string_t *s, char c) {
    if (s->len >= MAX_STRING_SIZE - 2) {
        printf("Error: string is too long!\n");
        exit(1);
    }
    s->str[s->len++] = c;
    s->str[s->len] = '\0';
}

void append_string(string_t *s, const char *str) {
    int len = strlen(str);
    if (s->len + len >= MAX_STRING_SIZE - 2) {
        printf("Error: string is too long!\n");
        exit(1);
    }
    strcat(s->str, str);
    s->len += len;
}

int is_palindrome(const char *str) {
    int i, j;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if (tolower(str[i])!= tolower(str[j])) {
            return 0;
        }
    }
    return 1;
}

void reverse_string(string_t *s) {
    char *p = s->str + s->len - 1;
    char *q = s->str;
    while (p > q) {
        char c = *p;
        *p-- = *q;
        *q++ = c;
    }
}

int main() {
    string_t s1, s2;
    init_string(&s1);
    init_string(&s2);

    append_string(&s1, "A man, a plan, a canal: Panama");
    printf("Original string: %s\n", s1.str);

    reverse_string(&s1);
    printf("Reversed string: %s\n", s1.str);

    if (is_palindrome(s1.str)) {
        printf("The string is a palindrome!\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}