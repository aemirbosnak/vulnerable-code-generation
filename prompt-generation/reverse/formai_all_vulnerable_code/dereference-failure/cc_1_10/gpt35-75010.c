//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// define the structure of each node in linked list representing a bucket
struct Node {
    int value;
    struct Node* next;
};

// define the function to insert a value into a bucket
void insert(struct Node** head, int value) {
    struct Node* curr = *head;
    struct Node* prev = NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;

    // find the correct position to insert the new node
    while (curr != NULL && curr->value <= value) {
        prev = curr;
        curr = curr->next;
    }

    if (prev == NULL) { // insert at the head
        newNode->next = *head;
        *head = newNode;
    }
    else {
        newNode->next = prev->next;
        prev->next = newNode;
    }
}

// define the function to sort using bucket sort
void bucketSort(int arr[], int n, int numBuckets) {
    struct Node** buckets = (struct Node**)malloc(sizeof(struct Node*) * numBuckets);

    int i;
    for (i = 0; i < numBuckets; i++) {
        buckets[i] = NULL; // initialize each bucket as empty linked list
    }

    // insert each value from array into corresponding bucket
    for (i = 0; i < n; i++) {
        int bucketIndex = arr[i] / numBuckets;
        insert(&buckets[bucketIndex], arr[i]);
    }

    // copy values from buckets back into original array in sorted order
    int k = 0;
    for (i = 0; i < numBuckets; i++) {
        struct Node* curr = buckets[i];
        while (curr != NULL) {
            arr[k++] = curr->value;
            curr = curr->next;
        }
    }

    // free up memory used by buckets
    for (i = 0; i < numBuckets; i++) {
        struct Node* curr = buckets[i];
        while (curr != NULL) {
            struct Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(buckets);
}

// driver code to test the implementation
int main() {
    // create an array of integers to sort
    int arr[] = { 87, 456, 32, 56, 123, 987, 345, 654, 321, 789, 101, 202, 303, 55, 76 };
    int n = sizeof(arr) / sizeof(int);

    // set the number of buckets to use
    int numBuckets = 10;

    // perform bucket sort on the array
    bucketSort(arr, n, numBuckets);

    // print the sorted array
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}