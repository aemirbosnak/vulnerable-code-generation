//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Define a single linked list node
typedef struct sll_node {
    int data;
    struct sll_node *next;
} sll_node_t;

// Bucket sort function
void bucket_sort(int arr[], int n, int bucket_count) {
    // Create an array of linked lists as buckets
    sll_node_t **buckets = malloc(bucket_count * sizeof(sll_node_t *));
    for (int i = 0; i < bucket_count; i++) {
        buckets[i] = NULL;
    }

    // Calculate the maximum and minimum elements in the array
    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    // Calculate the size of each bucket
    float range = (float) (max - min) / bucket_count;
    int bucket_size[bucket_count];
    for (int i = 0; i < bucket_count; i++) {
        bucket_size[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int index = (int) ((arr[i] - min) / range);
        bucket_size[index]++;
    }

    // Insert elements into the buckets
    for (int i = 0; i < n; i++) {
        int index = (int) ((arr[i] - min) / range);
        sll_node_t *node = malloc(sizeof(sll_node_t));
        node->data = arr[i];
        node->next = buckets[index];
        buckets[index] = node;
    }

    // Sort the elements in each bucket using insertion sort
    for (int i = 0; i < bucket_count; i++) {
        sll_node_t *head = buckets[i];
        for (int j = 1; j < bucket_size[i]; j++) {
            // Remove current node from list
            sll_node_t *prev = NULL, *current = head;
            for (int k = 0; k < j; k++) {
                prev = current;
                current = current->next;
            }
            prev->next = current->next;

            // Insert current node into sorted list
            prev = NULL, current = head;
            while (current != NULL && current->data < head->data) {
                prev = current;
                current = current->next;
            }
            head->next = prev->next;
            prev->next = head;
        }
        arr[i] = head->data;
        free(head);
    }

    // Free memory
    free(buckets);
}

// Test program
int main() {
    int arr[] = { 4, 7, 1, 3, 8, 5, 2, 6 };
    int n = sizeof(arr) / sizeof(int);
    int bucket_count = 3;
    bucket_sort(arr, n, bucket_count);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}