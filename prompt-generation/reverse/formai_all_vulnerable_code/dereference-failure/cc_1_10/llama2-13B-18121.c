//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024
#define CHAR_ARRAY_SIZE 10

typedef struct {
    char *array;
    int length;
} char_array;

void init_char_array(char_array *array) {
    array->array = (char *)malloc(MAX_LENGTH * sizeof(char));
    array->length = 0;
}

void add_char(char_array *array, char c) {
    if (array->length >= MAX_LENGTH) {
        printf("Oops! Array is full, cannot add %c\n", c);
        return;
    }

    array->array[array->length] = c;
    array->length++;
}

void print_char_array(char_array *array) {
    printf("Array: %s\n", array->array);
}

int main() {
    char_array char_array_1;
    char_array char_array_2;

    init_char_array(&char_array_1);
    init_char_array(&char_array_2);

    add_char(&char_array_1, 'a');
    add_char(&char_array_1, 'b');
    add_char(&char_array_1, 'c');

    add_char(&char_array_2, 'd');
    add_char(&char_array_2, 'e');
    add_char(&char_array_2, 'f');

    print_char_array(&char_array_1);
    print_char_array(&char_array_2);

    char_array_1.array[0] = 'g';
    char_array_1.length++;

    print_char_array(&char_array_1);

    return 0;
}