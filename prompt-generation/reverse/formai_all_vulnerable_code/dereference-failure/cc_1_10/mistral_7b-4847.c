//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the linked list node
typedef struct Node {
    char name[50];
    int age;
    float height;
    struct Node *next;
} Node;

// Function to create a new node
Node* createNode(char name[], int age, float height) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->height = height;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(Node** head, char name[], int age, float height) {
    Node* newNode = createNode(name, age, height);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(Node** head, char name[], int age, float height) {
    Node* newNode = createNode(name, age, height);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* lastNode = *head;
    while (lastNode->next != NULL)
        lastNode = lastNode->next;
    lastNode->next = newNode;
}

// Function to display the contents of the list
void displayList(Node* head) {
    Node* currentNode = head;
    while (currentNode != NULL) {
        printf("%s (%d years old, %.2f meters tall)\n", currentNode->name, currentNode->age, currentNode->height);
        currentNode = currentNode->next;
    }
}

// Function to delete the first occurrence of a node with a given name from the list
void deleteNode(Node** head, char name[]) {
    if (*head == NULL)
        return;
    if (strcmp((*head)->name, name) == 0) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    Node* currentNode = *head;
    while (currentNode->next != NULL && strcmp(currentNode->next->name, name) != 0)
        currentNode = currentNode->next;
    if (currentNode->next == NULL)
        return;
    Node* temp = currentNode->next;
    currentNode->next = currentNode->next->next;
    free(temp);
}

// Function to search for a node with a given name in the list
Node* searchNode(Node* head, char name[]) {
    Node* currentNode = head;
    while (currentNode != NULL) {
        if (strcmp(currentNode->name, name) == 0)
            return currentNode;
        currentNode = currentNode->next;
    }
    return NULL;
}

// Main function
int main() {
    Node* head = NULL;

    // Insert some nodes at the beginning of the list
    insertAtBeginning(&head, "John Doe", 25, 1.8);
    insertAtBeginning(&head, "Jane Doe", 30, 1.6);

    // Insert some nodes at the end of the list
    insertAtEnd(&head, "Mike Smith", 22, 1.7);
    insertAtEnd(&head, "Sarah Johnson", 28, 1.75);

    // Display the contents of the list
    printf("List before deletion:\n");
    displayList(head);

    // Delete a node with a given name
    deleteNode(&head, "Jane Doe");

    // Display the contents of the list after deletion
    printf("\nList after deletion:\n");
    displayList(head);

    // Search for a node with a given name
    Node* foundNode = searchNode(head, "Mike Smith");
    if (foundNode != NULL)
        printf("\nFound node with name 'Mike Smith': (%d years old, %.2f meters tall)\n", foundNode->age, foundNode->height);

    return 0;
}