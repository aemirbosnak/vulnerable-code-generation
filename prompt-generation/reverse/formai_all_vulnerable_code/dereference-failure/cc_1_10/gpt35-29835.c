//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linkedlist of each bucket
struct Node {
    int data;
    struct Node* next;
};

// Function to perform bucket sort on the input array
void bucketSort(int arr[], int n, int k) {
    // Create the buckets
    struct Node** buckets = (struct Node**) malloc(sizeof(struct Node*) * k);
    for (int i = 0; i < k; i++) buckets[i] = NULL;

    // Assign elements to their respective buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i] / k;
        struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
        new_node->data = arr[i];
        new_node->next = buckets[bucket_index];
        buckets[bucket_index] = new_node;
    }

    // Sort the individual buckets using insertion sort
    for (int i = 0; i < k; i++) {
        // Insertion sort on each bucket
        struct Node* current = buckets[i];
        while (current != NULL) {
            struct Node* head = buckets[i];
            if (head->data > current->data) {
                head = current;
                current = current->next;
                head->next = buckets[i];
                buckets[i] = head;
            }
            else {
                struct Node* previous = head;
                while (previous->next != NULL && previous->next->data < current->data)
                    previous = previous->next;
                struct Node* temp = current->next;
                current->next = previous->next;
                previous->next = current;
                current = temp;
            }
        }
    }

    // Copy the sorted elements back to the input array
    int index = 0;
    for (int i = 0; i < k; i++) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->data;
            current = current->next;
        }
    }

    // Free memory
    for (int i = 0; i < k; i++) {
        struct Node* current = buckets[i];
        while (buckets[i] != NULL) {
            buckets[i] = buckets[i]->next;
            free(current);
            current = buckets[i];
        }
    }
    free(buckets);
}

// Main function to test the implementation
int main() {
    int arr[] = {48, 22, 67, 32, 92, 55, 17, 69};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 10; // The value of k can be changed depending on the input range
    bucketSort(arr, n, k);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}