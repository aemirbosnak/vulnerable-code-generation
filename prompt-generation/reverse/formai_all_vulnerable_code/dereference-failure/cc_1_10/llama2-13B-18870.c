//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Definition of a node
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of the list
void insertAtStart(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode(data);
}

// Function to remove the first node of the list
struct Node* removeFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return NULL;
    }
    struct Node* node = *head_ref;
    *head_ref = node->next;
    free(node);
    return node;
}

// Function to remove the last node of the list
struct Node* removeLast(struct Node** head_ref) {
    struct Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    struct Node* last = current;
    current->next = NULL;
    return last;
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning of the list
    insertAtStart(&head, 1);
    insertAtStart(&head, 2);
    insertAtStart(&head, 3);

    // Insert nodes at the end of the list
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);

    // Remove the first node of the list
    struct Node* first = removeFirst(&head);
    printf("First node removed: %d\n", first->data);

    // Remove the last node of the list
    struct Node* last = removeLast(&head);
    printf("Last node removed: %d\n", last->data);

    // Print the updated list
    printList(head);

    return 0;
}