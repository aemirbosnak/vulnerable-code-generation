//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products in the store
#define MAX_PRODUCTS 100

// Define the structure of a product
typedef struct Product {
    char name[50];
    float price;
    int quantity;
} Product;

// Define the structure of the medical store
typedef struct MedicalStore {
    Product products[MAX_PRODUCTS];
    int num_products;
} MedicalStore;

// Create a new medical store
MedicalStore* create_medical_store() {
    MedicalStore* store = (MedicalStore*)malloc(sizeof(MedicalStore));
    store->num_products = 0;
    return store;
}

// Add a new product to the medical store
void add_product(MedicalStore* store, Product product) {
    store->products[store->num_products] = product;
    store->num_products++;
}

// Find a product in the medical store by name
Product* find_product(MedicalStore* store, char* name) {
    for (int i = 0; i < store->num_products; i++) {
        if (strcmp(store->products[i].name, name) == 0) {
            return &store->products[i];
        }
    }
    return NULL;
}

// Sell a product in the medical store
void sell_product(MedicalStore* store, char* name, int quantity) {
    Product* product = find_product(store, name);
    if (product != NULL) {
        if (product->quantity >= quantity) {
            product->quantity -= quantity;
        } else {
            printf("Insufficient quantity of %s in stock.\n", name);
        }
    } else {
        printf("Product %s not found in stock.\n", name);
    }
}

// Print the inventory of the medical store
void print_inventory(MedicalStore* store) {
    printf("Inventory:\n");
    for (int i = 0; i < store->num_products; i++) {
        printf("%s: %d units at $%.2f each\n", store->products[i].name, store->products[i].quantity, store->products[i].price);
    }
}

// Main function
int main() {
    // Create a new medical store
    MedicalStore* store = create_medical_store();

    // Add some products to the store
    Product product1 = {"Paracetamol", 10.0, 100};
    add_product(store, product1);
    Product product2 = {"Ibuprofen", 15.0, 50};
    add_product(store, product2);
    Product product3 = {"Aspirin", 5.0, 200};
    add_product(store, product3);

    // Sell some products
    sell_product(store, "Paracetamol", 20);
    sell_product(store, "Ibuprofen", 10);

    // Print the inventory
    print_inventory(store);

    return 0;
}