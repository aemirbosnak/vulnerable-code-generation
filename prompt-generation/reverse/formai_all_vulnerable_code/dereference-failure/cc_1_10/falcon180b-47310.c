//Falcon-180B DATASET v1.0 Category: Memory management ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define INIT_SIZE 10

typedef struct {
    char *data;
    int size;
    int capacity;
} String;

void init_string(String *s) {
    s->data = (char *) malloc(INIT_SIZE * sizeof(char));
    s->size = 0;
    s->capacity = INIT_SIZE;
}

void resize_string(String *s) {
    s->capacity *= 2;
    s->data = (char *) realloc(s->data, s->capacity * sizeof(char));
}

void append_string(String *s, char c) {
    if (s->size == s->capacity) {
        resize_string(s);
    }
    s->data[s->size++] = c;
    s->data[s->size] = '\0';
}

int main() {
    String s1, s2;
    init_string(&s1);
    init_string(&s2);

    append_string(&s1, 'R');
    append_string(&s1, 'o');
    append_string(&s1,'s');
    append_string(&s1, 'e');
    append_string(&s1, '\0');

    append_string(&s2, 'L');
    append_string(&s2, 'o');
    append_string(&s2, 'v');
    append_string(&s2, 'e');
    append_string(&s2, '\0');

    int size = strlen(s1.data) + strlen(s2.data) + 1;
    char *result = (char *) malloc(size * sizeof(char));
    strcpy(result, s1.data);
    strcat(result, s2.data);

    printf("%s\n", result);

    free(result);
    free(s1.data);
    free(s2.data);

    return 0;
}