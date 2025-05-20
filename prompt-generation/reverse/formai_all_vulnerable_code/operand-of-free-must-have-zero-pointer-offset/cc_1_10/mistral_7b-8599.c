//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 10
#define STRING_SIZE 50

typedef struct {
    char data[STRING_SIZE];
} String;

typedef struct {
    String strings[MAX_STRINGS];
    int count;
} Array;

void init_array(Array *array) {
    array->count = 0;
}

int add_string(Array *array, const char *str) {
    if (array->count == MAX_STRINGS) {
        printf("Error: Array is full.\n");
        return 0;
    }

    size_t len = strlen(str) + 1;
    String *new_string = malloc(sizeof(String) + len);

    if (new_string == NULL) {
        printf("Error: Failed to allocate memory for new string.\n");
        return 0;
    }

    memcpy(new_string->data, str, len);
    array->strings[array->count] = *new_string;
    array->count++;

    return 1;
}

void free_array(Array *array) {
    for (int i = 0; i < array->count; i++) {
        free(array->strings + i);
    }
}

int main() {
    Array strings_array;
    init_array(&strings_array);

    if (add_string(&strings_array, "Hello")) {
        if (add_string(&strings_array, "World")) {
            if (add_string(&strings_array, "!")) {
                for (int i = 0; i < strings_array.count; i++) {
                    printf("%s\n", strings_array.strings[i].data);
                }
                free_array(&strings_array);
            }
        }
    }

    return 0;
}