//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUCKETS 10

typedef struct Bucket {
    int key;
    struct Bucket* next;
} Bucket;

Bucket* createBucket(int key) {
    Bucket* bucket = malloc(sizeof(Bucket));
    bucket->key = key;
    bucket->next = NULL;
    return bucket;
}

void insertIntoBucket(Bucket* bucket, int key) {
    Bucket* newBucket = createBucket(key);
    if (bucket == NULL) {
        bucket = newBucket;
    } else {
        bucket->next = newBucket;
        bucket = newBucket;
    }
}

void bucketSort(char* arr, int n) {
    Bucket** buckets = malloc(MAX_BUCKETS * sizeof(Bucket*));
    for (int i = 0; i < MAX_BUCKETS; i++) {
        buckets[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        int key = arr[i] - 'a';
        insertIntoBucket(buckets[key], key);
    }

    int i = 0;
    for (Bucket* bucket = buckets[0]; bucket; bucket = bucket->next) {
        arr[i++] = bucket->key + 'a';
    }

    free(buckets);
}

int main() {
    char arr[] = "abcba";
    int n = strlen(arr);

    bucketSort(arr, n);

    printf("%s", arr);

    return 0;
}