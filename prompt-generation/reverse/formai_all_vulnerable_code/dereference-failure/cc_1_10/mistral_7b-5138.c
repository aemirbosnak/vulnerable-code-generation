//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int key;
    char data[50];
} Record;

void invasiveBucketSort(Record arr[], int n) {
    int i, j, bucket, index;
    Record *temp;
    int *count = (int *)calloc(MAX_SIZE, sizeof(int));

    for (i = 0; i < MAX_SIZE; i++) {
        count[i] = 0;
    }

    for (i = 0; i < n; i++) {
        bucket = arr[i].key % MAX_SIZE;
        count[bucket]++;
    }

    for (i = 1; i < MAX_SIZE; i++) {
        count[i] += count[i - 1];
    }

    temp = (Record *)calloc(n, sizeof(Record));

    for (i = n - 1; i >= 0; i--) {
        bucket = arr[i].key % MAX_SIZE;
        index = count[bucket] - 1;
        temp[index] = arr[i];
        count[bucket]--;
    }

    for (i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    free(temp);
    free(count);
}

int main() {
    Record arr[10];
    int i, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %s", &arr[i].key, arr[i].data);
    }

    printf("Before Sorting:\n");
    for (i = 0; i < n; i++) {
        printf("| %d | %s |\n", arr[i].key, arr[i].data);
    }

    invasiveBucketSort(arr, n);

    printf("After Sorting:\n");
    for (i = 0; i < n; i++) {
        printf("| %d | %s |\n", arr[i].key, arr[i].data);
    }

    return 0;
}