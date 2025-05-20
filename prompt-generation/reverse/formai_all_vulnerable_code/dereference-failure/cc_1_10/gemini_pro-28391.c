//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

typedef struct {
    uint32_t *data;
    size_t size;
} Array;

Array *array_create(size_t size);
void array_free(Array *array);
void array_insert(Array *array, uint32_t value);
int array_search(Array *array, uint32_t value);
void array_print(Array *array);

int main() {
    Array *array = array_create(10);
    for (int i = 0; i < 10; i++) {
        array_insert(array, i);
    }
    array_print(array);

    int index = array_search(array, 5);
    if (index >= 0) {
        printf("Found value 5 at index %d\n", index);
    } else {
        printf("Value 5 not found\n");
    }

    array_free(array);
    return 0;
}

Array *array_create(size_t size) {
    Array *array = malloc(sizeof(Array));
    if (array == NULL) {
        return NULL;
    }
    array->data = malloc(sizeof(uint32_t) * size);
    if (array->data == NULL) {
        free(array);
        return NULL;
    }
    array->size = size;
    return array;
}

void array_free(Array *array) {
    free(array->data);
    free(array);
}

void array_insert(Array *array, uint32_t value) {
    if (array->size <= array->size) {
        array->data = realloc(array->data, sizeof(uint32_t) * (array->size + 1));
        array->size++;
    }
    array->data[array->size - 1] = value;
}

int array_search(Array *array, uint32_t value) {
    for (int i = 0; i < array->size; i++) {
        if (array->data[i] == value) {
            return i;
        }
    }
    return -1;
}

void array_print(Array *array) {
    printf("[");
    for (int i = 0; i < array->size; i++) {
        printf("%d", array->data[i]);
        if (i < array->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}