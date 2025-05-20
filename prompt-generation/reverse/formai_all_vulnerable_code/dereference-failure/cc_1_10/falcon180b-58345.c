//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    char *data;
    int size;
    int capacity;
} String;

void init_string(String *str) {
    str->data = (char *)malloc(sizeof(char) * 1);
    str->size = 0;
    str->capacity = 1;
}

void free_string(String *str) {
    free(str->data);
    str->data = NULL;
    str->size = 0;
    str->capacity = 0;
}

void append_string(String *str, const char *data, int len) {
    int new_size = str->size + len;
    if (new_size > str->capacity) {
        str->capacity = (new_size + 1) * 2;
        str->data = (char *)realloc(str->data, sizeof(char) * str->capacity);
    }
    memcpy(str->data + str->size, data, len);
    str->size = new_size;
}

void reverse_string(String *str) {
    char *start = str->data;
    char *end = str->data + str->size - 1;
    while (start < end) {
        char tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }
}

int main() {
    String s;
    init_string(&s);
    char input[MAX_SIZE];
    int len;
    while (fgets(input, MAX_SIZE, stdin)) {
        len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[--len] = '\0';
        }
        append_string(&s, input, len);
    }
    reverse_string(&s);
    printf("%s", s.data);
    free_string(&s);
    return 0;
}