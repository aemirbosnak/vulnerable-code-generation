//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

// Define bucket data structure
typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Bucket {
    Node* head;
} Bucket;

// Bucket Sort function
void bucketSort(int arr[], int n) {
    int i, j;
    Bucket* buckets = (Bucket*) malloc(sizeof(Bucket) * n);
    
    // Initialize buckets
    for (i = 0; i < n; i++) {
        buckets[i].head = NULL;
    }
    
    // Insert elements into their respective buckets
    for (i = 0; i < n; i++) {
        int index = arr[i] / n; // Determine which bucket to insert the element into
        Node* newNode = (Node*) malloc(sizeof(Node)); // Create new node
        newNode->value = arr[i];
        newNode->next = NULL;
        // Insert node at head of corresponding bucket
        if (buckets[index].head == NULL) {
            buckets[index].head = newNode;
        } else {
            Node* curr = buckets[index].head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }
    
    // Sort each individual bucket
    for (i = 0; i < n; i++) {
        Node* curr = buckets[i].head;
        int* bucketArr = (int*) malloc(sizeof(int) * n);
        int count = 0;
        // Copy bucket elements into array
        while (curr != NULL) {
            bucketArr[count++] = curr->value;
            curr = curr->next;
        }
        // Sort array using Insertion Sort
        for (j = 1; j < count; j++) {
            int key = bucketArr[j];
            int k = j - 1;
            while (k >= 0 && bucketArr[k] > key) {
                bucketArr[k + 1] = bucketArr[k];
                k--;
            }
            bucketArr[k + 1] = key;
        }
        // Copy sorted array back into bucket
        curr = buckets[i].head;
        for (j = 0; j < count; j++) {
            curr->value = bucketArr[j];
            curr = curr->next;
        }
        free(bucketArr);
    }
    
    // Concatenate sorted buckets
    i = 0;
    for (j = 0; j < n; j++) {
        Node* curr = buckets[j].head;
        while (curr != NULL) {
            arr[i++] = curr->value;
            curr = curr->next;
        }
        free(buckets[j].head); // Free memory allocated for each individual bucket's linked list
    }
    free(buckets); // Free memory allocated for bucket array
}

// Driver program to test Bucket Sort
int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}