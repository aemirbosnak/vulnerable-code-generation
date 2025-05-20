//Falcon-180B DATASET v1.0 Category: Memory management ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define CHUNK_SIZE 100

typedef struct {
    char *data;
    int size;
    int capacity;
} String;

void init_string(String *s) {
    s->data = malloc(CHUNK_SIZE * sizeof(char));
    s->size = 0;
    s->capacity = CHUNK_SIZE;
}

void resize_string(String *s) {
    s->capacity += CHUNK_SIZE;
    s->data = realloc(s->data, s->capacity * sizeof(char));
}

void append_string(String *s, char c) {
    if (s->size == s->capacity) {
        resize_string(s);
    }

    s->data[s->size] = c;
    s->size++;
}

void delete_string(String *s) {
    free(s->data);
}

int main() {
    String s;
    init_string(&s);

    char *romantic_text = "My love for you is like a circle, it has no end.\n";
    int length = strlen(romantic_text);

    for (int i = 0; i < length; i++) {
        append_string(&s, romantic_text[i]);
    }

    printf("%s", s.data);

    delete_string(&s);

    return 0;
}