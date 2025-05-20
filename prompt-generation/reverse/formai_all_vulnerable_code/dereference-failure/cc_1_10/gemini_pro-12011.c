//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 5

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct bucket {
    node_t *head;
    node_t *tail;
} bucket_t;

void insert_node(bucket_t *bucket, int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (bucket->head == NULL) {
        bucket->head = new_node;
        bucket->tail = new_node;
    } else {
        bucket->tail->next = new_node;
        bucket->tail = new_node;
    }
}

void bucket_sort(int *arr, int size) {
    bucket_t *buckets[BUCKET_SIZE];

    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = (bucket_t *)malloc(sizeof(bucket_t));
        buckets[i]->head = NULL;
        buckets[i]->tail = NULL;
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / BUCKET_SIZE;
        insert_node(buckets[bucket_index], arr[i]);
    }

    for (int i = 0; i < BUCKET_SIZE; i++) {
        node_t *current_node = buckets[i]->head;
        while (current_node != NULL) {
            printf("%d ", current_node->data);
            current_node = current_node->next;
        }
    }

    printf("\n");
}

int main() {
    int arr[] = {3, 1, 4, 2, 5, 7, 6, 8, 9, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    bucket_sort(arr, size);

    return 0;
}