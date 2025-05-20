//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    char *str;
    int len;
} String;

String *create_string(const char *str) {
    String *s = malloc(sizeof(String));
    s->str = strdup(str);
    s->len = strlen(str);
    return s;
}

void destroy_string(String *s) {
    free(s->str);
    free(s);
}

String *to_upper(String *s) {
    for (int i = 0; i < s->len; i++) {
        s->str[i] = toupper(s->str[i]);
    }
    return s;
}

String *to_lower(String *s) {
    for (int i = 0; i < s->len; i++) {
        s->str[i] = tolower(s->str[i]);
    }
    return s;
}

String *trim(String *s) {
    while (isspace(s->str[0])) {
        s->str++;
        s->len--;
    }
    while (isspace(s->str[s->len - 1])) {
        s->len--;
    }
    return s;
}

int main() {
    String *s = create_string("Hello, World!");
    s = to_upper(s);
    printf("%s\n", s->str);
    s = to_lower(s);
    printf("%s\n", s->str);
    s = trim(s);
    printf("%s\n", s->str);
    destroy_string(s);
    return 0;
}