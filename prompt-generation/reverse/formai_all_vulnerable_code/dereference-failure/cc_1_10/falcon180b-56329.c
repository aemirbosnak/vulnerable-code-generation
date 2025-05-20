//Falcon-180B DATASET v1.0 Category: Memory management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int size;
    char *data;
} String;

void init_string(String *s) {
    s->size = 0;
    s->data = (char*)malloc(MAX_SIZE * sizeof(char));
    if (s->data == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    s->data[0] = '\0';
}

void append_string(String *s, char *str) {
    int len = strlen(str);
    int new_size = s->size + len + 1;

    if (new_size > MAX_SIZE) {
        printf("Error: String too long\n");
        exit(1);
    }

    s->data = (char*)realloc(s->data, new_size * sizeof(char));
    if (s->data == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }

    strcat(s->data, str);
    s->size = new_size;
}

void print_string(String *s) {
    printf("%s\n", s->data);
}

int main() {
    String s;
    init_string(&s);

    append_string(&s, "Hello");
    print_string(&s);

    append_string(&s, " world!");
    print_string(&s);

    free(s.data);
    return 0;
}