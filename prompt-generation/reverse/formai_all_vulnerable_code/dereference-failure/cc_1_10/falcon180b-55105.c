//Falcon-180B DATASET v1.0 Category: Memory management ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int size;
    char *data;
} String;

String *create_string(int size) {
    String *s = (String *) malloc(sizeof(String));
    if (s == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    s->size = size;
    s->data = (char *) malloc(sizeof(char) * size);
    if (s->data == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    memset(s->data, '\0', size);
    return s;
}

void destroy_string(String *s) {
    free(s->data);
    free(s);
}

void append_string(String *s, char *str) {
    int new_size = s->size + strlen(str);
    char *new_data = (char *) realloc(s->data, sizeof(char) * new_size);
    if (new_data == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    s->data = new_data;
    s->size = new_size;
    strcat(s->data, str);
}

int main() {
    String *s1 = create_string(10);
    append_string(s1, "Hello");
    printf("%s\n", s1->data);
    append_string(s1, " world!");
    printf("%s\n", s1->data);
    destroy_string(s1);
    return 0;
}