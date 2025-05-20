//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define INIT_SIZE 10

typedef struct {
    char *data;
    int size;
    int capacity;
} String;

void init_string(String *s) {
    s->data = malloc(INIT_SIZE * sizeof(char));
    s->size = 0;
    s->capacity = INIT_SIZE;
}

void append_string(String *s, char c) {
    if (s->size == s->capacity) {
        s->capacity *= 2;
        s->data = realloc(s->data, s->capacity * sizeof(char));
    }
    s->data[s->size++] = c;
    s->data[s->size] = '\0';
}

void print_string(String s) {
    printf("%s", s.data);
}

void free_string(String *s) {
    free(s->data);
}

int main() {
    String s;
    init_string(&s);

    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        append_string(&s, 'a');
    }

    print_string(s);

    free_string(&s);

    return 0;
}