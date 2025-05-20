//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ARRAY_SIZE 10

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node** create_buckets() {
    Node** buckets = malloc(sizeof(Node*) * 11);
    for (int i = 0; i < 11; i++) {
        buckets[i] = NULL;
    }
    return buckets;
}

void free_buckets(Node** buckets) {
    for (int i = 0; i < 11; i++) {
        Node* current = buckets[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(buckets);
}

void add_to_bucket(Node** bucket, int data) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *bucket;
    *bucket = new_node;
}

void sort(int arr[], int n) {
    Node** buckets = create_buckets();

    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i] / 10;
        add_to_bucket(buckets + bucket_index, arr[i]);
    }

    int index = 0;
    for (int i = 0; i < 11; i++) {
        Node* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->data;
            current = current->next;
        }
    }

    free_buckets(buckets);
}

void print_array(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(", ");
        printf("%d", arr[i]);
    }
    printf("]\n");
}

int main() {
    int arr[ARRAY_SIZE] = {5, 2, 8, 3, 7, 1, 6, 4, 9, 0};

    printf("Before sorting: \n");
    print_array(arr, ARRAY_SIZE);

    sort(arr, ARRAY_SIZE);

    printf("After sorting: \n");
    print_array(arr, ARRAY_SIZE);

    return 0;
}