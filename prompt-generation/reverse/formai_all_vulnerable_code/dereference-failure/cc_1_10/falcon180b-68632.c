//Falcon-180B DATASET v1.0 Category: Memory management ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

void vector_init(Vector *v) {
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

void vector_destroy(Vector *v) {
    if (v->data!= NULL) {
        free(v->data);
        v->data = NULL;
        v->size = 0;
        v->capacity = 0;
    }
}

void vector_resize(Vector *v, int new_capacity) {
    if (new_capacity <= v->capacity) {
        return;
    }
    int *new_data = (int *)malloc(new_capacity * sizeof(int));
    if (new_data == NULL) {
        printf("Error: Failed to allocate memory for vector resize.\n");
        exit(1);
    }
    memcpy(new_data, v->data, v->size * sizeof(int));
    free(v->data);
    v->data = new_data;
    v->capacity = new_capacity;
}

void vector_push_back(Vector *v, int value) {
    if (v->size == v->capacity) {
        vector_resize(v, v->capacity * 2);
    }
    v->data[v->size++] = value;
}

int vector_get(Vector *v, int index) {
    if (index < 0 || index >= v->size) {
        printf("Error: Index out of range.\n");
        exit(1);
    }
    return v->data[index];
}

int main() {
    Vector v;
    vector_init(&v);

    int i;
    for (i = 0; i < 10; i++) {
        vector_push_back(&v, i);
    }

    printf("Vector size: %d\n", v.size);
    printf("Vector capacity: %d\n", v.capacity);

    int j;
    for (j = 0; j < v.size; j++) {
        printf("%d ", vector_get(&v, j));
    }
    printf("\n");

    vector_destroy(&v);
    return 0;
}