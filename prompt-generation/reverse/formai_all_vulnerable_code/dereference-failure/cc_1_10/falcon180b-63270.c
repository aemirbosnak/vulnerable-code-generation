//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUES 100
#define MAX_RANGE 100

typedef struct {
    int *values;
    int num_values;
    int bucket_size;
} Bucket;

Bucket *create_bucket(int size) {
    Bucket *b = (Bucket *)malloc(sizeof(Bucket));
    if (b == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    b->values = (int *)malloc(size * sizeof(int));
    if (b->values == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    b->num_values = 0;
    b->bucket_size = size;
    return b;
}

void insert_value(Bucket *b, int value) {
    if (b->num_values >= b->bucket_size) {
        printf("Bucket is full\n");
        exit(1);
    }
    b->values[b->num_values++] = value;
}

void print_bucket(Bucket *b) {
    printf("Bucket: ");
    for (int i = 0; i < b->num_values; i++) {
        printf("%d ", b->values[i]);
    }
    printf("\n");
}

void bucket_sort(Bucket *b, int num_buckets, int range) {
    Bucket **buckets = (Bucket **)malloc(num_buckets * sizeof(Bucket *));
    if (buckets == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    for (int i = 0; i < num_buckets; i++) {
        buckets[i] = create_bucket(range);
    }
    for (int i = 0; i < b->num_values; i++) {
        int bucket_index = b->values[i] / range;
        insert_value(buckets[bucket_index], b->values[i]);
    }
    for (int i = 0; i < num_buckets; i++) {
        print_bucket(buckets[i]);
    }
    for (int i = 0; i < num_buckets; i++) {
        free(buckets[i]->values);
        free(buckets[i]);
    }
    free(buckets);
}

int main() {
    int num_values, range;
    printf("Enter number of values: ");
    scanf("%d", &num_values);
    printf("Enter range: ");
    scanf("%d", &range);
    Bucket *b = create_bucket(num_values);
    if (b == NULL) {
        return 1;
    }
    printf("Enter values:\n");
    for (int i = 0; i < num_values; i++) {
        scanf("%d", &b->values[i]);
    }
    bucket_sort(b, num_values, range);
    return 0;
}