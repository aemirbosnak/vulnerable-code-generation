//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the store
#define MAX_ITEMS 100

// Define the structure of an item in the store
typedef struct item {
    char name[50];
    char description[100];
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
    store *s = (store *)malloc(sizeof(store));
    s->num_items = 0;
    return s;
}

// Add an item to the store
void add_item(store *s, item *i) {
    if (s->num_items < MAX_ITEMS) {
        s->items[s->num_items] = *i;
        s->num_items++;
    } else {
        printf("Error: Store is full.\n");
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
    if (i < s->num_items) {
        for (int j = i + 1; j < s->num_items; j++) {
            s->items[j - 1] = s->items[j];
        }
        s->num_items--;
    } else {
        printf("Error: Item not found.\n");
    }
}

// Find an item in the store
item *find_item(store *s, char *name) {
    int i;
    for (i = 0; i < s->num_items; i++) {
        if (strcmp(s->items[i].name, name) == 0) {
            return &s->items[i];
        }
    }
    return NULL;
}

// Print the inventory of the store
void print_inventory(store *s) {
    int i;
    for (i = 0; i < s->num_items; i++) {
        printf("%s - %s - %d - %f\n", s->items[i].name, s->items[i].description, s->items[i].quantity, s->items[i].price);
    }
}

// Main function
int main() {
    // Create a new store
    store *s = create_store();

    // Add some items to the store
    item i1 = {"Aspirin", "Pain reliever", 100, 0.50};
    add_item(s, &i1);
    item i2 = {"Ibuprofen", "Pain reliever", 50, 0.75};
    add_item(s, &i2);
    item i3 = {"Acetaminophen", "Pain reliever", 25, 0.25};
    add_item(s, &i3);

    // Print the inventory of the store
    print_inventory(s);

    // Find an item in the store
    item *i = find_item(s, "Ibuprofen");
    if (i != NULL) {
        printf("Found item: %s - %s - %d - %f\n", i->name, i->description, i->quantity, i->price);
    } else {
        printf("Item not found.\n");
    }

    // Remove an item from the store
    remove_item(s, "Acetaminophen");

    // Print the inventory of the store
    print_inventory(s);

    return 0;
}