//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Define the product struct
typedef struct {
    int id;
    char *name;
    float price;
    int quantity;
} product;

// Create a new product
product *create_product(int id, char *name, float price, int quantity) {
    product *p = (product *)malloc(sizeof(product));
    p->id = id;
    p->name = name;
    p->price = price;
    p->quantity = quantity;
    return p;
}

// Print a product
void print_product(product *p) {
    printf("ID: %d, Name: %s, Price: %.2f, Quantity: %d\n", p->id, p->name, p->price, p->quantity);
}

// Add a product to the inventory
void add_product(product **inventory, int *size, product *p) {
    *inventory = (product *)realloc(*inventory, (*size + 1) * sizeof(product));
    (*inventory)[*size] = *p;
    *size = *size + 1;
}

// Remove a product from the inventory
void remove_product(product **inventory, int *size, int id) {
    for (int i = 0; i < *size; i++) {
        if ((*inventory)[i].id == id) {
            for (int j = i + 1; j < *size; j++) {
                (*inventory)[j - 1] = (*inventory)[j];
            }
            *size = *size - 1;
            break;
        }
    }
}

// Update a product in the inventory
void update_product(product **inventory, int *size, product *p) {
    for (int i = 0; i < *size; i++) {
        if ((*inventory)[i].id == p->id) {
            (*inventory)[i] = *p;
            break;
        }
    }
}

// Search for a product in the inventory
product *search_product(product **inventory, int *size, int id) {
    for (int i = 0; i < *size; i++) {
        if ((*inventory)[i].id == id) {
            return &(*inventory)[i];
        }
    }
    return NULL;
}

// Print the inventory
void print_inventory(product **inventory, int *size) {
    printf("Inventory:\n");
    for (int i = 0; i < *size; i++) {
        print_product(&(*inventory)[i]);
    }
}

// Main function
int main() {
    // Create an inventory
    product **inventory = (product **)malloc(sizeof(product *));
    int size = 0;

    // Add some products to the inventory
    add_product(inventory, &size, create_product(1, "Product 1", 10.00, 10));
    add_product(inventory, &size, create_product(2, "Product 2", 20.00, 20));
    add_product(inventory, &size, create_product(3, "Product 3", 30.00, 30));

    // Print the inventory
    print_inventory(inventory, &size);

    // Search for a product in the inventory
    product *p = search_product(inventory, &size, 2);
    if (p != NULL) {
        printf("Found product: ");
        print_product(p);
    } else {
        printf("Product not found.\n");
    }

    // Update a product in the inventory
    update_product(inventory, &size, create_product(2, "Product 2", 25.00, 25));

    // Print the inventory
    print_inventory(inventory, &size);

    // Remove a product from the inventory
    remove_product(inventory, &size, 3);

    // Print the inventory
    print_inventory(inventory, &size);

    // Free the memory allocated for the inventory
    for (int i = 0; i < size; i++) {
        free(inventory[i]->name);
        free(inventory[i]);
    }
    free(inventory);

    return 0;
}