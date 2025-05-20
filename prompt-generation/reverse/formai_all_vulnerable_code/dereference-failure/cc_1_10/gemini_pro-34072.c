//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products in the warehouse
#define MAX_PRODUCTS 100

// Define the maximum length of a product name
#define MAX_PRODUCT_NAME_LENGTH 50

// Define the maximum length of a product description
#define MAX_PRODUCT_DESCRIPTION_LENGTH 200

// Define the structure of a product
typedef struct {
    int id;
    char name[MAX_PRODUCT_NAME_LENGTH];
    char description[MAX_PRODUCT_DESCRIPTION_LENGTH];
    int quantity;
    float price;
} product;

// Define the structure of the warehouse
typedef struct {
    product products[MAX_PRODUCTS];
    int num_products;
} warehouse;

// Create a new warehouse
warehouse* create_warehouse() {
    warehouse* w = malloc(sizeof(warehouse));
    w->num_products = 0;
    return w;
}

// Add a product to the warehouse
void add_product(warehouse* w, product p) {
    w->products[w->num_products++] = p;
}

// Find a product in the warehouse by its id
product* find_product_by_id(warehouse* w, int id) {
    for (int i = 0; i < w->num_products; i++) {
        if (w->products[i].id == id) {
            return &w->products[i];
        }
    }
    return NULL;
}

// Find a product in the warehouse by its name
product* find_product_by_name(warehouse* w, char* name) {
    for (int i = 0; i < w->num_products; i++) {
        if (strcmp(w->products[i].name, name) == 0) {
            return &w->products[i];
        }
    }
    return NULL;
}

// Print the products in the warehouse
void print_products(warehouse* w) {
    for (int i = 0; i < w->num_products; i++) {
        printf("Product %d:\n", w->products[i].id);
        printf("    Name: %s\n", w->products[i].name);
        printf("    Description: %s\n", w->products[i].description);
        printf("    Quantity: %d\n", w->products[i].quantity);
        printf("    Price: %f\n", w->products[i].price);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new warehouse
    warehouse* w = create_warehouse();

    // Add some products to the warehouse
    product p1 = {1, "Apple", "A delicious fruit", 10, 1.00};
    product p2 = {2, "Banana", "Another delicious fruit", 15, 1.50};
    product p3 = {3, "Orange", "A healthy fruit", 20, 2.00};
    add_product(w, p1);
    add_product(w, p2);
    add_product(w, p3);

    // Print the products in the warehouse
    print_products(w);

    // Find a product in the warehouse by its id
    product* p4 = find_product_by_id(w, 2);
    if (p4 != NULL) {
        printf("Found product by id: %d\n", p4->id);
        printf("    Name: %s\n", p4->name);
        printf("    Description: %s\n", p4->description);
        printf("    Quantity: %d\n", p4->quantity);
        printf("    Price: %f\n", p4->price);
        printf("\n");
    } else {
        printf("Product not found\n");
    }

    // Find a product in the warehouse by its name
    product* p5 = find_product_by_name(w, "Banana");
    if (p5 != NULL) {
        printf("Found product by name: %s\n", p5->name);
        printf("    Id: %d\n", p5->id);
        printf("    Description: %s\n", p5->description);
        printf("    Quantity: %d\n", p5->quantity);
        printf("    Price: %f\n", p5->price);
        printf("\n");
    } else {
        printf("Product not found\n");
    }

    return 0;
}