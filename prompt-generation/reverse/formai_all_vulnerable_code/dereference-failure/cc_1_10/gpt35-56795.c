//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#define N 10

// Define node struct
typedef struct node {
    int data;
    struct node* next;
} node;

// Function to insert nodes into buckets
void insert(node** bucket, int value, int index) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;

    if(bucket[index] == NULL) {
        bucket[index] = newNode;
    }
    else {
        node* temp = bucket[index];
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print nodes in sorted order 
void printNodes(node** bucket) {
    int i;
    for(i = 0; i < N; i++) {
        node* temp = bucket[i];
        while(temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

// Function that applies bucket sort algorithm
void bucketSort(int arr[], int n) {
    // Create buckets array
    node* buckets[N] = { NULL };

    int i, j;
    for(i = 0; i < n; i++) {
        insert(buckets, arr[i], arr[i]/N);
    }

    // Sort buckets and print results
    printf("Sorted array: ");
    printNodes(buckets);
}

// Main function to test implementation
int main() {
    int arr[] = {45, 66, 75, 88, 23, 56, 67, 12, 89, 31};
    int n = sizeof(arr)/sizeof(arr[0]);

    bucketSort(arr, n);

    return 0;
}