//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUCKET_SIZE 10
#define TABLE_SIZE 101

typedef struct Node {
    int key;
    struct Node *next;
} Node;

Node *create_node(int key) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->key = key;
    new_node->next = NULL;
    return new_node;
}

void destroy_list(Node **head) {
    Node *current = *head;
    Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->key);
        current = current->next;
    }
}

int hash_func(int key) {
    return (key % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE;
}

void bucket_sort(int *arr, int size) {
    Node **buckets = calloc(TABLE_SIZE, sizeof(Node *));
    for (int i = 0; i < TABLE_SIZE; i++) {
        buckets[i] = NULL;
    }

    for (int i = 0; i < size; i++) {
        int index = hash_func(arr[i]);
        Node *new_node = create_node(arr[i]);
        Node *current = buckets[index];
        if (current == NULL) {
            buckets[index] = new_node;
        } else {
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Bucket %d: ", i);
        print_list(buckets[i]);
        printf("\n");
        destroy_list(&(buckets[i]));
    }

    free(buckets);
}

int main() {
    int arr[] = {34, 23, 1, 26, 66, 10, 34, 5, 25, 12, 21, 33, 16};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    bucket_sort(arr, size);

    return 0;
}