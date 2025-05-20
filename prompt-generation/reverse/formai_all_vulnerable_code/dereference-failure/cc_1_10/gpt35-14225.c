//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 100000

// Create our custom bucket data structure
typedef struct node {
    int value;
    struct node *next;
} Node;

// Function declarations
int* generateRandomArray(int size);

Node** initializeBuckets();
void addToBucket(Node **buckets, int value);
void sortBuckets(Node **buckets, int *array);

void printArray(int *array, int size);
void printBuckets(Node **buckets);

int main() {

    // Generate a random array of integers
    int *array = generateRandomArray(MAX_ARRAY_SIZE);

    printf("Unsorted array:\n");
    printArray(array, MAX_ARRAY_SIZE);

    // Initialize the buckets
    Node **buckets = initializeBuckets();

    // Add values to the buckets
    for(int i = 0; i < MAX_ARRAY_SIZE; i++) {
        addToBucket(buckets, array[i]);
    }

    printf("\nBuckets:\n");
    printBuckets(buckets);

    // Sort the buckets and update the original array
    sortBuckets(buckets, array);

    printf("\nSorted array:\n");
    printArray(array, MAX_ARRAY_SIZE);

    return 0;
}

// Generates an array of random integers between 0 and 9999
int* generateRandomArray(int size) {
    int *array = (int*)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++) {
        array[i] = rand() % 10000;
    }
    return array;
}

// Initializes an array of buckets
Node** initializeBuckets() {
    Node **buckets = (Node**)calloc(100, sizeof(Node*));
    return buckets;
}

// Adds a value to the appropriate bucket
void addToBucket(Node **buckets, int value) {
    // Calculate which bucket to add the value to
    int index = value / 100;

    // Create a new node for the value
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    // Add the node to the appropriate bucket
    if(buckets[index] == NULL) {
        buckets[index] = newNode;
    } else {
        Node *currentNode = buckets[index];
        while(currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

// Sorts the values in each bucket and updates the original array
void sortBuckets(Node **buckets, int *array) {
    int index = 0;
    for(int i = 0; i < 100; i++) {
        Node *currentNode = buckets[i];
        while(currentNode != NULL) {
            array[index++] = currentNode->value;
            currentNode = currentNode->next;
        }
    }
}

// Prints the original unsorted array
void printArray(int *array, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Prints the sorted values in each bucket
void printBuckets(Node **buckets) {
    for(int i = 0; i < 100; i++) {
        Node *currentNode = buckets[i];
        printf("Bucket %d: ", i);
        while(currentNode != NULL) {
            printf("%d ", currentNode->value);
            currentNode = currentNode->next;
        }
        printf("\n");
    }
}