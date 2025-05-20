//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key;
    struct Node *next;
} Node;

Node *create_node(int key) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->key = key;
    new_node->next = NULL;
    return new_node;
}

void insert_node(Node **head_ref, int new_key) {
    Node *new_node = create_node(new_key);
    Node *current = *head_ref, *previous = NULL;

    while (current != NULL && current->key < new_key) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL)
        *head_ref = new_node;
    else
        previous->next = new_node;

    new_node->next = current;
}

void print_list(Node *node) {
    while (node != NULL) {
        printf("%d ", node->key);
        node = node->next;
    }
    printf("\n");
}

void bucket_sort(int arr[], int n) {
    int i, max_index, bucket_size;
    Node **buckets;

    max_index = find_max(arr, n);
    bucket_size = 5; // Arbitrary bucket size

    buckets = (Node **)calloc(max_index + 1, sizeof(Node *));
    if (buckets == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    for (i = 0; i <= max_index; i++)
        buckets[i] = NULL;

    for (i = 0; i < n; i++) {
        insert_node(&buckets[arr[i]], arr[i]);
    }

    int index = 0;
    for (i = 0; i <= max_index; i++) {
        Node *temp = buckets[i];
        while (temp != NULL) {
            arr[index++] = temp->key;
            Node *next = temp->next;
            free(temp);
            temp = next;
        }
    }

    free(buckets);
}

int find_max(int arr[], int n) {
    int max = arr[0];
    int i;
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucket_sort(arr, n);
    printf("Sorted array: ");
    print_list(arr);

    return 0;
}