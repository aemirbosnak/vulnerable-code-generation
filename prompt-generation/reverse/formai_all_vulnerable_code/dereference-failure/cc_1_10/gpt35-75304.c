//FormAI DATASET v1.0 Category: Stock market tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a stock item including its name and value
typedef struct {
    char name[50];
    double value;
} StockItem;

// Define a structure for a linked list node
typedef struct node {
    StockItem item;
    struct node *next;
} Node;

// Function prototypes
void addStockItem(Node **headPtr, StockItem itemToAdd);
void printStockList(Node *head);
void freeStockList(Node *head);

int main(void) {
    // Create an empty linked list to store stock items
    Node *head = NULL;
    
    // Add some example stock items to the list
    addStockItem(&head, (StockItem) {"AAPL", 128.80});
    addStockItem(&head, (StockItem) {"GOOG", 2354.25});
    addStockItem(&head, (StockItem) {"TSLA", 743.62});
    
    // Print the current list of stock items
    printf("Current stock portfolio:\n");
    printStockList(head);
    
    // Free the memory used by the linked list
    freeStockList(head);
    head = NULL;
    
    return 0;
}

// Function to add a stock item to the linked list
void addStockItem(Node **headPtr, StockItem itemToAdd) {
    // Allocate memory for a new linked list node
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->item = itemToAdd;
    newNode->next = NULL;
    
    // If the list is empty, set the new node as the head
    if (*headPtr == NULL) {
        *headPtr = newNode;
        return;
    }
    
    // Otherwise, loop through the list until the end is reached
    Node *currNode = *headPtr;
    while (currNode->next != NULL) {
        currNode = currNode->next;
    }
    
    // Add the new node to the end of the list
    currNode->next = newNode;
}

// Function to print the current list of stock items
void printStockList(Node *head) {
    // Loop through the linked list and print each item's details
    Node *currNode = head;
    while (currNode != NULL) {
        printf("%s: %.2f\n", currNode->item.name, currNode->item.value);
        currNode = currNode->next;
    }
}

// Function to free the memory used by the linked list
void freeStockList(Node *head) {
    // Loop through the linked list and free each node's memory
    Node *currNode = head;
    while (currNode != NULL) {
        Node *nextNode = currNode->next;
        free(currNode);
        currNode = nextNode;
    }
}