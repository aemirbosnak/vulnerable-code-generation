//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new linked list node
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of a linked list
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to remove the first node of a linked list
struct Node* removeFirst(struct Node** head_ref) {
    struct Node* first_node = *head_ref;
    *head_ref = first_node->next;
    free(first_node);
    return first_node;
}

// Function to find the first node with a given value
struct Node* findFirstWithValue(struct Node* head, int value) {
    while (head != NULL && head->data != value) {
        head = head->next;
    }
    return head;
}

// Function to print all the nodes in a linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes at the beginning of the list
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    // Remove the first node from the list
    struct Node* first_node = removeFirst(&head);
    printf("Removed first node: %d\n", first_node->data);

    // Find the first node with value 2
    struct Node* second_node = findFirstWithValue(head, 2);
    printf("Found second node: %d\n", second_node->data);

    // Print the remaining nodes in the list
    printList(head);

    return 0;
}