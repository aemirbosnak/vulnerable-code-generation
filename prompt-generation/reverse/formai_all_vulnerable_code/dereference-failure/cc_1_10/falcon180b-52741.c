//Falcon-180B DATASET v1.0 Category: Memory management ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *data;
    int size;
} String;

String *create_string(int size) {
    String *s = (String *) malloc(sizeof(String));
    s->data = (char *) malloc(size * sizeof(char));
    s->size = size;
    return s;
}

void destroy_string(String *s) {
    free(s->data);
    free(s);
}

void set_string(String *s, char *value) {
    strcpy(s->data, value);
}

char *get_string(String *s) {
    return s->data;
}

void resize_string(String *s, int new_size) {
    char *new_data = (char *) realloc(s->data, new_size * sizeof(char));
    if (new_data!= NULL) {
        s->data = new_data;
        s->size = new_size;
    }
}

int main() {
    String *s = create_string(10);
    set_string(s, "Hello, world!");
    printf("%s\n", get_string(s));

    resize_string(s, 20);
    set_string(s, "Lorem ipsum dolor sit amet.");
    printf("%s\n", get_string(s));

    destroy_string(s);
    return 0;
}