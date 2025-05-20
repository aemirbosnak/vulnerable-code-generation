//Falcon-180B DATASET v1.0 Category: Memory management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int size;
    char *data;
} String;

String *create_string(int initial_size) {
    String *str = (String *) malloc(sizeof(String));
    str->size = initial_size;
    str->data = (char *) malloc(initial_size * sizeof(char));
    if (str->data == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    str->data[0] = '\0';
    return str;
}

void append_string(String *str, char *append) {
    int new_size = str->size + strlen(append) + 1;
    char *new_data = (char *) realloc(str->data, new_size * sizeof(char));
    if (new_data == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    str->data = new_data;
    str->size = new_size;
    strcat(str->data, append);
}

void delete_string(String *str) {
    free(str->data);
    free(str);
}

int main() {
    String *str1 = create_string(10);
    append_string(str1, "Hello, world!");
    printf("str1: %s\n", str1->data);

    String *str2 = create_string(20);
    append_string(str2, "This is a longer string.");
    printf("str2: %s\n", str2->data);

    delete_string(str1);
    delete_string(str2);

    return 0;
}