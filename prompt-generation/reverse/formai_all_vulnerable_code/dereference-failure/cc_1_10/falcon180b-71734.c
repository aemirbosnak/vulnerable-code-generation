//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int size;
    int capacity;
    char *data;
} String;

String *create_string() {
    String *s = (String *)malloc(sizeof(String));
    s->size = 0;
    s->capacity = MAX_SIZE;
    s->data = (char *)malloc(MAX_SIZE * sizeof(char));
    return s;
}

void destroy_string(String *s) {
    free(s->data);
    free(s);
}

void string_append(String *s, char c) {
    if (s->size == s->capacity) {
        s->capacity *= 2;
        s->data = (char *)realloc(s->data, s->capacity * sizeof(char));
    }
    s->data[s->size++] = c;
    s->data[s->size] = '\0';
}

void string_append_string(String *s, String *t) {
    int i = 0;
    while (i < t->size) {
        string_append(s, t->data[i]);
        i++;
    }
}

void string_prepend(String *s, char c) {
    if (s->size == s->capacity) {
        s->capacity *= 2;
        s->data = (char *)realloc(s->data, s->capacity * sizeof(char));
    }
    memmove(s->data + 1, s->data, s->size);
    s->data[0] = c;
    s->data[s->size++] = '\0';
}

void string_prepend_string(String *s, String *t) {
    int i = 0;
    while (i < t->size) {
        string_prepend(s, t->data[i]);
        i++;
    }
}

int main() {
    String *s1 = create_string();
    String *s2 = create_string();

    string_append_string(s1, s2);

    printf("s1: %s\n", s1->data);

    destroy_string(s1);
    destroy_string(s2);

    return 0;
}