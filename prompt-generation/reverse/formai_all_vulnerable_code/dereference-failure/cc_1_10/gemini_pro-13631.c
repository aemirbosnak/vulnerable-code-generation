//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: modular
#include <stdlib.h>
#include <stdio.h>

// Structure to represent a node in the bucket
struct node {
    int value;
    struct node *next;
};

// Function to create a new node
struct node* create_node(int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node into a bucket
void insert_node(struct node** bucket, int value) {
    struct node* new_node = create_node(value);
    new_node->next = *bucket;
    *bucket = new_node;
}

// Function to sort an array using bucket sort
void bucket_sort(int* arr, int size) {
    // Create an array of buckets
    struct node** buckets = (struct node**)malloc(sizeof(struct node*) * size);
    for (int i = 0; i < size; i++) {
        buckets[i] = NULL;
    }

    // Insert each element of the array into a bucket
    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / size;
        insert_node(&buckets[bucket_index], arr[i]);
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < size; i++) {
        struct node* current = buckets[i];
        struct node* prev = NULL;
        while (current != NULL) {
            if (prev != NULL && current->value < prev->value) {
                // Swap the values of the current and previous nodes
                int temp = current->value;
                current->value = prev->value;
                prev->value = temp;
            }
            prev = current;
            current = current->next;
        }
    }

    // Concatenate the sorted buckets into a single array
    int index = 0;
    for (int i = 0; i < size; i++) {
        struct node* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->value;
            current = current->next;
        }
    }

    // Free the memory allocated for the buckets
    for (int i = 0; i < size; i++) {
        struct node* current = buckets[i];
        while (current != NULL) {
            struct node* next = current->next;
            free(current);
            current = next;
        }
        free(buckets[i]);
    }
    free(buckets);
}

// Function to print an array
void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Create an array of unsorted integers
    int arr[] = {3, 1, 4, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using bucket sort
    bucket_sort(arr, size);

    // Print the sorted array
    print_array(arr, size);

    return 0;
}