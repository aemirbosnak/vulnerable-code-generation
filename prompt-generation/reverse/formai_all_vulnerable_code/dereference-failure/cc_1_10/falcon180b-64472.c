//Falcon-180B DATASET v1.0 Category: Memory management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int size;
    char *data;
} String;

String *create_string(int size) {
    String *s = malloc(sizeof(String));
    if (s == NULL) {
        printf("Failed to allocate memory for string.\n");
        exit(1);
    }
    s->size = size;
    s->data = malloc(size * sizeof(char));
    if (s->data == NULL) {
        printf("Failed to allocate memory for string data.\n");
        exit(1);
    }
    return s;
}

void destroy_string(String *s) {
    free(s->data);
    free(s);
}

void append_string(String *s1, const char *s2) {
    int new_size = s1->size + strlen(s2) + 1;
    s1->data = realloc(s1->data, new_size * sizeof(char));
    if (s1->data == NULL) {
        printf("Failed to reallocate memory for string data.\n");
        exit(1);
    }
    strcat(s1->data, s2);
    s1->size = new_size;
}

int main() {
    String *s1 = create_string(MAX_SIZE);
    String *s2 = create_string(MAX_SIZE);
    strcpy(s1->data, "Hello, world!");
    strcpy(s2->data, "How are you?");
    append_string(s1, ", my friend!");
    append_string(s2, "?");
    printf("%s\n", s1->data);
    printf("%s\n", s2->data);
    destroy_string(s1);
    destroy_string(s2);
    return 0;
}