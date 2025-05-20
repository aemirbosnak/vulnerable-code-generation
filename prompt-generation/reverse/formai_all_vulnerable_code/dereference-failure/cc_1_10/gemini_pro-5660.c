//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *str;
    int len;
} string_t;

void string_init(string_t *s, const char *str) {
    s->str = strdup(str);
    s->len = strlen(str);
}

void string_free(string_t *s) {
    free(s->str);
}

void string_upper(string_t *s) {
    for (int i = 0; i < s->len; i++) {
        s->str[i] = toupper(s->str[i]);
    }
}

void string_lower(string_t *s) {
    for (int i = 0; i < s->len; i++) {
        s->str[i] = tolower(s->str[i]);
    }
}

void string_trim(string_t *s) {
    while (s->len > 0 && isspace(s->str[s->len - 1])) {
        s->str[s->len - 1] = '\0';
        s->len--;
    }
    while (s->len > 0 && isspace(*s->str)) {
        s->str++;
        s->len--;
    }
}

void string_reverse(string_t *s) {
    for (int i = 0, j = s->len - 1; i < j; i++, j--) {
        char c = s->str[i];
        s->str[i] = s->str[j];
        s->str[j] = c;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s string\n", argv[0]);
        return EXIT_FAILURE;
    }

    string_t s;
    string_init(&s, argv[1]);

    printf("Original: %s\n", s.str);
    string_upper(&s);
    printf("Upper: %s\n", s.str);
    string_lower(&s);
    printf("Lower: %s\n", s.str);
    string_trim(&s);
    printf("Trimmed: %s\n", s.str);
    string_reverse(&s);
    printf("Reversed: %s\n", s.str);

    string_free(&s);

    return EXIT_SUCCESS;
}