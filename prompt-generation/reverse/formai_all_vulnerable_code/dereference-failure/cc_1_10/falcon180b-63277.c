//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *str;
    int len;
} String;

void init_string(String *s) {
    s->str = NULL;
    s->len = 0;
}

void append_string(String *s, const char *str) {
    int len = strlen(str);
    s->str = realloc(s->str, s->len + len + 1);
    strcat(s->str, str);
    s->len += len;
}

void reverse_string(String *s) {
    char *start = s->str;
    char *end = s->str + s->len - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int is_palindrome(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i])!= tolower(str[len - i - 1])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    String input, reversed;
    init_string(&input);
    init_string(&reversed);

    char ch;
    while ((ch = getchar())!= '\n') {
        if (isalnum(ch)) {
            append_string(&input, &ch);
        }
    }

    reverse_string(&input);

    if (is_palindrome(input.str)) {
        printf("Palindrome\n");
    } else {
        printf("Not palindrome\n");
    }

    return 0;
}