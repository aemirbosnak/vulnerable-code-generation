//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
} InventoryItem;

typedef struct Node {
    InventoryItem item;
    struct Node *next;
} Node;

Node *head = NULL;

void addItemToInventory(char *name, int qty) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->item.name, name);
    newNode->item.quantity = qty;
    newNode->next = head;
    head = newNode;
}

void displayInventory() {
    Node *current = head;
    printf("\n---------------------\n|   Medieval Warehouse |\n---------------------\n");
    printf("|   Current Inventory |\n---------------------\n");
    while (current != NULL) {
        printf("| %-45s | %5d |\n", current->item.name, current->item.quantity);
        current = current->next;
    }
}

int main() {
    char name[MAX_NAME_LEN];
    int qty, choice;

    printf("\n---------------------\n|   Medieval Warehouse |\n---------------------\n");
    printf("| Welcome, noble Lord! |\n---------------------\n");

    while (1) {
        printf("\n1. Add an item to the inventory.\n2. Display the current inventory.\n3. Quit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the item: ");
                scanf("%s", name);
                printf("Enter the quantity: ");
                scanf("%d", &qty);
                addItemToInventory(name, qty);
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                printf("Farewell, noble Lord!\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}