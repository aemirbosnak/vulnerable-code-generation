//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store product information
typedef struct product {
    char name[50];
    int quantity;
    float price;
} product;

// Function to create a new product
product* create_product(char* name, int quantity, float price) {
    product* new_product = (product*)malloc(sizeof(product));
    strcpy(new_product->name, name);
    new_product->quantity = quantity;
    new_product->price = price;
    return new_product;
}

// Function to add a product to the inventory
void add_product(product* inventory[], int* size, product* new_product) {
    inventory[*size] = new_product;
    (*size)++;
}

// Function to remove a product from the inventory
void remove_product(product* inventory[], int* size, char* name) {
    int index = -1;
    for (int i = 0; i < *size; i++) {
        if (strcmp(inventory[i]->name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < *size - 1; i++) {
            inventory[i] = inventory[i + 1];
        }
        (*size)--;
    }
}

// Function to update the quantity of a product in the inventory
void update_quantity(product* inventory[], int* size, char* name, int new_quantity) {
    int index = -1;
    for (int i = 0; i < *size; i++) {
        if (strcmp(inventory[i]->name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        inventory[index]->quantity = new_quantity;
    }
}

// Function to print the inventory
void print_inventory(product* inventory[], int size) {
    printf("Product Inventory:\n");
    for (int i = 0; i < size; i++) {
        printf("%s %d %.2f\n", inventory[i]->name, inventory[i]->quantity, inventory[i]->price);
    }
}

int main() {
    // Create the product inventory
    product* inventory[100];
    int size = 0;

    // Add some products to the inventory
    add_product(inventory, &size, create_product("Apple", 10, 1.0));
    add_product(inventory, &size, create_product("Banana", 20, 1.5));
    add_product(inventory, &size, create_product("Orange", 15, 2.0));

    // Print the inventory
    print_inventory(inventory, size);

    // Remove a product from the inventory
    remove_product(inventory, &size, "Banana");

    // Print the inventory
    print_inventory(inventory, size);

    // Update the quantity of a product in the inventory
    update_quantity(inventory, &size, "Apple", 15);

    // Print the inventory
    print_inventory(inventory, size);

    return 0;
}