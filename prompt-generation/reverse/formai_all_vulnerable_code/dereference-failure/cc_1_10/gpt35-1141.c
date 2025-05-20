//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// define a structure to act as the nodes in the linked list that represents each bucket
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// function to insert a value into the correct bucket (represented by a linked list)
void insert(Node** bucket, int value) {
    // allocate memory for a new node for the value
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    
    // if the first element of the bucket is NULL (i.e. the bucket is empty), set the newNode as the first element
    if (*bucket == NULL) {
        *bucket = newNode;
        return;
    }
    
    // if the first element has a value larger than the newNode value, insert the newNode as the first element
    if ((*bucket)->value > value) {
        newNode->next = *bucket;
        *bucket = newNode;
        return;
    }
    
    // traverse the linked list until finding the correct position to insert the newNode
    Node* current = *bucket;
    while (current->next != NULL && current->next->value < value) {
        current = current->next;
    }
    
    // insert the newNode after the current node
    newNode->next = current->next;
    current->next = newNode;
}

// function to traverse all the buckets and print the sorted array
void traverseAndPrint(Node** bucketArray, int arraySize) {
    int index = 0;
    Node* current;
    for (int i = 0; i < arraySize; i++) {
        current = bucketArray[i];
        while (current != NULL) {
            printf("%d ", current->value);
            current = current->next;
        }
    }
}

// function to sort an array using the bucket sort algorithm
void bucketSort(int* array, int arraySize, int bucketSize) {
    // create the array of buckets (represented by linked lists)
    Node** bucketArray = (Node**)malloc(bucketSize * sizeof(Node*));
    for (int i = 0; i < bucketSize; i++) {
        bucketArray[i] = NULL;
    }
    
    // insert each element of the original array into its corresponding bucket
    for (int i = 0; i < arraySize; i++) {
        int bucketIndex = array[i] / bucketSize;
        insert(&bucketArray[bucketIndex], array[i]);
    }
    
    // traverse all the buckets and print the sorted array
    traverseAndPrint(bucketArray, bucketSize);
}

int main() {
    int array[] = {18, 22, 12, 4, 8, 28, 0, 1, 9, 33, 34, 2, 15, 11, 10, 7};
    int arraySize = sizeof(array) / sizeof(int);
    int bucketSize = 5;
    
    bucketSort(array, arraySize, bucketSize);
    
    return 0;
}