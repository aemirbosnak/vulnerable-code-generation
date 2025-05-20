//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include <stdlib.h>
#include <stdio.h>

typedef struct bucket_node {
    int value;
    struct bucket_node *next;
} bucket_node;

typedef struct bucket {
    bucket_node *head;
    bucket_node *tail;
} bucket;

void bucket_sort(int *arr, int len) {
    int max = arr[0];
    for (int i = 1; i < len; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int num_buckets = max + 1;
    bucket *buckets = malloc(sizeof(bucket) * num_buckets);
    for (int i = 0; i < num_buckets; i++) {
        buckets[i].head = NULL;
        buckets[i].tail = NULL;
    }

    for (int i = 0; i < len; i++) {
        int bucket_index = arr[i];
        bucket_node *new_node = malloc(sizeof(bucket_node));
        new_node->value = arr[i];
        new_node->next = NULL;

        if (buckets[bucket_index].head == NULL) {
            buckets[bucket_index].head = new_node;
            buckets[bucket_index].tail = new_node;
        } else {
            buckets[bucket_index].tail->next = new_node;
            buckets[bucket_index].tail = new_node;
        }
    }

    int sorted_index = 0;
    for (int i = 0; i < num_buckets; i++) {
        bucket_node *current = buckets[i].head;
        while (current != NULL) {
            arr[sorted_index++] = current->value;
            current = current->next;
        }
    }

    free(buckets);
}

int main() {
    int arr[] = {5, 3, 1, 7, 4, 1, 2, 8, 6};
    int len = sizeof(arr) / sizeof(arr[0]);

    bucket_sort(arr, len);

    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}