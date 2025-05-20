//Falcon-180B DATASET v1.0 Category: Memory management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define WORD_SIZE 4

typedef struct {
    int size;
    int capacity;
    char *data;
} String;

String *createString() {
    String *s = (String *)malloc(sizeof(String));
    s->size = 0;
    s->capacity = MAX_SIZE;
    s->data = (char *)malloc(s->capacity * WORD_SIZE);
    return s;
}

void deleteString(String *s) {
    free(s->data);
    free(s);
}

void stringAppend(String *s, char c) {
    if (s->size >= s->capacity) {
        s->capacity *= 2;
        s->data = (char *)realloc(s->data, s->capacity * WORD_SIZE);
    }
    s->data[s->size++] = c;
}

void stringAppendString(String *s, char *str) {
    int len = strlen(str);
    if (s->size + len >= s->capacity) {
        s->capacity *= 2;
        s->data = (char *)realloc(s->data, s->capacity * WORD_SIZE);
    }
    memcpy(&s->data[s->size], str, len * WORD_SIZE);
    s->size += len;
}

void stringPrint(String *s) {
    printf("%s", s->data);
}

int main() {
    String *s = createString();
    stringAppend(s, 'h');
    stringAppend(s, 'e');
    stringAppend(s, 'l');
    stringAppend(s, 'l');
    stringAppend(s, 'o');
    stringAppendString(s, ", world!");
    stringPrint(s);
    deleteString(s);
    return 0;
}