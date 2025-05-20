//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: single-threaded
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

typedef struct {
    size_t size;
    size_t max_size;
    int * data;
} TArray;

TArray * ta_init(size_t max_size) {
    TArray * ta = malloc(sizeof(*ta));
    ta->data = malloc(sizeof(*ta->data) * max_size);
    ta->size = 0;
    ta->max_size = max_size;
    return ta;
}

void ta_free(TArray * ta) {
    free(ta->data);
    free(ta);
}

void ta_append(TArray * ta, int val) {
    if (ta->size == ta->max_size) {
        ta->max_size *= 2;
        ta->data = realloc(ta->data, sizeof(*ta->data) * ta->max_size);
    }
    ta->data[ta->size++] = val;
}

void ta_sort(TArray * ta) {
    int i, j, temp;
    for (i = 0; i < ta->size - 1; i++) {
        for (j = 0; j < ta->size - i - 1; j++) {
            if (ta->data[j] > ta->data[j + 1]) {
                temp = ta->data[j];
                ta->data[j] = ta->data[j + 1];
                ta->data[j + 1] = temp;
            }
        }
    }
}

void ta_print(TArray * ta) {
    int i;
    for (i = 0; i < ta->size; i++) {
        printf("%d ", ta->data[i]);
    }
    printf("\n");
}

int main() {
    TArray * ta = ta_init(10);
    ta_append(ta, 1);
    ta_append(ta, 3);
    ta_append(ta, 2);
    ta_append(ta, 5);
    ta_append(ta, 4);
    ta_print(ta);
    ta_sort(ta);
    ta_print(ta);
    ta_free(ta);
    return 0;
}