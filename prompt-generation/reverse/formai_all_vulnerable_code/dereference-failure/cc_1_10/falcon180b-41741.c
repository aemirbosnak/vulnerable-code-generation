//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000000
#define MAX_CHARS 1000

typedef struct {
    int size;
    char *data;
} String;

String *create_string(int size) {
    String *string = (String *) malloc(sizeof(String));
    string->size = size;
    string->data = (char *) malloc(sizeof(char) * (size + 1));
    string->data[0] = '\0';
    return string;
}

void destroy_string(String *string) {
    free(string->data);
    free(string);
}

void append_string(String *string, char *data) {
    int new_size = string->size + strlen(data);
    string->data = (char *) realloc(string->data, sizeof(char) * (new_size + 1));
    strcat(string->data, data);
    string->size = new_size;
}

void clear_string(String *string) {
    string->size = 0;
    string->data[0] = '\0';
}

int get_string_size(String *string) {
    return string->size;
}

char *get_string_data(String *string) {
    return string->data;
}

int main() {
    String *string = create_string(0);
    int size = 0;
    char *data = "Hello, world!";
    while (size < MAX_SIZE) {
        append_string(string, data);
        size += strlen(data);
    }
    printf("String size: %d\n", size);
    printf("String data: %s\n", get_string_data(string));
    destroy_string(string);
    return 0;
}