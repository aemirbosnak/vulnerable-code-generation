//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// Define struct for warehouse item
typedef struct {
    int id;
    char name[20];
    float price;
    int quantity;
} Item;

// Define struct for the warehouse itself
typedef struct {
    Item items[MAX_SIZE];
    int num_items;
} Warehouse;

// Function to add item to the warehouse
void add_item(Warehouse *w, Item item) {
    w->items[w->num_items++] = item;
}

// Function to print all items in the warehouse
void print_items(Warehouse w) {
    printf("\nWarehouse Inventory:\n");
    printf("---------------------\n");
    for (int i = 0; i < w.num_items; i++) {
        printf("ID: %d\n", w.items[i].id);
        printf("Name: %s\n", w.items[i].name);
        printf("Price: %.2f\n", w.items[i].price);
        printf("Quantity: %d\n", w.items[i].quantity);
        printf("---------------------\n");
    }
}

int main() {
    // Initialize warehouse and some example items
    Warehouse w;
    Item item1 = {1, "Shoes", 29.99, 20};
    Item item2 = {2, "Hats", 12.99, 30};
    Item item3 = {3, "T-Shirts", 8.99, 50};

    // Add items to warehouse
    add_item(&w, item1);
    add_item(&w, item2);
    add_item(&w, item3);

    // Print all items in warehouse
    print_items(w);

    return 0;
}