//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LENGTH 20

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

int numItems = 0;
Item *inventory[MAX_ITEMS];

void addItem() {
    Item *newItem = (Item *)malloc(sizeof(Item));

    printf("Enter the name of the item: ");
    scanf("%s", newItem->name);

    printf("Enter the quantity of the item: ");
    scanf("%d", &newItem->quantity);

    printf("Enter the price of the item: ");
    scanf("%f", &newItem->price);

    newItem->id = numItems + 1;

    inventory[numItems] = newItem;
    numItems++;

    printf("Item added successfully!\n");
}

void removeItem() {
    int id;
    int index = -1;

    printf("Enter the ID of the item to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < numItems; i++) {
        if (inventory[i]->id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Item with ID %d not found.\n", id);
    } else {
        free(inventory[index]);

        for (int i = index; i < numItems - 1; i++) {
            inventory[i] = inventory[i + 1];
            inventory[i]->id--;
        }

        numItems--;

        printf("Item with ID %d removed successfully!\n", id);
    }
}

void listItems() {
    printf("ID\tName\tQuantity\tPrice\n");

    for (int i = 0; i < numItems; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", inventory[i]->id, inventory[i]->name, inventory[i]->quantity, inventory[i]->price);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. List items\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                removeItem();
                break;
            case 3:
                listItems();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}