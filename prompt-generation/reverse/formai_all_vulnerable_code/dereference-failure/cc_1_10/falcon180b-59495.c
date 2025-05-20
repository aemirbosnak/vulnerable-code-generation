//Falcon-180B DATASET v1.0 Category: Memory management ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define MAX_CHARS 100

typedef struct {
    char *data;
    int size;
} String;

String *newString(char *data, int size) {
    String *s = malloc(sizeof(String));
    s->data = malloc(size * sizeof(char));
    s->size = size;
    strncpy(s->data, data, size);
    s->data[size - 1] = '\0';
    return s;
}

void deleteString(String *s) {
    free(s->data);
    free(s);
}

char *getString(String *s) {
    return s->data;
}

void resizeString(String *s, int newSize) {
    char *newData = malloc(newSize * sizeof(char));
    strncpy(newData, s->data, s->size - 1);
    free(s->data);
    s->data = newData;
    s->size = newSize;
    s->data[newSize - 1] = '\0';
}

void appendString(String *s, char *data) {
    int newSize = s->size + strlen(data);
    resizeString(s, newSize);
    strcat(s->data, data);
}

int main() {
    String *s1 = newString("Hello", 5);
    printf("s1: %s\n", getString(s1));

    String *s2 = newString("World", 5);
    printf("s2: %s\n", getString(s2));

    appendString(s1, " ");
    appendString(s1, "World");
    printf("s1: %s\n", getString(s1));

    deleteString(s2);
    deleteString(s1);
    return 0;
}