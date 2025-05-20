//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct {
    char name[50];
    int quantity;
    float price;
    struct Node *next;
} Node;

// Function prototypes
void add_item(Item *item);
void remove_item(char *name);
void update_item(char *name, Item *item);
void print_items();

// Global variables
Node *head = NULL; // Head of the linked list

// Main function
int main() {
    // Initialize the program
    printf("Welcome to the Cyberpunk Medical Store Management System!\n");

    // Add some items to the store
    Item item1 = {"Medkit", 10, 100.0};
    add_item(&item1);

    Item item2 = {"Stimpak", 5, 50.0};
    add_item(&item2);

    Item item3 = {"Cybernetic implant", 1, 1000.0};
    add_item(&item3);

    // Print the items in the store
    print_items();

    // Remove an item from the store
    remove_item("Medkit");

    // Update an item in the store
    Item item4 = {"Stimpak", 10, 75.0};
    update_item("Stimpak", &item4);

    // Print the items in the store again
    print_items();

    return 0;
}

// Function to add an item to the store
void add_item(Item *item) {
    // Create a new node
    Node *new_node = malloc(sizeof(Node));

    // Copy the item data into the new node
    strcpy(new_node->name, item->name);
    new_node->quantity = item->quantity;
    new_node->price = item->price;

    // Set the next pointer of the new node to the head of the linked list
    new_node->next = head;

    // Set the head of the linked list to the new node
    head = new_node;
}

// Function to remove an item from the store
void remove_item(char *name) {
    // Find the node containing the item
    Node *current_node = head;
    while (current_node != NULL && strcmp(current_node->name, name) != 0) {
        current_node = current_node->next;
    }

    // If the node was not found, return
    if (current_node == NULL) {
        return;
    }

    // If the node is the head of the linked list, set the head to the next node
    if (current_node == head) {
        head = current_node->next;
    } else {
        // Find the node before the current node
        Node *prev_node = head;
        while (prev_node->next != current_node) {
            prev_node = prev_node->next;
        }

        // Set the next pointer of the previous node to the next node of the current node
        prev_node->next = current_node->next;
    }

    // Free the current node
    free(current_node);
}

// Function to update an item in the store
void update_item(char *name, Item *item) {
    // Find the node containing the item
    Node *current_node = head;
    while (current_node != NULL && strcmp(current_node->name, name) != 0) {
        current_node = current_node->next;
    }

    // If the node was not found, return
    if (current_node == NULL) {
        return;
    }

    // Update the item data in the node
    strcpy(current_node->name, item->name);
    current_node->quantity = item->quantity;
    current_node->price = item->price;
}

// Function to print the items in the store
void print_items() {
    // Initialize the current node to the head of the linked list
    Node *current_node = head;

    // Iterate over the linked list and print the items
    while (current_node != NULL) {
        printf("%s: %d units, $%.2f\n", current_node->name, current_node->quantity, current_node->price);
        current_node = current_node->next;
    }
}