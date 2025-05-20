//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

// function to create a new bucket
Node* createBucket() {
    Node *newBucket = (Node*)malloc(sizeof(Node));
    newBucket->value = 0;
    newBucket->next = NULL;
    return newBucket;
}

// function to insert an element into a bucket
void insertIntoBucket(Node **bucket, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = *bucket;
    *bucket = newNode;
}

// function to calculate the maximum element in an array
int findMax(int array[], int length) {
    int max = array[0];
    for (int i = 1; i < length; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// function to perform bucket sort
void bucketSort(int array[], int length) {
    int max = findMax(array, length); // calculate the maximum element
    Node **buckets = (Node**)calloc(max + 1, sizeof(Node*)); // create an array of buckets
    
    // insert each element into its respective bucket
    for (int i = 0; i < length; i++) {
        int index = array[i];
        insertIntoBucket(&buckets[index], array[i]);
    }
    
    // iterate through each bucket, sorting its elements
    int k = 0; // variable to keep track of current index in original array
    for (int i = 0; i <= max; i++) {
        Node *currentNode = buckets[i];
        while (currentNode != NULL) { // sort elements in each bucket
            array[k++] = currentNode->value;
            currentNode = currentNode->next;
        }
    }
}

// sample main function to test the bucket sort implementation
int main() {
    int numbers[] = { 5, 2, 13, 2, 8, 1, 9 };
    int length = sizeof(numbers) / sizeof(numbers[0]);
    printf("Unsorted array:\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", numbers[i]);
    }
    bucketSort(numbers, length);
    printf("\nSorted array:\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", numbers[i]);
    }
    return 0;
}