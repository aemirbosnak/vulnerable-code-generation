//FormAI DATASET v1.0 Category: Product Inventory System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a structure for each product
struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};

// Define functions
void addProduct(struct Product *products, int *size);
void deleteProduct(struct Product *products, int *size);
void printProducts(struct Product *products, int size);
void updateProduct(struct Product *products, int size);

int main() {
    // Declare variables
    int option = 0;
    int size = 0;
    struct Product *products;

    // Allocate memory for products array
    products = malloc(size * sizeof(struct Product));

    // Display menu and get user input until they quit
    while(option != 5) {
        printf("Welcome to the Product Inventory System!\n");
        printf("Please select an option:\n\n");
        printf("1. Add Product\n");
        printf("2. Delete Product\n");
        printf("3. Print Products\n");
        printf("4. Update Product\n");
        printf("5. Quit\n\n");

        printf("Option: ");
        scanf("%d", &option);

        // Handle menu option chosen by user
        switch(option) {
            case 1:
                addProduct(products, &size);
                break;
            case 2:
                deleteProduct(products, &size);
                break;
            case 3:
                printProducts(products, size);
                break;
            case 4:
                updateProduct(products, size);
                break;
            case 5:
                printf("Thank you for using the Product Inventory System!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    // Free memory allocated for products
    free(products);

    return 0;
}

// Function to add a new product
void addProduct(struct Product *products, int *size) {
    // Re-allocate memory for products array with new size
    *size = *size + 1;
    products = realloc(products, *size * sizeof(struct Product));

    // Get details of new product
    printf("\nAdd Product\n");
    printf("===========\n");

    printf("Enter Product ID: ");
    scanf("%d", &products[*size-1].id);

    printf("Enter Product Name: ");
    scanf("%s", products[*size-1].name);

    printf("Enter Product Price: ");
    scanf("%f", &products[*size-1].price);

    printf("Enter Product Quantity: ");
    scanf("%d", &products[*size-1].quantity);

    printf("\nProduct added successfully!\n\n");
}

// Function to delete a product
void deleteProduct(struct Product *products, int *size) {
    // Get ID of product to be deleted
    int idToDelete;
    int indexToDelete;

    printf("\nDelete Product\n");
    printf("==============\n");

    printf("Enter Product ID to delete: ");
    scanf("%d", &idToDelete);

    // Find index of product to be deleted
    for(int i = 0; i < *size; i++) {
        if(products[i].id == idToDelete) {
            indexToDelete = i;
        }
    }

    // Shift array elements to remove product at indexToDelete
    for(int i = indexToDelete; i < *size; i++) {
        products[i] = products[i+1];
    }

    // Re-allocate memory for products array with new size
    *size = *size - 1;
    products = realloc(products, *size * sizeof(struct Product));

    printf("\nProduct deleted successfully!\n\n");
}

// Function to print all products
void printProducts(struct Product *products, int size) {
    printf("\nAll Products\n");
    printf("============\n");
    for(int i = 0; i < size; i++) {
        printf("Product %d\n", i+1);
        printf("ID: %d\n", products[i].id);
        printf("Name: %s\n", products[i].name);
        printf("Price: $%.2f\n", products[i].price);
        printf("Quantity: %d\n\n", products[i].quantity);
    }
}

// Function to update a product
void updateProduct(struct Product *products, int size) {
    // Get ID of product to update
    int idToUpdate;
    int indexToUpdate;

    printf("\nUpdate Product\n");
    printf("==============\n");

    printf("Enter Product ID to update: ");
    scanf("%d", &idToUpdate);

    // Find index of product to update
    for(int i = 0; i < size; i++) {
        if(products[i].id == idToUpdate) {
            indexToUpdate = i;
        }
    }

    // Get details of updated product
    printf("\nEnter new details:\n");

    printf("Enter Product Name: ");
    scanf("%s", products[indexToUpdate].name);

    printf("Enter Product Price: ");
    scanf("%f", &products[indexToUpdate].price);

    printf("Enter Product Quantity: ");
    scanf("%d", &products[indexToUpdate].quantity);

    printf("\nProduct updated successfully!\n\n");
}