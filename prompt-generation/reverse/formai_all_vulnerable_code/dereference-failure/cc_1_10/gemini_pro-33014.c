//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the store
#define MAX_ITEMS 100

// Define the structure of an item in the store
typedef struct item {
    char name[50];
    int quantity;
    float price;
} item;

// Define the structure of the store
typedef struct store {
    item items[MAX_ITEMS];
    int num_items;
} store;

// Create a new store
store *create_store() {
    store *s = malloc(sizeof(store));
    s->num_items = 0;
    return s;
}

// Add an item to the store
void add_item(store *s, char *name, int quantity, float price) {
    if (s->num_items == MAX_ITEMS) {
        printf("Error: The store is full.\n");
    } else {
        strcpy(s->items[s->num_items].name, name);
        s->items[s->num_items].quantity = quantity;
        s->items[s->num_items].price = price;
        s->num_items++;
    }
}

// Remove an item from the store
void remove_item(store *s, char *name) {
    int i;
    for (i = 0; i < s->num_items; i++) {
        if (strcmp(s->items[i].name, name) == 0) {
            break;
        }
    }
    if (i == s->num_items) {
        printf("Error: The item '%s' is not in the store.\n", name);
    } else {
        for (i = i + 1; i < s->num_items; i++) {
            strcpy(s->items[i - 1].name, s->items[i].name);
            s->items[i - 1].quantity = s->items[i].quantity;
            s->items[i - 1].price = s->items[i].price;
        }
        s->num_items--;
    }
}

// Print the inventory of the store
void print_inventory(store *s) {
    int i;
    for (i = 0; i < s->num_items; i++) {
        printf("%s %d %.2f\n", s->items[i].name, s->items[i].quantity, s->items[i].price);
    }
}

// Free the memory allocated for the store
void free_store(store *s) {
    free(s);
}

// Main function
int main() {
    // Create a new store
    store *s = create_store();

    // Add some items to the store
    add_item(s, "Aspirin", 100, 0.50);
    add_item(s, "Ibuprofen", 50, 1.00);
    add_item(s, "Acetaminophen", 75, 0.75);

    // Print the inventory of the store
    print_inventory(s);

    // Remove an item from the store
    remove_item(s, "Ibuprofen");

    // Print the inventory of the store
    print_inventory(s);

    // Free the memory allocated for the store
    free_store(s);

    return 0;
}