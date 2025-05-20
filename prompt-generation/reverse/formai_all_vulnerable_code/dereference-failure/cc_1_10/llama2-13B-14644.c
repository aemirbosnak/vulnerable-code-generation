//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the sorted list
struct Node {
    int data;
    struct Node* next;
};

// Function to sort an array of integers
void sortArray(int arr[], int n) {
    // Create a linked list of nodes representing the sorted list
    struct Node* head = NULL;
    struct Node* current = NULL;
    struct Node* next = NULL;

    // Loop through the array and add nodes to the linked list
    for (int i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }

        current = newNode;
    }

    // Set the current node to the head of the list
    head = current;

    // Print the sorted list
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

int main() {
    int arr[] = {3, 2, 1, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortArray(arr, n);

    return 0;
}