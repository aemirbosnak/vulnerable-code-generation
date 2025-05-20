//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define BIAS 0x7f

typedef struct {
    float *data;
    size_t length;
} paranoid_array;

paranoid_array *paranoid_array_create(size_t length) {
    paranoid_array *array = malloc(sizeof(paranoid_array));
    array->data = malloc(sizeof(float) * length);
    array->length = length;
    return array;
}

void paranoid_array_destroy(paranoid_array *array) {
    free(array->data);
    free(array);
}

float paranoid_array_get(paranoid_array *array, size_t index) {
    if (index < 0 || index >= array->length) {
        fprintf(stderr, "Index %zu is out of bounds for array of length %zu\n", index, array->length);
        exit(EXIT_FAILURE);
    }
    return array->data[index];
}

void paranoid_array_set(paranoid_array *array, size_t index, float value) {
    if (index < 0 || index >= array->length) {
        fprintf(stderr, "Index %zu is out of bounds for array of length %zu\n", index, array->length);
        exit(EXIT_FAILURE);
    }
    array->data[index] = value;
}

paranoid_array *paranoid_array_copy(paranoid_array *array) {
    paranoid_array *copy = paranoid_array_create(array->length);
    memcpy(copy->data, array->data, sizeof(float) * array->length);
    return copy;
}

paranoid_array *paranoid_array_filter(paranoid_array *array, float *kernel, size_t kernel_length) {
    paranoid_array *filtered_array = paranoid_array_create(array->length);
    for (size_t i = 0; i < array->length; i++) {
        float sum = 0;
        for (size_t j = 0; j < kernel_length; j++) {
            if (i + j < array->length) {
                sum += array->data[i + j] * kernel[j];
            }
        }
        paranoid_array_set(filtered_array, i, sum);
    }
    return filtered_array;
}

int main(void) {
    paranoid_array *array = paranoid_array_create(10);
    for (size_t i = 0; i < array->length; i++) {
        paranoid_array_set(array, i, i + 1);
    }

    paranoid_array *filtered_array = paranoid_array_filter(array, (float[]){0.1, 0.2, 0.3, 0.4, 0.5}, 5);

    for (size_t i = 0; i < filtered_array->length; i++) {
        printf("%f\n", paranoid_array_get(filtered_array, i));
    }

    paranoid_array_destroy(array);
    paranoid_array_destroy(filtered_array);
    return 0;
}