//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product structure
typedef struct product {
    int id;
    char name[50];
    int quantity;
    float price;
} product;

// Function to create a new product
product* create_product(int id, char* name, int quantity, float price) {
    product* new_product = (product*)malloc(sizeof(product));
    new_product->id = id;
    strcpy(new_product->name, name);
    new_product->quantity = quantity;
    new_product->price = price;
    return new_product;
}

// Function to display a product
void display_product(product* product) {
    printf("ID: %d\n", product->id);
    printf("Name: %s\n", product->name);
    printf("Quantity: %d\n", product->quantity);
    printf("Price: %.2f\n", product->price);
}

// Function to add a product to the inventory
void add_product(product** inventory, int* size, product* new_product) {
    *inventory = (product*)realloc(*inventory, (*size + 1) * sizeof(product));
    (*inventory)[*size] = *new_product;
    (*size)++;
}

// Function to remove a product from the inventory
void remove_product(product** inventory, int* size, int id) {
    int index = -1;
    for (int i = 0; i < *size; i++) {
        if ((*inventory)[i].id == id) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < *size - 1; i++) {
            (*inventory)[i] = (*inventory)[i + 1];
        }
        (*size)--;
        *inventory = (product*)realloc(*inventory, *size * sizeof(product));
    }
}

// Function to update a product in the inventory
void update_product(product** inventory, int* size, int id, char* name, int quantity, float price) {
    int index = -1;
    for (int i = 0; i < *size; i++) {
        if ((*inventory)[i].id == id) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        strcpy((*inventory)[index].name, name);
        (*inventory)[index].quantity = quantity;
        (*inventory)[index].price = price;
    }
}

// Function to search for a product in the inventory
product* search_product(product** inventory, int* size, int id) {
    product* result = NULL;
    for (int i = 0; i < *size; i++) {
        if ((*inventory)[i].id == id) {
            result = &(*inventory)[i];
            break;
        }
    }
    return result;
}

// Function to display the entire inventory
void display_inventory(product** inventory, int* size) {
    printf("Inventory:\n");
    for (int i = 0; i < *size; i++) {
        display_product(&(*inventory)[i]);
        printf("\n");
    }
}

// Main function
int main() {
    // Create an empty inventory
    product* inventory = NULL;
    int size = 0;

    // Add some products to the inventory
    product* product1 = create_product(1, "Apple", 10, 1.0);
    add_product(&inventory, &size, product1);

    product* product2 = create_product(2, "Orange", 15, 1.5);
    add_product(&inventory, &size, product2);

    product* product3 = create_product(3, "Banana", 20, 2.0);
    add_product(&inventory, &size, product3);

    // Display the inventory
    display_inventory(&inventory, &size);

    // Search for a product in the inventory
    product* product = search_product(&inventory, &size, 2);
    if (product != NULL) {
        printf("Found product:\n");
        display_product(product);
    } else {
        printf("Product not found.\n");
    }

    // Update a product in the inventory
    update_product(&inventory, &size, 3, "Mango", 25, 2.5);

    // Display the inventory again
    printf("\nUpdated inventory:\n");
    display_inventory(&inventory, &size);

    // Remove a product from the inventory
    remove_product(&inventory, &size, 1);

    // Display the inventory again
    printf("\nInventory after removing product:\n");
    display_inventory(&inventory, &size);

    // Free the memory allocated to the inventory
    for (int i = 0; i < size; i++) {
        free(&inventory[i]);
    }
    free(inventory);

    return 0;
}