//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define our linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void insertAtEnd(struct Node** head, int data);
void deleteNode(struct Node** head, int key);
void displayList(struct Node* node);
struct Node* searchNode(struct Node* head, int key);

int main() {
    struct Node* head = NULL;  // Initialize the head of the linked list

    // Some delightful insertions
    printf("Welcome to the Wonderful World of Linked Lists!\n");
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    
    printf("Here is the list after some happy insertions:\n");
    displayList(head);

    // Searching for an element
    int searchValue = 20;
    struct Node* searchResult = searchNode(head, searchValue);
    if (searchResult) {
        printf("Found %d in the list!\n", searchValue);
    } else {
        printf("%d not found in the list.\n", searchValue);
    }

    // Let's do some deletions
    printf("Let's remove 20 from our marvelous list:\n");
    deleteNode(&head, 20);
    displayList(head);

    printf("And now let's try deleting an element that doesn't exist like 100!\n");
    deleteNode(&head, 100);
    displayList(head);

    // Free the remaining nodes
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    printf("Thank you for visiting our Linked List!\n");
    return 0;
}

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert a new node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    printf("Inserted %d into the list!\n", data);
}

// Delete a node from the list
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head, *prev = NULL;

    // If the node to be deleted is the head node
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        printf("Deleted %d from the list!\n", key);
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in the list
    if (temp == NULL) {
        printf("%d not found in the list, could not delete.\n", key);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from the list!\n", key);
}

// Display the entire linked list
void displayList(struct Node* node) {
    if (node == NULL) {
        printf("The list is empty!\n");
        return;
    }
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Search for a node in the list
struct Node* searchNode(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current; // Return the node found
        }
        current = current->next;
    }
    return NULL; // Return NULL if not found
}