//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products that can be stored in the system
#define MAX_PRODUCTS 100

// Define the structure of a product
typedef struct {
    char name[50];
    char description[100];
    float price;
    int quantity;
} Product;

// Define the structure of the medical store
typedef struct {
    Product products[MAX_PRODUCTS];
    int num_products;
} MedicalStore;

// Create a new medical store
MedicalStore* create_medical_store() {
    MedicalStore* store = (MedicalStore*) malloc(sizeof(MedicalStore));
    store->num_products = 0;
    return store;
}

// Add a new product to the medical store
void add_product(MedicalStore* store, Product product) {
    if (store->num_products < MAX_PRODUCTS) {
        store->products[store->num_products] = product;
        store->num_products++;
    } else {
        printf("Error: The medical store is full.\n");
    }
}

// Search for a product in the medical store by name
Product* search_product_by_name(MedicalStore* store, char* name) {
    for (int i = 0; i < store->num_products; i++) {
        if (strcmp(store->products[i].name, name) == 0) {
            return &store->products[i];
        }
    }
    return NULL;
}

// Search for a product in the medical store by description
Product* search_product_by_description(MedicalStore* store, char* description) {
    for (int i = 0; i < store->num_products; i++) {
        if (strcmp(store->products[i].description, description) == 0) {
            return &store->products[i];
        }
    }
    return NULL;
}

// Print the details of all products in the medical store
void print_products(MedicalStore* store) {
    for (int i = 0; i < store->num_products; i++) {
        printf("Product %d:\n", i + 1);
        printf("Name: %s\n", store->products[i].name);
        printf("Description: %s\n", store->products[i].description);
        printf("Price: %.2f\n", store->products[i].price);
        printf("Quantity: %d\n", store->products[i].quantity);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new medical store
    MedicalStore* store = create_medical_store();

    // Add some products to the medical store
    Product product1 = {"Paracetamol", "A pain reliever", 10.0, 50};
    add_product(store, product1);

    Product product2 = {"Ibuprofen", "An anti-inflammatory drug", 15.0, 25};
    add_product(store, product2);

    Product product3 = {"Aspirin", "A blood thinner", 5.0, 100};
    add_product(store, product3);

    // Print the details of all products in the medical store
    print_products(store);

    // Search for a product in the medical store by name
    Product* product = search_product_by_name(store, "Ibuprofen");
    if (product != NULL) {
        printf("Product found:\n");
        printf("Name: %s\n", product->name);
        printf("Description: %s\n", product->description);
        printf("Price: %.2f\n", product->price);
        printf("Quantity: %d\n", product->quantity);
        printf("\n");
    } else {
        printf("Product not found.\n");
    }

    // Search for a product in the medical store by description
    product = search_product_by_description(store, "A blood thinner");
    if (product != NULL) {
        printf("Product found:\n");
        printf("Name: %s\n", product->name);
        printf("Description: %s\n", product->description);
        printf("Price: %.2f\n", product->price);
        printf("Quantity: %d\n", product->quantity);
        printf("\n");
    } else {
        printf("Product not found.\n");
    }

    return 0;
}