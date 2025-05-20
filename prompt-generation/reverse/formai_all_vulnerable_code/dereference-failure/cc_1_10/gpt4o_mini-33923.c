//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VALUE 100  // The realm of numbers we shall conjure
#define BUCKET_COUNT 10 // The tributaries where we will cast our number nets

// The hollow echo of the cosmic void
typedef struct Node {
    int value;
    struct Node* next; // The endless loop of destiny
} Node;

// The magic of the buckets
typedef struct Bucket {
    Node* head;  // The guardian of the bucket's secrets
    Node* tail;  // The end of the line, or is it?
} Bucket;

// Function to create a bucket, a vessel of chaos
Bucket* createBucket() {
    Bucket* bucket = (Bucket*)malloc(sizeof(Bucket));
    bucket->head = NULL;
    bucket->tail = NULL;
    return bucket;
}

// Function to add a number to the bucket
void addToBucket(Bucket* bucket, int number) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = number;
    newNode->next = NULL;

    if (bucket->head == NULL) {
        bucket->head = newNode; // The first star igniting the sky
        bucket->tail = newNode; // The anchor at the end
    } else {
        bucket->tail->next = newNode; // Linking destinies
        bucket->tail = newNode; // Moving the tail to a new horizon
    }
}

// Function to sort buckets and release the spirits within
void sortBucket(Bucket* bucket, int* sortedArray, int* index) {
    Node* currentNode = bucket->head;
    while (currentNode != NULL) {
        sortedArray[*index] = currentNode->value; // Recording the moment
        (*index)++;
        currentNode = currentNode->next; // Flowing through time
    }
}

// The luminous function that orchestrates the bucket sort
void bucketSort(int* array, int arraySize) {
    Bucket* buckets[BUCKET_COUNT];
    for (int i = 0; i < BUCKET_COUNT; i++) {
        buckets[i] = createBucket();  // Casting a net into the abyss
    }

    // Populate the buckets
    for (int i = 0; i < arraySize; i++) {
        int index = (array[i] * BUCKET_COUNT) / (MAX_VALUE + 1); // Finding the appropriate abyss
        addToBucket(buckets[index], array[i]); // Entrapping the swirling numbers
    }

    // Sort the buckets and free the captured spirits
    int sortedIndex = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        sortBucket(buckets[i], array, &sortedIndex);
        // Freeing the wisdom caught in time
        Node* currentNode = buckets[i]->head;
        while (currentNode != NULL) {
            Node* temp = currentNode;
            currentNode = currentNode->next; // An unbroken loop in the tapestry
            free(temp);
        }
        free(buckets[i]); // Embracing the emptiness of the void
    }
}

// A dance of code that spins the tale of cosmic numbers
void printArray(int* array, int size) {
    printf("The sorted array emerges as a wild vision:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]); // Casting spells with digits
    }
    printf("\n");
}

int main() {
    // The genesis of unshaped numbers
    int array[] = {29, 25, 3, 49, 9, 37, 21, 43, 1, 99, 88, 76, 12, 54, 2, 61};
    int n = sizeof(array) / sizeof(array[0]);

    printf("In an alternate universe, numbers awaken...\n");
    bucketSort(array, n); // The incantation begins
    printArray(array, n); // The revelation of sorted order

    return 0; // A closing curtain in the theater of dreams
}