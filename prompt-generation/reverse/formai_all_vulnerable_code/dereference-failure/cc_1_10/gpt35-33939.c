//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct to represent a warehouse item */
typedef struct {
    char name[50];
    int quantity;
    float price;
} Warehouse_Item;

/* Struct to represent a node in the linked list */
typedef struct node {
    Warehouse_Item item;
    struct node *next;
} Node;

/* Function to add item to the warehouse */
void add_item(Node **head, Warehouse_Item item) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->item = item;
    new_node->next = (*head);
    (*head) = new_node;
    printf("Item added successfully!\n");
}

/* Function to display all items in the warehouse */
void display_items(Node *head) {
    Node *current = head;
    if (current == NULL) {
        printf("There are currently no items in the warehouse.\n");
    }
    while (current != NULL) {
        printf("Item name: %s\n", current->item.name);
        printf("Quantity: %d\n", current->item.quantity);
        printf("Price: $%.2f\n", current->item.price);
        current = current->next;
    }
}

/* Function to remove an item from the warehouse */
void remove_item(Node **head, char *name) {
    Node *current = (*head);
    Node *previous = NULL;
    int found = 0;
    while (current != NULL) {
        if (strcmp(current->item.name, name) == 0) {
            found = 1;
            if (previous == NULL) {
                (*head) = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("%s removed successfully!\n", name);
            break;
        }
        previous = current;
        current = current->next;
    }
    if (found == 0) {
        printf("Item not found in the warehouse.\n");
    }
}

int main() {
    Node *head = NULL;
    int choice;
    char name[50];
    int quantity;
    float price;
    Warehouse_Item item;

    printf("Welcome to the warehouse management system!\n");

    do {
        printf("\n1. Add item\n");
        printf("2. Display items\n");
        printf("3. Remove item\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", item.name);
                printf("Enter quantity: ");
                scanf("%d", &item.quantity);
                printf("Enter price: $");
                scanf("%f", &item.price);
                add_item(&head, item);
                break;
            case 2:
                display_items(head);
                break;
            case 3:
                printf("Enter name of item to remove: ");
                scanf("%s", name);
                remove_item(&head, name);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}