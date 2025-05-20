//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products that can be stored in the system
#define MAX_PRODUCTS 100

// Define the structure of a product
typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} product;

// Define the structure of the medical store
typedef struct {
    product products[MAX_PRODUCTS];
    int num_products;
} medical_store;

// Create a new medical store
medical_store* create_medical_store() {
    medical_store* store = (medical_store*)malloc(sizeof(medical_store));
    store->num_products = 0;
    return store;
}

// Add a product to the medical store
void add_product(medical_store* store, product* p) {
    if (store->num_products < MAX_PRODUCTS) {
        store->products[store->num_products] = *p;
        store->num_products++;
    } else {
        printf("Error: Maximum number of products reached.\n");
    }
}

// Remove a product from the medical store
void remove_product(medical_store* store, int id) {
    int i;
    for (i = 0; i < store->num_products; i++) {
        if (store->products[i].id == id) {
            break;
        }
    }

    if (i < store->num_products) {
        for (int j = i; j < store->num_products - 1; j++) {
            store->products[j] = store->products[j + 1];
        }
        store->num_products--;
    } else {
        printf("Error: Product not found.\n");
    }
}

// Update the price of a product
void update_price(medical_store* store, int id, float new_price) {
    int i;
    for (i = 0; i < store->num_products; i++) {
        if (store->products[i].id == id) {
            break;
        }
    }

    if (i < store->num_products) {
        store->products[i].price = new_price;
    } else {
        printf("Error: Product not found.\n");
    }
}

// Update the quantity of a product
void update_quantity(medical_store* store, int id, int new_quantity) {
    int i;
    for (i = 0; i < store->num_products; i++) {
        if (store->products[i].id == id) {
            break;
        }
    }

    if (i < store->num_products) {
        store->products[i].quantity = new_quantity;
    } else {
        printf("Error: Product not found.\n");
    }
}

// Print the details of all products in the medical store
void print_products(medical_store* store) {
    int i;
    for (i = 0; i < store->num_products; i++) {
        printf("Product ID: %d\n", store->products[i].id);
        printf("Product Name: %s\n", store->products[i].name);
        printf("Product Price: %.2f\n", store->products[i].price);
        printf("Product Quantity: %d\n\n", store->products[i].quantity);
    }
}

// Main function
int main() {
    // Create a new medical store
    medical_store* store = create_medical_store();

    // Add some products to the medical store
    product p1 = {1, "Paracetamol", 10.0, 100};
    product p2 = {2, "Ibuprofen", 15.0, 50};
    product p3 = {3, "Aspirin", 5.0, 200};
    add_product(store, &p1);
    add_product(store, &p2);
    add_product(store, &p3);

    // Print the details of all products in the medical store
    print_products(store);

    // Remove a product from the medical store
    remove_product(store, 2);

    // Update the price of a product
    update_price(store, 1, 12.0);

    // Update the quantity of a product
    update_quantity(store, 3, 300);

    // Print the details of all products in the medical store
    print_products(store);

    // Free the memory allocated for the medical store
    free(store);

    return 0;
}