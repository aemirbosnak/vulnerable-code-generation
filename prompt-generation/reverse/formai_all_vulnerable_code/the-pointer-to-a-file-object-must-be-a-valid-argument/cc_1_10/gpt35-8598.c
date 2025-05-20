//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Linus Torvalds
/*
 * C Product Inventory System Example Program
 *
 * Author: Linus Torvalds
 *
 * This program is a simple product inventory system.
 * It reads in product data from a file and allows the user to 
 * add new products, update existing products, and delete products.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

// Product structure
typedef struct product {
    char name[50];
    int quantity;
    double price;
} product_t;

// Function declarations
void read_data(product_t products[], int *num_products);
void add_product(product_t products[], int *num_products);
void update_product(product_t products[], int num_products);
void delete_product(product_t products[], int *num_products);

int main() {
    product_t products[MAX_PRODUCTS];
    int num_products = 0;
    int choice = 0;
    
    // Read in product data from file
    read_data(products, &num_products);
    
    // Display menu and process user input
    while (choice != 4) {
        printf("\n\nProduct Inventory System Menu:\n");
        printf("1. Add Product\n");
        printf("2. Update Product\n");
        printf("3. Delete Product\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_product(products, &num_products);
                break;
            case 2:
                update_product(products, num_products);
                break;
            case 3:
                delete_product(products, &num_products);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    
    return 0;
}

// Reads in product data from file
void read_data(product_t products[], int *num_products) {
    FILE *data;
    char filename[50];
    char line[100];
    char *token;
    
    // Open data file for reading
    printf("Enter name of data file: ");
    scanf("%s", filename);
    data = fopen(filename, "r");
    
    // Read in product data
    while (fgets(line, 100, data)) {
        token = strtok(line, ",");
        strcpy(products[*num_products].name, token);
        token = strtok(NULL, ",");
        products[*num_products].quantity = atoi(token);
        token = strtok(NULL, ",");
        products[*num_products].price = atof(token);
        (*num_products)++;
    }
    
    printf("%d products read from file.\n", *num_products);
    
    // Close data file
    fclose(data);
}

// Adds a new product to the inventory
void add_product(product_t products[], int *num_products) {
    char name[50];
    int quantity;
    double price;
    
    // Get product data from user
    printf("Enter product name: ");
    scanf("%s", name);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    printf("Enter price: ");
    scanf("%lf", &price);
    
    // Add new product to inventory
    strcpy(products[*num_products].name, name);
    products[*num_products].quantity = quantity;
    products[*num_products].price = price;
    (*num_products)++;
    
    printf("Product added!\n");
}

// Updates an existing product in the inventory
void update_product(product_t products[], int num_products) {
    char name[50];
    int choice = 0;
    int i;
    
    // Get name of product to update
    printf("Enter name of product to update: ");
    scanf("%s", name);
    
    // Find product in inventory
    for (i = 0; i < num_products; i++) {
        if (strcmp(name, products[i].name) == 0) {
            // Product found, display options to update
            printf("Product found.\n");
            printf("1. Update quantity\n");
            printf("2. Update price\n");
            printf("Enter choice: ");
            scanf("%d", &choice);
            
            switch(choice) {
                case 1:
                    // Update quantity
                    printf("Enter new quantity: ");
                    scanf("%d", &products[i].quantity);
                    printf("Quantity updated!\n");
                    break;
                case 2:
                    // Update price
                    printf("Enter new price: ");
                    scanf("%lf", &products[i].price);
                    printf("Price updated!\n");
                    break;
                default:
                    printf("Invalid choice. Try again.\n");
            }
            
            return;
        }
    }
    
    // Product not found
    printf("Product not found.\n");
}

// Deletes a product from the inventory
void delete_product(product_t products[], int *num_products) {
    char name[50];
    int i, j;
    
    // Get name of product to delete
    printf("Enter name of product to delete: ");
    scanf("%s", name);
    
    // Find product in inventory
    for (i = 0; i < *num_products; i++) {
        if (strcmp(name, products[i].name) == 0) {
            // Product found, shift array elements to delete product
            printf("Product found.\n");
            for (j = i; j < *num_products - 1; j++) {
                strcpy(products[j].name, products[j + 1].name);
                products[j].quantity = products[j + 1].quantity;
                products[j].price = products[j + 1].price;
            }
            (*num_products)--;
            printf("Product deleted!\n");
            return;
        }
    }
    
    // Product not found
    printf("Product not found.\n");
}