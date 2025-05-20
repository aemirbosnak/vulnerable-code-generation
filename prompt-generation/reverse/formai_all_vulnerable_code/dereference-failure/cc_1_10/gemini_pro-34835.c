//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// A bucket is a linked list of integers.
typedef struct bucket {
    int value;
    struct bucket *next;
} bucket;

// A hash table is an array of buckets.
typedef struct hash_table {
    bucket **buckets;
    int size;
} hash_table;

// Create a new hash table.
hash_table *create_hash_table(int size) {
    hash_table *ht = malloc(sizeof(hash_table));
    ht->size = size;
    ht->buckets = malloc(sizeof(bucket *) * size);
    for (int i = 0; i < size; i++) {
        ht->buckets[i] = NULL;
    }
    return ht;
}

// Destroy a hash table.
void destroy_hash_table(hash_table *ht) {
    for (int i = 0; i < ht->size; i++) {
        bucket *b = ht->buckets[i];
        while (b != NULL) {
            bucket *next = b->next;
            free(b);
            b = next;
        }
    }
    free(ht->buckets);
    free(ht);
}

// Insert a value into a hash table.
void insert_value(hash_table *ht, int value) {
    int index = value % ht->size;
    bucket *b = ht->buckets[index];
    if (b == NULL) {
        b = malloc(sizeof(bucket));
        b->value = value;
        b->next = NULL;
        ht->buckets[index] = b;
    } else {
        while (b->next != NULL) {
            b = b->next;
        }
        b->next = malloc(sizeof(bucket));
        b->next->value = value;
        b->next->next = NULL;
    }
}

// Sort a list of integers using bucket sort.
void bucket_sort(int *arr, int size) {
    hash_table *ht = create_hash_table(size);
    for (int i = 0; i < size; i++) {
        insert_value(ht, arr[i]);
    }
    int index = 0;
    for (int i = 0; i < ht->size; i++) {
        bucket *b = ht->buckets[i];
        while (b != NULL) {
            arr[index++] = b->value;
            b = b->next;
        }
    }
    destroy_hash_table(ht);
}

int main() {
    int arr[] = {3, 1, 4, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    bucket_sort(arr, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}