//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The main inventory structure */
struct Inventory {
    char *name;
    int quantity;
    float price;
};

/* Create a new inventory item */
struct Inventory *new_inventory(char *name, int quantity, float price) {
    struct Inventory *item = malloc(sizeof(struct Inventory));
    item->name = strdup(name);
    item->quantity = quantity;
    item->price = price;
    return item;
}

/* Delete an inventory item */
void delete_inventory(struct Inventory *item) {
    free(item->name);
    free(item);
}

/* Print an inventory item */
void print_inventory(struct Inventory *item) {
    printf("%s: %d @ $%.2f\n", item->name, item->quantity, item->price);
}

/* The main inventory array */
struct Inventory *inventory[100];

/* The number of items in the inventory */
int inventory_count = 0;

/* Add an item to the inventory */
void add_inventory(struct Inventory *item) {
    inventory[inventory_count++] = item;
}

/* Remove an item from the inventory */
void remove_inventory(struct Inventory *item) {
    for (int i = 0; i < inventory_count; i++) {
        if (inventory[i] == item) {
            for (int j = i + 1; j < inventory_count; j++) {
                inventory[j - 1] = inventory[j];
            }
            inventory_count--;
            break;
        }
    }
}

/* Find an item in the inventory by name */
struct Inventory *find_inventory(char *name) {
    for (int i = 0; i < inventory_count; i++) {
        if (!strcmp(inventory[i]->name, name)) {
            return inventory[i];
        }
    }
    return NULL;
}

/* Print the entire inventory */
void print_inventory_list() {
    for (int i = 0; i < inventory_count; i++) {
        print_inventory(inventory[i]);
    }
}

/* The main function */
int main() {
    /* Add some items to the inventory */
    add_inventory(new_inventory("Apple", 10, 0.50));
    add_inventory(new_inventory("Orange", 5, 0.75));
    add_inventory(new_inventory("Banana", 15, 1.00));

    /* Print the inventory */
    print_inventory_list();

    /* Find an item in the inventory */
    struct Inventory *item = find_inventory("Orange");

    /* Print the item */
    print_inventory(item);

    /* Remove the item from the inventory */
    remove_inventory(item);

    /* Print the inventory again */
    print_inventory_list();

    return 0;
}