//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BUCKETS 10

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_end(Node **head_ref, int new_data) {
    Node *new_node = create_node(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    Node *last = *head_ref;
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

int hash_function(int key, int num_buckets) {
    return key % num_buckets;
}

void bucket_sort(int arr[], int n) {
    Node *bucket[NUM_BUCKETS] = {NULL};

    for (int i = 0; i < n; i++) {
        int bucket_index = hash_function(arr[i], NUM_BUCKETS);
        if (bucket[bucket_index] == NULL) {
            bucket[bucket_index] = create_node(arr[i]);
        } else {
            Node *current = bucket[bucket_index];
            while (current->next != NULL)
                current = current->next;

            current->next = create_node(arr[i]);
        }
    }

    int index = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        Node *current = bucket[i];
        while (current != NULL) {
            arr[index++] = current->data;
            current = current->next;
        }
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (n <= 0) {
        printf("Invalid input! Array should have at least one element.\n");
        return -1;
    }

    bucket_sort(arr, n);
    print_array(arr, n);

    return 0;
}