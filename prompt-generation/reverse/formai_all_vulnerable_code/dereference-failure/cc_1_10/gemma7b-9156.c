//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUCKETS 10

typedef struct Bucket {
    int key;
    struct Bucket* next;
} Bucket;

void insert(Bucket** head, int key) {
    Bucket* new_bucket = malloc(sizeof(Bucket));
    new_bucket->key = key;
    new_bucket->next = NULL;

    if (*head == NULL) {
        *head = new_bucket;
    } else {
        (*head)->next = new_bucket;
    }
}

void bucket_sort(int* arr, int n) {
    int i, key, bucket_index;
    Bucket** buckets = malloc(MAX_BUCKETS * sizeof(Bucket*));

    for (i = 0; i < MAX_BUCKETS; i++) {
        buckets[i] = NULL;
    }

    for (i = 0; i < n; i++) {
        key = arr[i];
        bucket_index = key % MAX_BUCKETS;
        insert(buckets[bucket_index], key);
    }

    int j = 0;
    for (i = 0; i < MAX_BUCKETS; i++) {
        for (Bucket* bucket = buckets[i]; bucket; bucket = bucket->next) {
            arr[j++] = bucket->key;
        }
    }

    free(buckets);
}

int main() {
    int arr[] = {4, 3, 5, 2, 8, 9, 1, 7, 6};
    int n = sizeof(arr) / sizeof(int);

    bucket_sort(arr, n);

    printf("Sorted array:");
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }

    printf("\n");

    return 0;
}