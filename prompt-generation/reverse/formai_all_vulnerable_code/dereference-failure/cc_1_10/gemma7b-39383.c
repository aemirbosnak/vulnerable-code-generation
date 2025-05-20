//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUCKETS 10

typedef struct BucketNode {
    int key;
    struct BucketNode* next;
} BucketNode;

void insertBucket(BucketNode** head, int key) {
    BucketNode* newNode = malloc(sizeof(BucketNode));
    newNode->key = key;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void bucketSort(int arr[], int n) {
    BucketNode** buckets = malloc(MAX_BUCKETS * sizeof(BucketNode*));

    for (int i = 0; i < MAX_BUCKETS; i++) {
        buckets[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        insertBucket(buckets[arr[i]], arr[i]);
    }

    int i = 0;
    for (BucketNode* head = buckets[0]; head; head = head->next) {
        arr[i++] = head->key;
    }

    free(buckets);
}

int main() {
    int arr[] = {4, 3, 5, 2, 8, 9, 1, 7, 6, 0};
    int n = sizeof(arr) / sizeof(int);

    bucketSort(arr, n);

    printf("Sorted array:");
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }

    printf("\n");

    return 0;
}