//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

// Node structure for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Linked list structure
Node* createLinkedList(int size) {
    Node* head = NULL;
    Node* curr = NULL;
    int i;

    for (i = 0; i < size; i++) {
        curr = (Node*)malloc(sizeof(Node));
        if (curr == NULL) {
            printf("Memory error\n");
            exit(1);
        }
        curr->data = rand() % MAX_SIZE;
        curr->next = NULL;

        if (head == NULL) {
            head = curr;
        } else {
            Node* temp = head;
            while (temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = curr;
        }
    }

    return head;
}

// Search function using linear search
Node* linearSearch(Node* head, int target) {
    Node* curr = head;

    while (curr!= NULL) {
        if (curr->data == target) {
            return curr;
        }
        curr = curr->next;
    }

    return NULL;
}

// Search function using binary search
Node* binarySearch(Node* head, int target) {
    Node* left = head;
    Node* right = head->next;

    while (right!= NULL) {
        if (right->data == target) {
            return right;
        }

        if (target < right->data) {
            left = right;
            right = right->next;
        } else {
            right = right->next;
        }
    }

    return left;
}

int main() {
    int size, target;
    Node* head;

    // Get size of linked list from user
    printf("Enter size of linked list: ");
    scanf("%d", &size);

    // Create linked list
    head = createLinkedList(size);

    // Get target value from user
    printf("Enter target value: ");
    scanf("%d", &target);

    // Perform linear search
    Node* result1 = linearSearch(head, target);
    if (result1!= NULL) {
        printf("Target found at position %d\n", result1->data);
    } else {
        printf("Target not found\n");
    }

    // Perform binary search
    Node* result2 = binarySearch(head, target);
    if (result2!= NULL) {
        printf("Target found at position %d\n", result2->data);
    } else {
        printf("Target not found\n");
    }

    return 0;
}