//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 5

typedef struct node {
    int data;
    struct node *next;
} node_t;

void insertion_sort(node_t **head) {
    node_t *current = *head;
    node_t *previous = NULL;

    while (current != NULL) {
        node_t *next = current->next;
        if (previous != NULL && current->data < previous->data) {
            if (previous == *head) {
                *head = current;
            } else {
                previous->next = current->next;
            }
            current->next = previous;
            previous = current;
            current = next;
        } else {
            previous = current;
            current = next;
        }
    }
}

void bucket_sort(int *input, int size) {
    node_t **buckets = malloc(sizeof(node_t *) * BUCKET_SIZE);
    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = NULL;
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = input[i] / BUCKET_SIZE;
        node_t *new_node = malloc(sizeof(node_t));
        new_node->data = input[i];
        new_node->next = buckets[bucket_index];
        buckets[bucket_index] = new_node;
    }

    for (int i = 0; i < BUCKET_SIZE; i++) {
        insertion_sort(&buckets[i]);
    }

    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        node_t *current = buckets[i];
        while (current != NULL) {
            input[index++] = current->data;
            current = current->next;
        }
    }

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
    int input[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(input) / sizeof(input[0]);

    bucket_sort(input, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", input[i]);
    }
    printf("\n");

    return 0;
}