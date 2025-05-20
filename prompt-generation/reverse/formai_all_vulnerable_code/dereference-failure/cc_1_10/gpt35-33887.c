//FormAI DATASET v1.0 Category: Linked list operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define the structure for our linked list node
struct LinkedListNode {
    int data;
    struct LinkedListNode* next;
};

// Function to add a new node at the end of linked list
void append(struct LinkedListNode** head_ref, int new_data) {
    // Create a new node
    struct LinkedListNode* new_node = (struct LinkedListNode*)malloc(sizeof(struct LinkedListNode));
    struct LinkedListNode* last = *head_ref;
    // Assign data to the new node
    new_node->data = new_data;
    new_node->next = NULL;
    // If the linked list is empty, set the new node as head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    // Traverse to the end of the linked list
    while (last->next != NULL) {
        last = last->next;
    }
    // Add the new node at the end
    last->next = new_node;
    return;
}

// Function to add a new node at the beginning of linked list
void prepend(struct LinkedListNode** head_ref, int new_data) {
    // Create a new node
    struct LinkedListNode* new_node = (struct LinkedListNode*)malloc(sizeof(struct LinkedListNode));
    // Assign data to the new node
    new_node->data = new_data;
    // Set the next pointer of new node to the current head node
    new_node->next = *head_ref;
    // Set the new node as head
    *head_ref = new_node;
    return;
}

// Function to insert a new node at a given position
void insert(struct LinkedListNode** head_ref, int new_data, int position) {
    // Create a new node
    struct LinkedListNode* new_node = (struct LinkedListNode*)malloc(sizeof(struct LinkedListNode));
    struct LinkedListNode* current = *head_ref;
    // Assign data to the new node
    new_node->data = new_data;
    // If the linked list is empty or position is 0, insert at the beginning
    if (*head_ref == NULL || position == 0) {
        new_node->next = *head_ref;
        *head_ref= new_node;
        return;
    }
    // Traverse to the position
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    // If position is greater than the number of nodes in the linked list, add at the end
    if (current == NULL) {
        append(head_ref, new_data);
        return;
    }
    // Insert the new node
    new_node->next = current->next;
    current->next = new_node;
    return;
}

// Function to delete the node at the given position
void delete(struct LinkedListNode** head_ref, int position) {
    struct LinkedListNode* current = *head_ref;
    struct LinkedListNode* temp;
    // If the linked list is empty, can't delete anything
    if (*head_ref == NULL) {
        return;
    }
    // If position is 0, delete the head node
    if (position == 0) {
        *head_ref = current->next;
        free(current);
        return;
    }
    // Traverse to the position
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    // If position is greater than the number of nodes in the linked list, can't delete anything
    if (current == NULL || current->next == NULL) {
        return;
    }
    // Delete the node at the given position
    temp = current->next;
    current->next = temp->next;
    free(temp);
    return;
}

// Function to display the linked list
void display(struct LinkedListNode* head) {
    struct LinkedListNode* current = head;
    // Traverse the linked list and print each node's data
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct LinkedListNode* head = NULL;
    // Append some nodes to the linked list
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    printf("Linked list after appending nodes: ");
    display(head);
    // Prepend a node to the linked list
    prepend(&head, 0);
    printf("Linked list after prepending a node: ");
    display(head);
    // Insert a node at position 2
    insert(&head, 99, 2);
    printf("Linked list after inserting a node at position 2: ");
    display(head);
    // Delete the node at position 3
    delete(&head, 3);
    printf("Linked list after deleting a node at position 3: ");
    display(head);
    return 0;
}