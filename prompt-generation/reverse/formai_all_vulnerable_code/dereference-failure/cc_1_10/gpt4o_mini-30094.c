//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000  // Maximum number of elements in array
#define BUCKET_SIZE 10  // Number of buckets
#define RANGE 1000  // Range of input numbers

// Node structure for linked list in each bucket
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Bucket structure holding the head of the linked list
typedef struct Bucket {
    Node* head;
} Bucket;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize buckets
void initBuckets(Bucket* buckets) {
    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i].head = NULL;
    }
}

// Insertion function for linked list in each bucket
void insert(Bucket* bucket, int value) {
    Node* newNode = createNode(value);
    if (bucket->head == NULL) {
        bucket->head = newNode;
    } else {
        Node* current = bucket->head;
        Node* previous = NULL;

        while (current != NULL && current->value < value) {
            previous = current;
            current = current->next;
        }

        if (previous == NULL) {  // Insert at head
            newNode->next = bucket->head;
            bucket->head = newNode;
        } else {
            newNode->next = current;
            previous->next = newNode;
        }
    }
}

// Function to sort and collect values from buckets
void collectSortedValues(Bucket* buckets, int* array, int* index) {
    for (int i = 0; i < BUCKET_SIZE; i++) {
        Node* current = buckets[i].head;
        while (current != NULL) {
            array[*index] = current->value;
            (*index)++;
            current = current->next;
        }
    }
}

// Bucket sort function
void bucketSort(int* array, int n) {
    // Create buckets
    Bucket* buckets = (Bucket*)malloc(BUCKET_SIZE * sizeof(Bucket));
    initBuckets(buckets);

    // Place each number into a bucket
    for (int i = 0; i < n; i++) {
        int bucketIndex = array[i] * BUCKET_SIZE / RANGE;
        if (bucketIndex >= BUCKET_SIZE)
            bucketIndex = BUCKET_SIZE - 1;
        insert(&buckets[bucketIndex], array[i]);
    }

    // Collect sorted values from buckets
    int index = 0;
    collectSortedValues(buckets, array, &index);

    // Free memory for linked lists in buckets
    for (int i = 0; i < BUCKET_SIZE; i++) {
        Node* current = buckets[i].head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(buckets);
}

// Utility function to print the array
void printArray(int* array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements to be sorted (max %d): ", MAX);
    scanf("%d", &n);
    if (n > MAX) {
        printf("Error: Number of elements exceeds maximum limit!\n");
        return 1;
    }

    int* array = (int*)malloc(n * sizeof(int));
    printf("Enter %d integers between 0 and %d:\n", n, RANGE - 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    // Perform bucket sort
    bucketSort(array, n);

    // Print sorted array
    printf("Sorted array: ");
    printArray(array, n);

    // Clean up
    free(array);
    return 0;
}