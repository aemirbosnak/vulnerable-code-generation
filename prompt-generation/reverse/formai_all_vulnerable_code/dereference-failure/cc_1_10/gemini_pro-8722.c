//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define BUCKET_COUNT 10

typedef struct bucket {
    uint32_t count;
    uint32_t *values;
} bucket_t;

void insert_value(bucket_t *bucket, uint32_t value) {
    bucket->values[bucket->count++] = value;
}

void bucket_sort(uint32_t *array, uint32_t array_size) {
    bucket_t buckets[BUCKET_COUNT];

    for (uint32_t i = 0; i < BUCKET_COUNT; i++) {
        buckets[i].count = 0;
        buckets[i].values = malloc(array_size * sizeof(uint32_t));
    }

    for (uint32_t i = 0; i < array_size; i++) {
        uint32_t bucket_index = array[i] / BUCKET_COUNT;
        insert_value(&buckets[bucket_index], array[i]);
    }

    uint32_t sorted_index = 0;
    for (uint32_t i = 0; i < BUCKET_COUNT; i++) {
        for (uint32_t j = 0; j < buckets[i].count; j++) {
            array[sorted_index++] = buckets[i].values[j];
        }
        free(buckets[i].values);
    }
}

int main() {
    uint32_t array[] = {170, 45, 75, 90, 802, 24, 2, 66, 1, 290};
    uint32_t array_size = sizeof(array) / sizeof(array[0]);

    bucket_sort(array, array_size);

    for (uint32_t i = 0; i < array_size; i++) {
        printf("%u ", array[i]);
    }
    printf("\n");

    return 0;
}