//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure
typedef struct Node {
    int type; // 0 for int, 1 for string
    union {
        int intValue;
        char strValue[50];
    } data;
    struct Node* next;
} Node;

// Function prototypes
Node* createNodeInt(int value);
Node* createNodeStr(const char* value);
void insert(Node** head, Node* newNode);
void deleteNode(Node** head, int index);
void display(Node* head);
void transformToStr(Node* node);
void transformToInt(Node* node);

int main() {
    Node* head = NULL;

    // Inserting integer nodes
    insert(&head, createNodeInt(10));
    insert(&head, createNodeInt(20));
    insert(&head, createNodeInt(30));

    // Display the linked list
    printf("Initial Integer List:\n");
    display(head);

    // Transform the second node to a string
    printf("Transforming second node to string:\n");
    transformToStr(head->next);
    display(head);

    // Transform the first node back to integer
    printf("Transforming first node back to integer:\n");
    transformToInt(head);
    display(head);

    // Inserting string nodes
    insert(&head, createNodeStr("Hello"));
    insert(&head, createNodeStr("World"));

    // Display the final list
    printf("Final List with Strings:\n");
    display(head);

    // Clean up the linked list
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

// Create a new integer node
Node* createNodeInt(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = 0; // Type is integer
    newNode->data.intValue = value;
    newNode->next = NULL;
    return newNode;
}

// Create a new string node
Node* createNodeStr(const char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = 1; // Type is string
    strncpy(newNode->data.strValue, value, sizeof(newNode->data.strValue));
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the end of the list
void insert(Node** head, Node* newNode) {
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Delete a node from the list
void deleteNode(Node** head, int index) {
    if (*head == NULL) return;

    Node* temp = *head;
    if (index == 0) {
        *head = temp->next; // Move head
        free(temp);
        return;
    }

    // Find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    }

    // If the node does not exist, return
    if (temp == NULL || temp->next == NULL) return;

    // Node temp->next is the node to be deleted
    Node* next = temp->next->next;
    free(temp->next); // Free memory
    temp->next = next; // Unlink the deleted node
}

// Display the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp) {
        if (temp->type == 0) {
            printf("%d -> ", temp->data.intValue);
        } else {
            printf("%s -> ", temp->data.strValue);
        }
        temp = temp->next;
    }
    printf("NULL\n");
}

// Transform node to string
void transformToStr(Node* node) {
    if (node->type == 0) {
        snprintf(node->data.strValue, sizeof(node->data.strValue), "Number: %d", node->data.intValue);
        node->type = 1; // Change type to string
    }
}

// Transform node to integer
void transformToInt(Node* node) {
    if (node->type == 1) {
        // Placeholder integer value
        node->data.intValue = 0; // Replace with logic to derive an int
        node->type = 0; // Change type to integer
    }
}