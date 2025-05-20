//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000

typedef struct {
    char* name;
    int quantity;
    float price;
} Item;

Item inventory[MAX_ITEMS];
int num_items = 0;

void add_item(char* name, int quantity, float price) {
    if (num_items >= MAX_ITEMS) {
        printf("Inventory is full.\n");
        return;
    }

    Item new_item;
    new_item.name = strdup(name);
    new_item.quantity = quantity;
    new_item.price = price;

    inventory[num_items++] = new_item;
}

void remove_item(int index) {
    if (index < 0 || index >= num_items) {
        printf("Invalid item index.\n");
        return;
    }

    free(inventory[index].name);
    memmove(&inventory[index], &inventory[index+1], (num_items - index - 1) * sizeof(Item));
    num_items--;
}

void update_item(int index, char* name, int quantity, float price) {
    if (index < 0 || index >= num_items) {
        printf("Invalid item index.\n");
        return;
    }

    free(inventory[index].name);
    inventory[index].name = strdup(name);
    inventory[index].quantity = quantity;
    inventory[index].price = price;
}

void display_inventory() {
    printf("Item Name\tQuantity\tPrice\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void search_item(char* name) {
    for (int i = 0; i < num_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Item found:\n");
            printf("Name: %s\n", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: %.2f\n", inventory[i].price);
            return;
        }
    }

    printf("Item not found.\n");
}

int main() {
    add_item("Apple", 100, 1.00);
    add_item("Orange", 50, 0.75);
    add_item("Banana", 200, 0.50);

    display_inventory();

    search_item("Banana");

    remove_item(1);

    display_inventory();

    update_item(0, "Red Apple", 150, 1.25);

    display_inventory();

    return 0;
}