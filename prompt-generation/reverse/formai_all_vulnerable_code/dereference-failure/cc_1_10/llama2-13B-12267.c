//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STR_LEN 1024
#define MAX_CHAR 0x10000

// Define a custom struct to hold the string and its manipulation history
typedef struct {
    char *str;
    size_t len;
    size_t cap;
    int dirty;
} str_t;

// Define some custom functions to manipulate the string
void str_init(str_t *s, const char *init_str) {
    s->str = (char *)malloc(sizeof(char) * (strlen(init_str) + 1));
    s->len = strlen(init_str);
    s->cap = s->len + 1;
    s->dirty = 0;
    strcpy(s->str, init_str);
}

void str_append(str_t *s, const char *append_str) {
    if (s->cap <= s->len + strlen(append_str)) {
        size_t new_cap = s->cap * 2;
        char *new_str = (char *)realloc(s->str, new_cap);
        if (!new_str) {
            perror("realloc failed");
            exit(EXIT_FAILURE);
        }
        s->str = new_str;
        s->cap = new_cap;
    }
    strcat(s->str, append_str);
    s->len += strlen(append_str);
    s->dirty = 1;
}

void str_insert(str_t *s, size_t pos, const char *insert_str) {
    if (pos > s->len) {
        printf("Invalid position %zu\n", pos);
        return;
    }
    size_t insert_len = strlen(insert_str);
    if (insert_len + pos > s->cap) {
        size_t new_cap = s->cap * 2;
        char *new_str = (char *)realloc(s->str, new_cap);
        if (!new_str) {
            perror("realloc failed");
            exit(EXIT_FAILURE);
        }
        s->str = new_str;
        s->cap = new_cap;
    }
    memmove(s->str + pos + insert_len, s->str + pos, s->len - pos);
    strcpy(s->str + pos, insert_str);
    s->len += insert_len;
    s->dirty = 1;
}

void str_delete(str_t *s, size_t pos, size_t len) {
    if (pos > s->len) {
        printf("Invalid position %zu\n", pos);
        return;
    }
    if (len > s->len - pos) {
        len = s->len - pos;
    }
    memmove(s->str + pos, s->str + pos + len, s->len - pos - len);
    s->len -= len;
    s->dirty = 1;
}

void str_print(str_t *s) {
    printf("%s\n", s->str);
}

int main() {
    str_t *str = malloc(sizeof(str_t));
    str_init(str, "Hello, world!");
    str_append(str, " Foo");
    str_insert(str, 5, " Bar");
    str_delete(str, 9, 4);
    str_print(str);
    free(str);
    return 0;
}