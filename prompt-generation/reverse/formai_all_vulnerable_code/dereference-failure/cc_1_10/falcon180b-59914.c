//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *str;
    int len;
} string_t;

void init_string(string_t *s) {
    s->str = (char *)malloc(MAX_SIZE * sizeof(char));
    s->len = 0;
}

void add_char(string_t *s, char c) {
    s->str[s->len++] = c;
    if (s->len >= MAX_SIZE) {
        s->str = (char *)realloc(s->str, MAX_SIZE * sizeof(char));
    }
}

void print_string(string_t s) {
    printf("%s\n", s.str);
}

int main() {
    string_t input, output;
    init_string(&input);
    init_string(&output);

    char c;
    while ((c = getchar())!= EOF) {
        add_char(&input, c);
    }

    int i = 0;
    while (i < input.len) {
        if (i == 0 || input.str[i]!= input.str[i - 1]) {
            add_char(&output, input.str[i]);
        }
        i++;
    }

    printf("Compressed string: ");
    print_string(output);

    return 0;
}