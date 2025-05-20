//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int value;
    char *name;
} element_t;

typedef struct {
    element_t *array;
    int size;
} array_t;

void insert_element(array_t *array, element_t element) {
    if (array->size >= array->size) {
        array->size *= 2;
        array->array = realloc(array->array, array->size * sizeof(element_t));
    }
    array->array[array->size++] = element;
}

element_t *find_element_by_value(array_t *array, int value) {
    for (int i = 0; i < array->size; i++) {
        if (array->array[i].value == value) {
            return &array->array[i];
        }
    }
    return NULL;
}

element_t *find_element_by_name(array_t *array, char *name) {
    for (int i = 0; i < array->size; i++) {
        if (strcmp(array->array[i].name, name) == 0) {
            return &array->array[i];
        }
    }
    return NULL;
}

int main() {
    array_t array;
    array.size = 0;
    array.array = NULL;

    insert_element(&array, (element_t) { .value = 1, .name = "one" });
    insert_element(&array, (element_t) { .value = 2, .name = "two" });
    insert_element(&array, (element_t) { .value = 3, .name = "three" });

    element_t *element = find_element_by_value(&array, 2);
    if (element) {
        printf("Found element with value %d and name %s\n", element->value, element->name);
    } else {
        printf("Element not found\n");
    }

    element = find_element_by_name(&array, "three");
    if (element) {
        printf("Found element with value %d and name %s\n", element->value, element->name);
    } else {
        printf("Element not found\n");
    }

    return 0;
}