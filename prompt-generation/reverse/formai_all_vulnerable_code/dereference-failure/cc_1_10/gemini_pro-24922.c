//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the stock structure
typedef struct Stock {
    char *name;
    double price;
} Stock;

// Define the node structure
typedef struct Node {
    Stock stock;
    struct Node *next;
} Node;

// Function to create a new stock
Stock *createStock(char *name, double price) {
    Stock *stock = malloc(sizeof(Stock));
    stock->name = malloc(strlen(name) + 1);
    strcpy(stock->name, name);
    stock->price = price;
    return stock;
}

// Function to create a new node
Node *createNode(Stock *stock) {
    Node *node = malloc(sizeof(Node));
    node->stock = *stock;
    node->next = NULL;
    return node;
}

// Function to insert a new node into a linked list
Node *insertNode(Node *head, Node *node) {
    if (head == NULL) {
        return node;
    } else {
        node->next = head;
        return node;
    }
}

// Function to print a linked list of stocks
void printList(Node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
    } else {
        Node *current = head;
        while (current != NULL) {
            printf("Stock: %s, Price: %f\n", current->stock.name, current->stock.price);
            current = current->next;
        }
    }
}

// Function to track the stock market
void trackStockMarket(Node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
    } else {
        Node *current = head;
        while (current != NULL) {
            // Get the current stock price
            double currentPrice = current->stock.price;

            // Get the previous stock price
            double previousPrice = 0.0;
            if (current->next != NULL) {
                previousPrice = current->next->stock.price;
            }

            // Calculate the change in stock price
            double change = currentPrice - previousPrice;

            // Print the stock information
            printf("Stock: %s, Current Price: %f, Change: %f\n", current->stock.name, currentPrice, change);

            // Recursively track the next stock
            trackStockMarket(current->next);

            // Move to the next stock
            current = current->next;
        }
    }
}

// Main function
int main() {
    // Create a linked list of stocks
    Node *head = NULL;
    head = insertNode(head, createNode(createStock("Apple", 100.0)));
    head = insertNode(head, createNode(createStock("Microsoft", 200.0)));
    head = insertNode(head, createNode(createStock("Google", 300.0)));
    head = insertNode(head, createNode(createStock("Amazon", 400.0)));
    head = insertNode(head, createNode(createStock("Tesla", 500.0)));

    // Print the linked list of stocks
    printList(head);

    // Track the stock market
    trackStockMarket(head);

    return 0;
}