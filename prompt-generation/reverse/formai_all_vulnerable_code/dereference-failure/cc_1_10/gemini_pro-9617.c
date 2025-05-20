//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *description;
    int quantity;
    float price;
} Product;

// Create a new product
Product *create_product(char *name, char *description, int quantity, float price) {
    Product *product = malloc(sizeof(Product));
    product->name = malloc(strlen(name) + 1);
    strcpy(product->name, name);
    product->description = malloc(strlen(description) + 1);
    strcpy(product->description, description);
    product->quantity = quantity;
    product->price = price;
    return product;
}

// Print a product
void print_product(Product *product) {
    printf("Name: %s\n", product->name);
    printf("Description: %s\n", product->description);
    printf("Quantity: %d\n", product->quantity);
    printf("Price: %f\n", product->price);
}

// Add a product to the inventory
void add_product(Product **inventory, int *num_products, Product *product) {
    inventory[*num_products] = product;
    (*num_products)++;
}

// Remove a product from the inventory
void remove_product(Product **inventory, int *num_products, int index) {
    for (int i = index; i < *num_products - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    (*num_products)--;
}

// Find a product by name
Product *find_product(Product **inventory, int num_products, char *name) {
    for (int i = 0; i < num_products; i++) {
        if (strcmp(inventory[i]->name, name) == 0) {
            return inventory[i];
        }
    }
    return NULL;
}

// Print the inventory
void print_inventory(Product **inventory, int num_products) {
    for (int i = 0; i < num_products; i++) {
        print_product(inventory[i]);
        printf("\n");
    }
}

int main() {
    // Create the inventory
    Product **inventory = malloc(sizeof(Product *) * 100);
    int num_products = 0;

    // Add some products to the inventory
    add_product(inventory, &num_products, create_product("HoloLens", "Mixed reality headset", 10, 399.99));
    add_product(inventory, &num_products, create_product("Oculus Rift", "Virtual reality headset", 15, 499.99));
    add_product(inventory, &num_products, create_product("PlayStation VR", "Virtual reality headset", 20, 399.99));
    add_product(inventory, &num_products, create_product("HTC Vive", "Virtual reality headset", 12, 599.99));
    add_product(inventory, &num_products, create_product("Samsung Gear VR", "Virtual reality headset", 8, 99.99));

    // Print the inventory
    print_inventory(inventory, num_products);

    // Find a product by name
    Product *product = find_product(inventory, num_products, "HoloLens");
    if (product != NULL) {
        print_product(product);
    } else {
        printf("Product not found.\n");
    }

    // Remove a product from the inventory
    remove_product(inventory, &num_products, 2);

    // Print the inventory
    print_inventory(inventory, num_products);

    // Free the memory
    for (int i = 0; i < num_products; i++) {
        free(inventory[i]->name);
        free(inventory[i]->description);
        free(inventory[i]);
    }
    free(inventory);

    return 0;
}