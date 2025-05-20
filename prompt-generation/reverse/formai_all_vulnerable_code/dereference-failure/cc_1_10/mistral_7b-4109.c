//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct String {
    char *data;
    size_t len;
} String;

String *new_string(const char *src) {
    String *str = malloc(sizeof(String));
    if (!str) return NULL;
    size_t size = strlen(src) + 1;
    str->data = malloc(size);
    if (!str->data) {
        free(str);
        return NULL;
    }
    str->len = size;
    strncpy(str->data, src, size);
    return str;
}

void append(String *dest, const String *src) {
    size_t dest_len = dest->len;
    size_t src_len = src->len;
    size_t new_size = dest_len + src_len + 1;
    dest->data = realloc(dest->data, new_size);
    if (!dest->data) {
        free(dest);
        free(src->data);
        return;
    }
    memcpy(dest->data + dest_len, src->data, src_len);
    dest->len = new_size;
}

void concat(String **strings, size_t count) {
    if (!strings || !count) return;
    String *result = new_string("");
    for (size_t i = 0; i < count; i++) {
        append(result, strings[i]);
        free(strings[i]);
    }
    printf("Result: %s\n", result->data);
    free(result);
}

int main() {
    const char *strings[] = { "Hello, ", "world!", "This is a", "string", "manipulation", "example" };
    concat(strings, sizeof(strings) / sizeof(strings[0]));
    return 0;
}