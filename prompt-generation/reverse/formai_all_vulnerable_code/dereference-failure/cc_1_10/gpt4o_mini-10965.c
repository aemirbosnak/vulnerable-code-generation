//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;                // Data to store in Node
    struct Node* next;       // Pointer to the next Node
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    printf("Your Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to append a node at the end
void appendNode(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Function to insert a new node at a specific position
void insertNode(struct Node** head_ref, int data, int position) {
    struct Node* new_node = createNode(data);
    if (position == 0) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }
    struct Node* temp = *head_ref;
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;
    
    if (temp == NULL) {
        printf("The previous node is null. Inserting at the end instead.\n");
        appendNode(head_ref, data);
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to delete a node by key
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    // If the head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        printf("Deleted the node with key: %d\n", key);
        return;
    }

    // Search for the key to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key was not present in the linked list
    if (temp == NULL) {
        printf("The key: %d was not found!\n", key);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);
    printf("Deleted the node with key: %d\n", key);
}

// Function to free the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function to execute the program
int main() {
    struct Node* head = NULL; // Starting point of the linked list

    printf("Welcome to the Energetic Linked List Program!\n");
    printf("Let's start by adding some elements to the list...\n");

    appendNode(&head, 5);
    appendNode(&head, 10);
    appendNode(&head, 15);
    printList(head);

    printf("Inserting 20 at position 1...\n");
    insertNode(&head, 20, 1);
    printList(head);

    printf("Inserting 25 at position 0...\n");
    insertNode(&head, 25, 0);
    printList(head);

    printf("Let's remove the number 10 from our linked list...\n");
    deleteNode(&head, 10);
    printList(head);

    printf("Let's try to delete a non-existent number 30...\n");
    deleteNode(&head, 30);
    printList(head);

    printf("Now, let's free the linked list to clear up memory.\n");
    freeList(head);
    head = NULL;

    printf("All done! Goodbye Linked List Adventure!\n");
    return 0;
}