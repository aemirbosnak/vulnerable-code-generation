//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 5

typedef struct node {
    int data;
    struct node *next;
} node_t;

void bucket_sort(int *arr, int n) {
    // Create buckets
    node_t **buckets = malloc(sizeof(node_t *) * BUCKET_SIZE);
    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = NULL;
    }

    // Insert elements into buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i] / BUCKET_SIZE;
        node_t *new_node = malloc(sizeof(node_t));
        new_node->data = arr[i];
        new_node->next = buckets[bucket_index];
        buckets[bucket_index] = new_node;
    }

    // Sort elements in each bucket
    for (int i = 0; i < BUCKET_SIZE; i++) {
        node_t *current = buckets[i];
        while (current != NULL) {
            node_t *next = current->next;
            while (next != NULL) {
                if (current->data > next->data) {
                    int temp = current->data;
                    current->data = next->data;
                    next->data = temp;
                }
                next = next->next;
            }
            current = current->next;
        }
    }

    // Concatenate buckets
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        node_t *current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->data;
            current = current->next;
        }
    }

    // Free buckets
    for (int i = 0; i < BUCKET_SIZE; i++) {
        node_t *current = buckets[i];
        while (current != NULL) {
            node_t *next = current->next;
            free(current);
            current = next;
        }
    }
    free(buckets);
}

int main() {
    // Get input array
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using bucket sort
    bucket_sort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the array
    free(arr);

    return 0;
}