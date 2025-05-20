//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Bucket {
    int count;
    struct Node *head;
} Bucket;

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Bucket *create_bucket_array() {
    Bucket *bucket_array = (Bucket *)calloc(TABLE_SIZE, sizeof(Bucket));

    for (int i = 0; i < TABLE_SIZE; ++i) {
        bucket_array[i].count = 0;
        bucket_array[i].head = NULL;
    }

    return bucket_array;
}

void insert_node(Node **head, int data) {
    Node *new_node = (Node *)calloc(1, sizeof(Node));

    if (!new_node) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

int hash_function(int data) {
    return data % TABLE_SIZE;
}

void bucket_sort(int arr[], int size) {
    Bucket *bucket_array = create_bucket_array();

    for (int i = 0; i < size; ++i) {
        int bucket_index = hash_function(arr[i]);
        insert_node(&bucket_array[bucket_index].head, arr[i]);
    }

    int index = 0;
    for (int i = 0; i < TABLE_SIZE; ++i) {
        Node *current = bucket_array[i].head;

        while (current != NULL) {
            arr[index++] = current->data;
            current = current->next;
        }
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    bucket_sort(arr, size);

    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    free(arr);

    return 0;
}