//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Definition of Linked List Node
struct Node {
    int data;
    struct Node *next;
};

// Function to create a Linked List
struct Node* createList(int *arr, int size) {
    struct Node *head = NULL;
    int i;

    for (i = 0; i < size; i++) {
        struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = head;
        head = newNode;
    }

    return head;
}

// Function to traverse the Linked List
void traverseList(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of the Linked List
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to insert a node at the end of the Linked List
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    current->next = newNode;
    return head;
}

// Function to remove the first node of the Linked List
struct Node* removeFirst(struct Node* head) {
    struct Node* temp = head->next;
    head->next = temp->next;
    free(temp);
    return head;
}

// Function to remove the last node of the Linked List
struct Node* removeLast(struct Node* head) {
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = NULL;
    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    struct Node* head = createList(arr, size);

    traverseList(head);

    // Insert a node at the beginning of the Linked List
    head = insertAtBeginning(head, 0);

    traverseList(head);

    // Insert a node at the end of the Linked List
    head = insertAtEnd(head, 10);

    traverseList(head);

    // Remove the first node of the Linked List
    head = removeFirst(head);

    traverseList(head);

    // Remove the last node of the Linked List
    head = removeLast(head);

    traverseList(head);

    return 0;
}