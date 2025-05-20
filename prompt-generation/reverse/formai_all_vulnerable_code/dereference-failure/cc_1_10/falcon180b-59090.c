//Falcon-180B DATASET v1.0 Category: Memory management ; Style: innovative
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

String *create_string() {
    String *s = (String *) malloc(sizeof(String));
    if (s == NULL) {
        printf("Error: Failed to allocate memory for string.\n");
        exit(1);
    }
    s->data = (char *) malloc(INIT_SIZE * sizeof(char));
    if (s->data == NULL) {
        printf("Error: Failed to allocate memory for string data.\n");
        exit(1);
    }
    s->size = 0;
    s->capacity = INIT_SIZE;
    return s;
}

void destroy_string(String *s) {
    free(s->data);
    free(s);
}

void string_append(String *s, const char *str) {
    int len = strlen(str);
    if (s->size + len >= s->capacity) {
        s->capacity *= 2;
        s->data = (char *) realloc(s->data, s->capacity * sizeof(char));
        if (s->data == NULL) {
            printf("Error: Failed to reallocate memory for string data.\n");
            exit(1);
        }
    }
    strcat(s->data, str);
    s->size += len;
}

void string_clear(String *s) {
    s->size = 0;
    s->data[0] = '\0';
}

int string_length(String *s) {
    return s->size;
}

char *string_data(String *s) {
    return s->data;
}

int main() {
    String *s = create_string();
    string_append(s, "Hello, world! ");
    string_append(s, "How are you today? ");
    printf("String length: %d\n", string_length(s));
    printf("String data: %s\n", string_data(s));
    string_clear(s);
    printf("String length after clear: %d\n", string_length(s));
    destroy_string(s);
    return 0;
}