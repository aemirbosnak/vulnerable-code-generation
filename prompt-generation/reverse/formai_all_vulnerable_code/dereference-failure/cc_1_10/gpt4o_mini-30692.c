//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(Node** head_ref, int new_data) {
    Node* new_node = createNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Function to insert a node at the beginning of the list
void insertBeginning(Node** head_ref, int new_data) {
    Node* new_node = createNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to delete a node by value
void deleteNode(Node** head_ref, int key) {
    Node* temp = *head_ref;
    Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

// Function to print the linked list
void printList(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to count the number of nodes in the list
int countNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to reverse the linked list
void reverseList(Node** head_ref) {
    Node* prev = NULL;
    Node* current = *head_ref;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse the link
        prev = current;       // Move prev and current one step forward
        current = next;
    }
    *head_ref = prev; // Update head to last node
}

// Main function to demonstrate linked list operations
int main() {
    Node* head = NULL;

    // Inserting elements at the end
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    printf("Linked List after inserting elements at the end:\n");
    printList(head);

    // Inserting elements at the beginning
    insertBeginning(&head, 5);
    insertBeginning(&head, 0);
    printf("Linked List after inserting elements at the beginning:\n");
    printList(head);

    // Deleting a node
    printf("Deleting node with value 20:\n");
    deleteNode(&head, 20);
    printList(head);

    // Counting the number of nodes
    int count = countNodes(head);
    printf("The total number of nodes in the linked list: %d\n", count);

    // Reversing the linked list
    printf("Reversing the linked list:\n");
    reverseList(&head);
    printList(head);

    // Clean up
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}