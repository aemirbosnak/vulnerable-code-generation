//Falcon-180B DATASET v1.0 Category: Memory management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

typedef struct {
    char *str;
    size_t len;
} String;

void init_string(String *s) {
    s->str = NULL;
    s->len = 0;
}

void set_string(String *s, const char *str) {
    if (s->str!= NULL) {
        free(s->str);
    }
    s->len = strlen(str);
    s->str = malloc(s->len + 1);
    strcpy(s->str, str);
}

void print_string(const String *s) {
    printf("%.*s\n", s->len, s->str);
}

void free_string(String *s) {
    if (s->str!= NULL) {
        free(s->str);
        s->str = NULL;
        s->len = 0;
    }
}

int main() {
    String s1, s2;
    init_string(&s1);
    init_string(&s2);

    set_string(&s1, "Hello, world!");
    print_string(&s1);

    set_string(&s2, "How are you?");
    print_string(&s2);

    free_string(&s1);
    free_string(&s2);

    return 0;
}