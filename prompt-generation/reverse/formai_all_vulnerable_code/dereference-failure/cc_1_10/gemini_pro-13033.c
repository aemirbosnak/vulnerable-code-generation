//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node struct for storing item and bid information
typedef struct Node {
    char itemName[50];
    float currentBid;
    struct Node *next;
} Node;

// Function to create a new node with given item name and bid
Node* createNode(char *itemName, float currentBid) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->itemName, itemName);
    newNode->currentBid = currentBid;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertNode(Node **head, Node *newNode) {
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

// Function to print the linked list of items
void printItems(Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        printf("%s: $%.2f\n", curr->itemName, curr->currentBid);
        curr = curr->next;
    }
}

// Function to check if an item exists in the linked list
bool itemExists(Node *head, char *itemName) {
    Node *curr = head;
    while (curr != NULL) {
        if (strcmp(curr->itemName, itemName) == 0) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

// Function to place a bid on an item
void placeBid(Node **head, char *itemName, float newBid) {
    if (!itemExists(*head, itemName)) {
        printf("Item does not exist.\n");
        return;
    }
    Node *curr = *head;
    while (curr != NULL) {
        if (strcmp(curr->itemName, itemName) == 0) {
            if (newBid > curr->currentBid) {
                curr->currentBid = newBid;
                printf("Bid placed successfully.\n");
            } else {
                printf("Bid must be higher than the current bid.\n");
            }
            return;
        }
        curr = curr->next;
    }
}

// Main function
int main() {
    // Create a linked list to store the items
    Node *head = NULL;

    // Insert some items into the linked list
    insertNode(&head, createNode("Painting", 100.0));
    insertNode(&head, createNode("Sculpture", 200.0));
    insertNode(&head, createNode("Vase", 50.0));

    // Print the list of items
    printf("Current Items:\n");
    printItems(head);

    // Place a bid on an item
    placeBid(&head, "Painting", 150.0);
    placeBid(&head, "Sculpture", 250.0);
    placeBid(&head, "Vase", 75.0);

    // Print the updated list of items
    printf("Updated Items:\n");
    printItems(head);

    return 0;
}