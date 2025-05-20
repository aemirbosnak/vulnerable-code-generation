//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MIN_SIZE 10
#define MAX_SIZE 1000

typedef struct {
    int key;
    void* data;
    size_t size;
} Element;

typedef struct {
    size_t size;
    size_t capacity;
    Element* array;
} Array;

Array* create_array(size_t initial_size) {
    Array* arr = calloc(1, sizeof(Array));
    assert(arr != NULL);

    arr->capacity = initial_size;
    arr->size = 0;
    arr->array = calloc(initial_size, sizeof(Element));
    assert(arr->array != NULL);

    return arr;
}

void resize_array(Array* arr) {
    size_t new_capacity = arr->capacity * 2;
    Element* new_array = calloc(new_capacity, sizeof(Element));
    assert(new_array != NULL);

    if (arr->size > 0) {
        memcpy(new_array, arr->array, arr->size * sizeof(Element));
    }

    free(arr->array);
    arr->array = new_array;
    arr->capacity = new_capacity;
}

int c_search(const Array* arr, int key, size_t size) {
    assert(arr != NULL);
    assert(size > 0 && size <= arr->size);

    int left = 0;
    int right = size - 1;

    while (left <= right) {
        size_t mid = (left + right) / 2;
        int mid_key = arr->array[mid].key;

        if (mid_key < key) {
            left = mid + 1;
        } else if (mid_key > key) {
            right = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}

void print_array(const Array* arr) {
    for (size_t i = 0; i < arr->size; ++i) {
        printf("(%d, %p, %zu)\n", arr->array[i].key, arr->array[i].data, arr->array[i].size);
    }
}

int main() {
    Array* arr = create_array(MIN_SIZE);

    arr->array[0] = (Element){1, "apple", 5};
    arr->array[1] = (Element){2, "banana", 6};
    arr->array[2] = (Element){3, "cherry", 7};

    size_t size = 3;

    int key = 3;
    int index = c_search(arr, key, size);

    if (index >= 0) {
        printf("Found key %d at index %d.\n", key, index);
    } else {
        printf("Key %d not found.\n", key);
    }

    print_array(arr);

    int new_key = 4;
    Element new_elem = {new_key, "orange", 6};

    if (arr->size >= arr->capacity) {
        resize_array(arr);
    }

    arr->array[arr->size++] = new_elem;

    print_array(arr);

    free(arr->array);
    free(arr);

    return 0;
}