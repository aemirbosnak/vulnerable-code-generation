//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

// Node structure for linked list
typedef struct Node {
    float value;
    struct Node* next;
} Node;

// Function to insert a value into the linked list
void insert(Node** head, float value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->value >= value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL && current->next->value < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to perform bucket sort
void bucketSort(float arr[], int n) {
    // Create buckets
    Node** buckets = (Node**)malloc(BUCKET_SIZE * sizeof(Node*));
    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = NULL; // Initialize each bucket
    }

    // Distribute input array values into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(arr[i] / BUCKET_SIZE); 
        if(bucketIndex >= BUCKET_SIZE) // Handle edge cases
            bucketIndex = BUCKET_SIZE - 1;
        insert(&buckets[bucketIndex], arr[i]);
    }

    // Concatenate buckets into the original array
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        Node* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->value;
            Node* temp = current;
            current = current->next;
            free(temp); // Free allocated memory
        }
    }
    
    free(buckets); // Free the bucket array
}

// Function to print the array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

// Main function to execute the program
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    float* arr = (float*)malloc(n * sizeof(float));
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    printf("Original array:\n");
    printArray(arr, n);

    bucketSort(arr, n);
    
    printf("Sorted array:\n");
    printArray(arr, n);

    free(arr); // Clean up
    return 0;
}