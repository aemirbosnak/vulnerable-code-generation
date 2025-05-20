//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// A node in our linked list
struct node {
    int data;
    struct node *next;
};

// A bucket
struct bucket {
    struct node *head;
    struct node *tail;
};

// Create a new bucket
struct bucket *create_bucket() {
    struct bucket *b = malloc(sizeof(struct bucket));
    b->head = NULL;
    b->tail = NULL;
    return b;
}

// Insert a node into a bucket
void insert_node(struct bucket *b, int data) {
    struct node *n = malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    if (b->head == NULL) {
        b->head = n;
        b->tail = n;
    } else {
        b->tail->next = n;
        b->tail = n;
    }
}

// Sort a bucket
void sort_bucket(struct bucket *b) {
    struct node *curr = b->head;
    struct node *prev = NULL;
    while (curr != NULL) {
        if (prev != NULL && prev->data > curr->data) {
            // Swap the data
            int temp = prev->data;
            prev->data = curr->data;
            curr->data = temp;
        }
        prev = curr;
        curr = curr->next;
    }
}

// Bucket sort
void bucket_sort(int *arr, int n) {
    // Create n buckets
    struct bucket *buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = create_bucket();
    }

    // Insert each element into a bucket
    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i] / n;
        insert_node(buckets[bucket_index], arr[i]);
    }

    // Sort each bucket
    for (int i = 0; i < n; i++) {
        sort_bucket(buckets[i]);
    }

    // Concatenate the buckets
    int index = 0;
    for (int i = 0; i < n; i++) {
        struct node *curr = buckets[i]->head;
        while (curr != NULL) {
            arr[index++] = curr->data;
            curr = curr->next;
        }
    }
}

// Print an array
void print_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 2, 3, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucket_sort(arr, n);

    printf("Sorted array: ");
    print_array(arr, n);

    return 0;
}