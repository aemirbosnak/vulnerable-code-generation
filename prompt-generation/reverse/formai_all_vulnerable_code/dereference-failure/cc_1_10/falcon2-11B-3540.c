//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int* data;
} array_t;

array_t* create_array(int size) {
    array_t* array = malloc(sizeof(array_t));
    array->size = size;
    array->data = malloc(size * sizeof(int));
    return array;
}

void destroy_array(array_t* array) {
    free(array->data);
    free(array);
}

void print_array(array_t* array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

void compress_array(array_t* array) {
    int compressed_size = 0;
    int prev = array->data[0];

    for (int i = 1; i < array->size; i++) {
        if (array->data[i] == prev) {
            compressed_size++;
        } else {
            compressed_size = 0;
            prev = array->data[i];
        }
    }

    array->data[array->size - 1] = -1;
    array->size = compressed_size;
}

int main() {
    int size = 10;
    array_t* array = create_array(size);
    for (int i = 0; i < size; i++) {
        array->data[i] = i;
    }

    print_array(array);
    compress_array(array);
    print_array(array);

    destroy_array(array);
    return 0;
}