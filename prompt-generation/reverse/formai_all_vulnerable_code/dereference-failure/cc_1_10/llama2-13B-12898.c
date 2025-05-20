//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new linked list
struct Node* createList(int* arr, int n) {
    struct Node* head = NULL;
    int i;

    for (i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = head;
        head = newNode;
    }

    return head;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

// Function to find the minimum element in the linked list
struct Node* findMin(struct Node* head) {
    struct Node* current = head;
    struct Node* min = head;

    while (current != NULL) {
        if (current->data < min->data) {
            min = current;
        }

        current = current->next;
    }

    return min;
}

// Function to remove the minimum element from the linked list
struct Node* removeMin(struct Node* head) {
    struct Node* current = head;
    struct Node* previous = NULL;

    while (current != NULL) {
        if (current->data == head->data) {
            if (current == head) {
                head = head->next;
            } else {
                previous->next = current->next;
            }

            free(current);
            return head;
        }

        previous = current;
        current = current->next;
    }

    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node* head = createList(arr, n);
    printList(head);

    struct Node* min = findMin(head);
    printList(min);

    head = removeMin(head);
    printList(head);

    return 0;
}