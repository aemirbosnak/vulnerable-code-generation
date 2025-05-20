//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold item data
typedef struct item {
    int id;
    char *name;
    int quantity;
    float price;
} item;

// Function to create a new item
item *create_item(int id, char *name, int quantity, float price) {
    item *new_item = malloc(sizeof(item));
    new_item->id = id;
    new_item->name = malloc(strlen(name) + 1);
    strcpy(new_item->name, name);
    new_item->quantity = quantity;
    new_item->price = price;
    return new_item;
}

// Function to add an item to the warehouse
void add_item(item **warehouse, int *num_items, item *new_item) {
    warehouse[*num_items] = new_item;
    (*num_items)++;
}

// Function to remove an item from the warehouse
void remove_item(item **warehouse, int *num_items, int id) {
    for (int i = 0; i < *num_items; i++) {
        if (warehouse[i]->id == id) {
            free(warehouse[i]->name);
            free(warehouse[i]);
            for (int j = i; j < *num_items - 1; j++) {
                warehouse[j] = warehouse[j + 1];
            }
            (*num_items)--;
            break;
        }
    }
}

// Function to find an item in the warehouse
item *find_item(item **warehouse, int num_items, int id) {
    for (int i = 0; i < num_items; i++) {
        if (warehouse[i]->id == id) {
            return warehouse[i];
        }
    }
    return NULL;
}

// Function to print the warehouse inventory
void print_inventory(item **warehouse, int num_items) {
    printf("Warehouse Inventory:\n");
    printf("--------------------\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d %s %d %.2f\n", warehouse[i]->id, warehouse[i]->name, warehouse[i]->quantity, warehouse[i]->price);
    }
    printf("\n");
}

// Function to get user input
char *get_input(char *prompt) {
    char *input = malloc(1024);
    printf("%s", prompt);
    scanf(" %[^\n]", input);
    return input;
}

// Main function
int main() {
    // Initialize the warehouse
    item **warehouse = malloc(100 * sizeof(item *));
    int num_items = 0;

    // Add some items to the warehouse
    add_item(warehouse, &num_items, create_item(1, "Apple", 10, 0.5));
    add_item(warehouse, &num_items, create_item(2, "Orange", 15, 0.75));
    add_item(warehouse, &num_items, create_item(3, "Banana", 20, 1.00));

    // Print the warehouse inventory
    print_inventory(warehouse, num_items);

    // Get user input
    char *input = get_input("Enter an item ID to remove: ");

    // Remove the item from the warehouse
    int id = atoi(input);
    remove_item(warehouse, &num_items, id);

    // Print the warehouse inventory
    print_inventory(warehouse, num_items);

    // Free the allocated memory
    for (int i = 0; i < num_items; i++) {
        free(warehouse[i]->name);
        free(warehouse[i]);
    }
    free(warehouse);
    free(input);

    return 0;
}