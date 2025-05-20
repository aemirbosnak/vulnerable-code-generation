//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 5

typedef struct node {
    int data;
    struct node *next;
} node;

void bucket_sort(int *arr, int n) {
    node **buckets = malloc(sizeof(node *) * BUCKET_SIZE);
    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i] / BUCKET_SIZE;
        node *new_node = malloc(sizeof(node));
        new_node->data = arr[i];
        new_node->next = buckets[bucket_index];
        buckets[bucket_index] = new_node;
    }

    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        node *current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->data;
            current = current->next;
        }
    }

    free(buckets);
}

int main() {
    int arr[] = {3, 1, 4, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucket_sort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}