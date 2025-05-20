//FormAI DATASET v1.0 Category: Product Inventory System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct item {
    int id;
    char name[50];
    int quantity;
    float cost;
};

typedef struct item Item;

int inventorySize = 0;
Item items[MAX_ITEMS];

void addItem() {
    if (inventorySize == MAX_ITEMS) {
        printf("Inventory is full!\n");
        return;
    }

    Item newItem;
    newItem.id = inventorySize + 1;

    printf("Enter the name of the item (up to 50 characters): ");
    scanf("%s", newItem.name);

    printf("Enter the quantity of the item: ");
    scanf("%d", &newItem.quantity);

    printf("Enter the cost of the item: ");
    scanf("%f", &newItem.cost);

    items[inventorySize] = newItem;
    inventorySize++;

    printf("\nItem added successfully!\n\n");
}

void removeItem() {
    if (inventorySize == 0) {
        printf("Inventory is empty!\n");
        return;
    }

    int itemId;
    printf("Enter the ID of the item to be removed: ");
    scanf("%d", &itemId);

    // Find item
    int index = -1;
    for (int i = 0; i < inventorySize; i++) {
        if (items[i].id == itemId) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Item not found!\n\n");
        return;
    }

    // Shift items back
    for (int i = index; i < inventorySize - 1; i++) {
        items[i] = items[i + 1];
    }

    inventorySize--;
    printf("Item removed successfully!\n\n");
}

void displayInventory() {
    printf("\nInventory:\n");
    
    if (inventorySize == 0) {
        printf("Empty\n");
        return;
    }

    printf("ID\tName\t\tQuantity\tCost\n");
    printf("-------------------------------------------------------\n");
    
    for (int i = 0; i < inventorySize; i++) {
        Item item = items[i];
        printf("%d\t%s\t\t%d\t\t%.2f\n", item.id, item.name, item.quantity, item.cost);
    }

    printf("\n");
}

void saveToFile() {
    FILE *fp = fopen("inventory.txt", "w");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    // Save inventory to file
    for (int i = 0; i < inventorySize; i++) {
        Item item = items[i];
        fprintf(fp, "%d-%s-%d-%.2f\n", item.id, item.name, item.quantity, item.cost);
    }

    fclose(fp);
    printf("Inventory saved to file!\n");
}

void loadFromFile() {
    FILE *fp = fopen("inventory.txt", "r");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Clear inventory
    inventorySize = 0;

    // Load inventory from file
    char line[100];

    while (fgets(line, sizeof(line), fp)) {
        // Get values from line
        char *id = strtok(line, "-");
        char *name = strtok(NULL, "-");
        char *quantity = strtok(NULL, "-");
        char *cost = strtok(NULL, "-");

        // Create new item
        Item item;
        item.id = atoi(id);
        strcpy(item.name, name);
        item.quantity = atoi(quantity);
        item.cost = atof(cost);

        // Add item to inventory
        items[inventorySize] = item;
        inventorySize++;
    }

    fclose(fp);
    printf("Inventory loaded from file!\n");
}

int main() {
    int choice;

    do {
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Inventory\n");
        printf("4. Save Inventory to File\n");
        printf("5. Load Inventory from File\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                removeItem();
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                saveToFile();
                break;
            case 5:
                loadFromFile();
                break;
            case 6:
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nInvalid choice!\n\n");
                break;
        }
    } while (choice != 6);

    return 0;
}