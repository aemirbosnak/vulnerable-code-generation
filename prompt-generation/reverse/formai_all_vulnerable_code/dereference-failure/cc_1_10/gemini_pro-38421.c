//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Shannon's Entropy Function
double entropy(int* freq, int n) {
    double ent = 0;
    for (int i = 0; i < n; i++) {
        if (freq[i] > 0) {
            double p = (double)freq[i] / n;
            ent -= p * log2(p);
        }
    }
    return ent;
}

// Product Inventory System
struct product {
    int id;
    char* name;
    int quantity;
    double price;
};

// Create a new product
struct product* create_product(int id, char* name, int quantity, double price) {
    struct product* p = malloc(sizeof(struct product));
    p->id = id;
    p->name = malloc(strlen(name) + 1);
    strcpy(p->name, name);
    p->quantity = quantity;
    p->price = price;
    return p;
}

// Add a product to the inventory
void add_product(struct product*** inventory, int* n, struct product* product) {
    *inventory = realloc(*inventory, (*n + 1) * sizeof(struct product*));
    (*inventory)[*n] = product;
    (*n)++;
}

// Search for a product by ID
struct product* find_product_by_id(struct product** inventory, int n, int id) {
    for (int i = 0; i < n; i++) {
        if (inventory[i]->id == id) {
            return inventory[i];
        }
    }
    return NULL;
}

// Search for a product by name
struct product* find_product_by_name(struct product** inventory, int n, char* name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(inventory[i]->name, name) == 0) {
            return inventory[i];
        }
    }
    return NULL;
}

// Print the inventory
void print_inventory(struct product** inventory, int n) {
    printf("Product Inventory:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %f\n", inventory[i]->id, inventory[i]->name, inventory[i]->quantity, inventory[i]->price);
    }
}

// Calculate the total value of the inventory
double calculate_total_value(struct product** inventory, int n) {
    double total = 0;
    for (int i = 0; i < n; i++) {
        total += inventory[i]->quantity * inventory[i]->price;
    }
    return total;
}

// Calculate the entropy of the inventory
double calculate_entropy(struct product** inventory, int n) {
    int freq[n];
    for (int i = 0; i < n; i++) {
        freq[i] = inventory[i]->quantity;
    }
    return entropy(freq, n);
}

int main() {
    // Initialize the inventory
    struct product** inventory = NULL;
    int inventory_size = 0;

    // Add some products to the inventory
    add_product(&inventory, &inventory_size, create_product(1, "Apple", 5, 1.5));
    add_product(&inventory, &inventory_size, create_product(2, "Banana", 10, 2.0));
    add_product(&inventory, &inventory_size, create_product(3, "Orange", 7, 2.5));
    add_product(&inventory, &inventory_size, create_product(4, "Grape", 12, 3.0));

    // Print the inventory
    print_inventory(inventory, inventory_size);

    // Search for a product by ID
    struct product* product = find_product_by_id(inventory, inventory_size, 3);
    printf("Product found by ID: %d, Name: %s, Quantity: %d, Price: %f\n", product->id, product->name, product->quantity, product->price);

    // Search for a product by name
    product = find_product_by_name(inventory, inventory_size, "Banana");
    printf("Product found by name: %d, ID: %s, Quantity: %d, Price: %f\n", product->id, product->name, product->quantity, product->price);

    // Calculate the total value of the inventory
    double total_value = calculate_total_value(inventory, inventory_size);
    printf("Total value of the inventory: %f\n", total_value);

    // Calculate the entropy of the inventory
    double entropy = calculate_entropy(inventory, inventory_size);
    printf("Entropy of the inventory: %f\n", entropy);

    // Clean up the inventory
    for (int i = 0; i < inventory_size; i++) {
        free(inventory[i]->name);
        free(inventory[i]);
    }
    free(inventory);

    return 0;
}