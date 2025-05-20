//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store medical store items
typedef struct Item {
    char name[50];
    int quantity;
    float price;
} Item;

// Define a function to manage inventory
void manageInventory(Item items[], int numItems) {
    // Display the inventory
    printf("Inventory:");
    for (int i = 0; i < numItems; i++) {
        printf("\n%s: %d, $%.2f", items[i].name, items[i].quantity, items[i].price);
    }

    // Get the item name
    char itemName[50];
    printf("\nEnter item name:");
    scanf("%s", itemName);

    // Get the item quantity
    int itemQuantity;
    printf("Enter item quantity:");
    scanf("%d", &itemQuantity);

    // Find the item in the inventory
    int itemIndex = -1;
    for (int i = 0; i < numItems; i++) {
        if (strcmp(items[i].name, itemName) == 0) {
            itemIndex = i;
        }
    }

    // If the item is found, update its quantity
    if (itemIndex != -1) {
        items[itemIndex].quantity += itemQuantity;
    } else {
        // If the item is not found, add it to the inventory
        Item newItem;
        strcpy(newItem.name, itemName);
        newItem.quantity = itemQuantity;
        newItem.price = 0.0;
        items = realloc(items, (numItems + 1) * sizeof(Item));
        items[numItems++] = newItem;
    }

    // Save the inventory
    FILE *fp = fopen("inventory.txt", "w");
    fprintf(fp, "Inventory:");
    for (int i = 0; i < numItems; i++) {
        fprintf(fp, "\n%s: %d, $%.2f", items[i].name, items[i].quantity, items[i].price);
    }
    fclose(fp);
}

int main() {
    // Create an array of items
    Item items[] = {
        {"Acetaminophen", 100, 5.0},
        {"Ibuprofen", 50, 6.0},
        {"Tylenol", 25, 4.0}
    };

    // Manage the inventory
    manageInventory(items, 3);

    return 0;
}