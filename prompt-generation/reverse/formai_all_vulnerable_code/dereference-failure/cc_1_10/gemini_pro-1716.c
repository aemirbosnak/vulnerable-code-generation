//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be stored in the warehouse
#define MAX_ITEMS 100

// Define the maximum length of a product name
#define MAX_NAME_LENGTH 50

// Define the structure of a product
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} product;

// Define the structure of the warehouse
typedef struct {
    product products[MAX_ITEMS];
    int num_products;
} warehouse;

// Function to create a new warehouse
warehouse* create_warehouse() {
    warehouse* w = malloc(sizeof(warehouse));
    w->num_products = 0;
    return w;
}

// Function to add a product to the warehouse
void add_product(warehouse* w, product p) {
    if (w->num_products < MAX_ITEMS) {
        w->products[w->num_products] = p;
        w->num_products++;
    } else {
        printf("Error: Warehouse is full!\n");
    }
}

// Function to remove a product from the warehouse
void remove_product(warehouse* w, int id) {
    int i;
    for (i = 0; i < w->num_products; i++) {
        if (w->products[i].id == id) {
            break;
        }
    }

    if (i < w->num_products) {
        for (int j = i + 1; j < w->num_products; j++) {
            w->products[j - 1] = w->products[j];
        }
        w->num_products--;
    } else {
        printf("Error: Product not found!\n");
    }
}

// Function to find a product in the warehouse
product* find_product(warehouse* w, int id) {
    int i;
    for (i = 0; i < w->num_products; i++) {
        if (w->products[i].id == id) {
            return &w->products[i];
        }
    }

    return NULL;
}

// Function to print the contents of the warehouse
void print_warehouse(warehouse* w) {
    printf("\nWarehouse Contents:\n");
    for (int i = 0; i < w->num_products; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", w->products[i].id, w->products[i].name, w->products[i].quantity, w->products[i].price);
    }
}

// Function to test the warehouse management system
int main() {
    // Create a new warehouse
    warehouse* w = create_warehouse();

    // Add some products to the warehouse
    product p1 = {1, "Product 1", 10, 10.00};
    product p2 = {2, "Product 2", 20, 20.00};
    product p3 = {3, "Product 3", 30, 30.00};
    add_product(w, p1);
    add_product(w, p2);
    add_product(w, p3);

    // Print the contents of the warehouse
    print_warehouse(w);

    // Find a product in the warehouse
    product* p = find_product(w, 2);
    if (p != NULL) {
        printf("\nFound product: ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", p->id, p->name, p->quantity, p->price);
    } else {
        printf("\nError: Product not found!\n");
    }

    // Remove a product from the warehouse
    remove_product(w, 2);

    // Print the contents of the warehouse
    print_warehouse(w);

    return 0;
}