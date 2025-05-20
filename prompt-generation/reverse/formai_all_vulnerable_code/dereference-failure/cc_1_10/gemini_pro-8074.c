//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a product
typedef struct Product {
    int product_id;
    char *product_name;
    int quantity;
    float price;
} Product;

// Function to create a new product
Product *createProduct(int product_id, char *product_name, int quantity, float price) {
    Product *product = (Product *)malloc(sizeof(Product));
    product->product_id = product_id;
    product->product_name = strdup(product_name);
    product->quantity = quantity;
    product->price = price;
    return product;
}

// Function to add a new product to the inventory
void addProduct(Product **inventory, int *inventory_size, Product *product) {
    *inventory = (Product *)realloc(*inventory, (*inventory_size + 1) * sizeof(Product));
    (*inventory)[*inventory_size] = *product;
    (*inventory_size)++;
}

// Function to search for a product by its ID
Product *findProductById(Product *inventory, int inventory_size, int product_id) {
    for (int i = 0; i < inventory_size; i++) {
        if (inventory[i].product_id == product_id) {
            return &inventory[i];
        }
    }
    return NULL;
}

// Function to sell a product
void sellProduct(Product *inventory, int inventory_size, int product_id, int quantity) {
    Product *product = findProductById(inventory, inventory_size, product_id);
    if (product != NULL) {
        if (product->quantity >= quantity) {
            product->quantity -= quantity;
        } else {
            printf("Not enough stock to sell %d units of product %d\n", quantity, product_id);
        }
    } else {
        printf("Product with ID %d not found\n", product_id);
    }
}

// Function to print the inventory
void printInventory(Product *inventory, int inventory_size) {
    printf("Product ID\tProduct Name\tQuantity\tPrice\n");
    for (int i = 0; i < inventory_size; i++) {
        printf("%d\t\t%s\t\t%d\t\t%.2f\n", inventory[i].product_id, inventory[i].product_name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    // Create an empty inventory
    Product *inventory = NULL;
    int inventory_size = 0;

    // Add some products to the inventory
    Product *product1 = createProduct(1, "Apple", 100, 1.0);
    addProduct(&inventory, &inventory_size, product1);
    Product *product2 = createProduct(2, "Orange", 50, 1.5);
    addProduct(&inventory, &inventory_size, product2);
    Product *product3 = createProduct(3, "Banana", 25, 2.0);
    addProduct(&inventory, &inventory_size, product3);

    // Print the inventory
    printf("Initial inventory:\n");
    printInventory(inventory, inventory_size);

    // Sell some products
    sellProduct(inventory, inventory_size, 1, 50);
    sellProduct(inventory, inventory_size, 2, 25);

    // Print the inventory again
    printf("Inventory after selling some products:\n");
    printInventory(inventory, inventory_size);

    // Free the memory allocated for the inventory
    for (int i = 0; i < inventory_size; i++) {
        free(inventory[i].product_name);
    }
    free(inventory);

    return 0;
}