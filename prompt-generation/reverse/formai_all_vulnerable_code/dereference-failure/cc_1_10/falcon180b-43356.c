//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    char *data;
    int size;
} String;

String *create_string() {
    String *s = malloc(sizeof(String));
    s->data = malloc(MAX_SIZE * sizeof(char));
    s->size = 0;
    return s;
}

void append_char(String *s, char c) {
    if (s->size >= MAX_SIZE) {
        printf("Error: String is full\n");
        return;
    }
    s->data[s->size++] = c;
    s->data[s->size] = '\0';
}

void append_string(String *s, const char *str) {
    int len = strlen(str);
    if (s->size + len >= MAX_SIZE) {
        printf("Error: String is full\n");
        return;
    }
    strcat(s->data, str);
    s->size += len;
}

void print_string(const String *s) {
    printf("%s", s->data);
}

int main() {
    String *s = create_string();
    append_string(s, "Hello, world!");
    print_string(s);
    append_char(s, '!');
    print_string(s);
    free(s->data);
    free(s);
    return 0;
}