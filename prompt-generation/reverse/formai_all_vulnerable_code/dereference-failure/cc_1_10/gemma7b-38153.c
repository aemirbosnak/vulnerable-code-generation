//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUCKETS 10

typedef struct bucket {
    int key;
    struct bucket* next;
} bucket;

bucket* createBucket(int key) {
    bucket* newBucket = (bucket*)malloc(sizeof(bucket));
    newBucket->key = key;
    newBucket->next = NULL;
    return newBucket;
}

void insertIntoBucket(bucket* bucketList, int key) {
    bucket* newBucket = createBucket(key);
    if (bucketList == NULL) {
        bucketList = newBucket;
    } else {
        bucket* currentBucket = bucketList;
        while (currentBucket->next) {
            currentBucket = currentBucket->next;
        }
        currentBucket->next = newBucket;
    }
}

void sortBuckets(bucket* bucketList) {
    int i, j, key, count = 0;
    bucket* currentBucket = bucketList;

    for (i = 0; i < MAX_BUCKETS; i++) {
        count = 0;
        for (j = 0; currentBucket; currentBucket = currentBucket->next) {
            if (currentBucket->key == i) {
                count++;
            }
        }
        printf("Bucket %d has %d elements\n", i, count);
    }
}

int main() {
    bucket* bucketList = NULL;
    insertIntoBucket(bucketList, 5);
    insertIntoBucket(bucketList, 3);
    insertIntoBucket(bucketList, 8);
    insertIntoBucket(bucketList, 2);
    insertIntoBucket(bucketList, 4);
    insertIntoBucket(bucketList, 6);
    sortBuckets(bucketList);

    return 0;
}