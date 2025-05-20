//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: curious
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at a given position in the linked list
void insertAtPosition(struct Node** head, int position, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to delete a node at a given position in the linked list
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("The linked list is empty!\n");
        return;
    }

    if (position == 0) {
        *head = (*head)->next;
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* current = *head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }

    current->next = current->next->next;
    free(current);
    return;
}

// Function to traverse the linked list in reverse order
void reverseTraversal(struct Node* head) {
    if (head == NULL) {
        return;
    }

    struct Node* prev = NULL;
    struct Node* current = head;

    while (current!= NULL) {
        struct Node* temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }

    head = prev;
    current = head;

    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

// Function to swap the values of two nodes at given positions in the linked list
void swapNodes(struct Node** head, int firstPos, int secondPos) {
    if (*head == NULL) {
        printf("The linked list is empty!\n");
        return;
    }

    if (firstPos == secondPos) {
        printf("The nodes at the given positions are the same!\n");
        return;
    }

    struct Node* temp = NULL;
    struct Node* first = *head;
    struct Node* second = NULL;

    for (int i = 0; i < firstPos; i++) {
        first = first->next;
    }

    if (firstPos == secondPos) {
        printf("The nodes at the given positions are the same!\n");
        return;
    }

    second = first->next;
    first->next = second->next;
    second->next = first;

    temp = first;
    first = second;
    second = temp;

    printf("Swapping the values of nodes at positions %d and %d\n", firstPos, secondPos);

    while (first!= NULL) {
        printf("%d ", first->data);
        first = first->next;
    }
    printf("\n");
}

int main() {
    // Create a new linked list
    struct Node* head = createNode(1);
    insertAtPosition(&head, 0, 2);
    insertAtPosition(&head, 1, 3);
    insertAtPosition(&head, 2, 4);
    insertAtPosition(&head, 3, 5);

    // Print the original linked list
    printf("Original linked list:\n");
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");

    // Delete the node at position 2
    deleteAtPosition(&head, 2);

    // Print the updated linked list
    printf("Updated linked list after deleting node at position 2:\n");
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");

    // Traverse the linked list in reverse order
    reverseTraversal(head);

    // Swap the values of nodes at positions 1 and 2
    swapNodes(&head, 1, 2);

    // Print the updated linked list
    printf("Updated linked list after swapping nodes at positions 1 and 2:\n");
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");

    return 0;
}