//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <crypt.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>
#include <float.h>
#include <inttypes.h>
#include <stdbool.h>

#define STRING_MAX 1024
#define STRING_SEP ','

struct string {
    char *ptr;
    size_t len;
};

void string_add(struct string *s, const char *str) {
    size_t len = strlen(str);
    if (s->len + len >= STRING_MAX) {
        s->ptr = realloc(s->ptr, STRING_MAX * 2);
        s->len *= 2;
    }
    memcpy(s->ptr + s->len, str, len);
    s->len += len;
}

void string_insert(struct string *s, size_t pos, const char *str) {
    size_t len = strlen(str);
    if (pos >= s->len) {
        s->ptr = realloc(s->ptr, s->len + len + 1);
        memmove(s->ptr + pos + len, s->ptr + pos, s->len - pos + 1);
        s->len += len;
    } else {
        memmove(s->ptr + pos + len, s->ptr + pos, s->len - pos + 1);
        s->len += len;
    }
    memcpy(s->ptr + pos, str, len);
}

void string_remove(struct string *s, size_t pos, size_t len) {
    if (pos >= s->len) {
        printf("Index %zu is out of bounds\n", pos);
        return;
    }
    if (len > s->len - pos) {
        len = s->len - pos;
    }
    memmove(s->ptr + pos, s->ptr + pos + len, s->len - pos - len + 1);
    s->len -= len;
}

int main() {
    struct string s;
    s.ptr = malloc(STRING_MAX);
    s.len = 0;

    string_add(&s, "Hello, ");
    string_add(&s, "world!");
    string_insert(&s, 5, "Ahoy!");
    string_remove(&s, 8, 5);

    printf("Original string: %s\n", s.ptr);
    printf("After inserting 'Ahoy!': %s\n", s.ptr);
    printf("After removing 'world!': %s\n", s.ptr);

    return 0;
}