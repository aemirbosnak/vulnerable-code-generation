//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 5
#define MAX_VALUE 100

typedef struct node {
    int value;
    struct node *next;
} node_t;

void bucket_sort(int *arr, int n) {
    // Create an array of buckets
    node_t *buckets[BUCKET_SIZE];
    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = NULL;
    }

    // Insert elements into the buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i] / BUCKET_SIZE;
        node_t *new_node = (node_t *)malloc(sizeof(node_t));
        new_node->value = arr[i];
        new_node->next = NULL;

        if (buckets[bucket_index] == NULL) {
            buckets[bucket_index] = new_node;
        } else {
            node_t *current = buckets[bucket_index];
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    // Sort each bucket
    for (int i = 0; i < BUCKET_SIZE; i++) {
        node_t *current = buckets[i];
        while (current != NULL) {
            node_t *next = current->next;
            int j = i;
            node_t *prev = NULL;

            while (j > 0 && current->value < buckets[j - 1]->value) {
                prev = buckets[j - 1];
                j--;
            }

            if (prev == NULL) {
                buckets[j] = current;
            } else {
                prev->next = current;
            }

            current = next;
        }
    }

    // Extract elements from the buckets and put them back into the original array
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        node_t *current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->value;
            current = current->next;
        }
    }

    // Free the memory allocated for the buckets
    for (int i = 0; i < BUCKET_SIZE; i++) {
        node_t *current = buckets[i];
        while (current != NULL) {
            node_t *next = current->next;
            free(current);
            current = next;
        }
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucket_sort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}