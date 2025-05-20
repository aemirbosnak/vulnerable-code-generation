//FormAI DATASET v1.0 Category: Product Inventory System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store product information
typedef struct {
    char *name;
    int quantity;
    float price;
} Product;

// Function to get product information from user
void get_product_info(Product *product) {
    char *name = (char*)malloc(50*sizeof(char));
    printf("Enter product name: ");
    scanf("%s", name);
    product->name = name;
    printf("Enter product quantity: ");
    scanf("%d", &product->quantity);
    printf("Enter product price: ");
    scanf("%f", &product->price);
}

// Function to add product to inventory
void add_product(Product **inventory, int *inventory_size) {
    // Allocate memory for new product
    Product *new_product = (Product*)malloc(sizeof(Product));
    // Get product information from user
    get_product_info(new_product);
    // Increase inventory size
    (*inventory_size)++;
    // Reallocate memory for inventory
    *inventory = (Product*)realloc(*inventory, (*inventory_size)*sizeof(Product));
    // Add new product to inventory
    (*inventory)[*inventory_size-1] = *new_product;
    // Free memory
    free(new_product->name);
    free(new_product);
}

// Function to print inventory
void print_inventory(Product *inventory, int inventory_size) {
    printf("+---------------+---------------+---------------+\n");
    printf("|%15s|%15s|%15s|\n", "Product Name", "Quantity", "Price");
    for (int i=0; i<inventory_size; i++) {
        printf("+---------------+---------------+---------------+\n");
        printf("|%15s|%15d|%15.2f|\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("+---------------+---------------+---------------+\n");
}

// Function to search for a product in inventory
void search_product(Product *inventory, int inventory_size) {
    char *search_term = (char*)malloc(50*sizeof(char));
    printf("Enter search term: ");
    scanf("%s", search_term);
    for (int i=0; i<inventory_size; i++) {
        if (strstr(inventory[i].name, search_term)) {
            printf("Product found!\n");
            printf("Product Name: %s\nQuantity: %d\nPrice: %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            free(search_term);
            return;
        }
    }
    printf("Product not found.\n");
    free(search_term);
}

int main() {
    int inventory_size = 0;
    Product *inventory = (Product*)malloc(0*sizeof(Product));
    int choice = 0;
    while (1) {
        printf("Enter choice:\n1. Add Product\n2. Print Inventory\n3. Search Product\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_product(&inventory, &inventory_size);
                break;
            case 2:
                print_inventory(inventory, inventory_size);
                break;
            case 3:
                search_product(inventory, inventory_size);
                break;
            case 4:
                free(inventory);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}