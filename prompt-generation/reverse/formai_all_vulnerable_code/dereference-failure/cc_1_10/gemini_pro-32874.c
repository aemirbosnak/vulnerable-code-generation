//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define HAPPY_BUCKET_SIZE 10

typedef struct {
    int min;
    int max;
    int count;
    int *elements;
} bucket_t;

typedef struct {
    int size;
    bucket_t *buckets;
} bucket_array_t;

void create_buckets(bucket_array_t *buckets, int min, int max, int count) {
    buckets->size = count;
    buckets->buckets = malloc(sizeof(bucket_t) * count);
    for (int i = 0; i < count; i++) {
        buckets->buckets[i].min = min + (i * (max - min) / count);
        buckets->buckets[i].max = min + ((i + 1) * (max - min) / count) - 1;
        buckets->buckets[i].count = 0;
        buckets->buckets[i].elements = malloc(sizeof(int) * HAPPY_BUCKET_SIZE);
    }
}

void sort_elements(bucket_array_t *buckets, int *elements, int count) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < buckets->size; j++) {
            if (elements[i] >= buckets->buckets[j].min && elements[i] <= buckets->buckets[j].max) {
                if (buckets->buckets[j].count >= HAPPY_BUCKET_SIZE) {
                    buckets->buckets[j].elements = realloc(buckets->buckets[j].elements, sizeof(int) * (buckets->buckets[j].count + 1));
                }
                buckets->buckets[j].elements[buckets->buckets[j].count++] = elements[i];
                break;
            }
        }
    }
}

void merge_buckets(bucket_array_t *buckets, int *sorted, int count) {
    int index = 0;
    for (int i = 0; i < buckets->size; i++) {
        for (int j = 0; j < buckets->buckets[i].count; j++) {
            sorted[index++] = buckets->buckets[i].elements[j];
        }
    }
}

void print_elements(int *elements, int count) {
    printf("[");
    for (int i = 0; i < count; i++) {
        printf("%d, ", elements[i]);
    }
    printf("]\n");
}

int main() {
    int elements[] = {13, 5, 2, 7, 11, 23, 17, 9, 4, 14, 19, 8, 1, 6, 20, 10, 3, 12, 18, 15, 16};
    int count = sizeof(elements) / sizeof(elements[0]);

    int min = 1;
    int max = 23;
    int bucket_count = 5;

    bucket_array_t buckets;
    create_buckets(&buckets, min, max, bucket_count);
    sort_elements(&buckets, elements, count);
    merge_buckets(&buckets, elements, count);

    printf("Original elements: ");
    print_elements(elements, count);

    printf("Sorted elements using bucket sort: ");
    print_elements(elements, count);

    return 0;
}