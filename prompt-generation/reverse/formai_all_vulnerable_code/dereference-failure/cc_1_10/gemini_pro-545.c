//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure to represent a product
typedef struct product {
    int id;
    char *name;
    int quantity;
    float price;
} product;

// Global variables
product *inventory;
int num_products;
pthread_mutex_t inventory_lock;

// Function to add a product to the inventory
void add_product(int id, char *name, int quantity, float price) {
    // Acquire the lock
    pthread_mutex_lock(&inventory_lock);

    // Create a new product
    product *new_product = (product *)malloc(sizeof(product));
    new_product->id = id;
    new_product->name = name;
    new_product->quantity = quantity;
    new_product->price = price;

    // Add the new product to the inventory
    inventory[num_products++] = *new_product;

    // Release the lock
    pthread_mutex_unlock(&inventory_lock);
}

// Function to remove a product from the inventory
void remove_product(int id) {
    // Acquire the lock
    pthread_mutex_lock(&inventory_lock);

    // Find the product to remove
    int i;
    for (i = 0; i < num_products; i++) {
        if (inventory[i].id == id) {
            break;
        }
    }

    // If the product was found, remove it from the inventory
    if (i < num_products) {
        for (i; i < num_products - 1; i++) {
            inventory[i] = inventory[i + 1];
        }
        num_products--;
    }

    // Release the lock
    pthread_mutex_unlock(&inventory_lock);
}

// Function to get the product with the specified ID
product *get_product(int id) {
    // Acquire the lock
    pthread_mutex_lock(&inventory_lock);

    // Find the product with the specified ID
    int i;
    for (i = 0; i < num_products; i++) {
        if (inventory[i].id == id) {
            break;
        }
    }

    // If the product was found, return it
    if (i < num_products) {
        pthread_mutex_unlock(&inventory_lock);
        return &inventory[i];
    }

    // Otherwise, return NULL
    pthread_mutex_unlock(&inventory_lock);
    return NULL;
}

// Function to print the inventory
void print_inventory() {
    // Acquire the lock
    pthread_mutex_lock(&inventory_lock);

    // Print the inventory
    int i;
    for (i = 0; i < num_products; i++) {
        printf("Product %d: %s, Quantity: %d, Price: %.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }

    // Release the lock
    pthread_mutex_unlock(&inventory_lock);
}

// Main function
int main() {
    // Initialize the inventory
    inventory = (product *)malloc(100 * sizeof(product));
    num_products = 0;

    // Initialize the mutex
    pthread_mutex_init(&inventory_lock, NULL);

    // Create a few products
    add_product(1, "Apple", 10, 1.0);
    add_product(2, "Orange", 15, 1.5);
    add_product(3, "Banana", 20, 2.0);

    // Print the inventory
    print_inventory();

    // Remove a product
    remove_product(2);

    // Print the inventory again
    print_inventory();

    // Destroy the mutex
    pthread_mutex_destroy(&inventory_lock);

    // Free the inventory
    free(inventory);

    return 0;
}