//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: cheerful
#include <stdio.h>
#include <string.h>

// Define a struct to store product information
typedef struct Product {
    char name[20];
    int quantity;
    double price;
} Product;

// Define a function to add a product to the inventory
void addProduct(Product *products, int *numProducts) {
    // Allocate memory for a new product
    products = (Product *)realloc(products, (*numProducts + 1) * sizeof(Product));

    // Get the product name, quantity, and price
    printf("Enter product name: ");
    scanf("%s", products[*numProducts].name);

    printf("Enter product quantity: ");
    scanf("%d", &products[*numProducts].quantity);

    printf("Enter product price: ");
    scanf("%lf", &products[*numProducts].price);

    // Increment the number of products
    (*numProducts)++;
}

// Define a function to display the inventory
void displayInventory(Product *products, int numProducts) {
    // Print the inventory
    printf("Inventory:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%s - %d - %.2lf\n", products[i].name, products[i].quantity, products[i].price);
    }
}

// Define a function to search for a product
void searchProduct(Product *products, int numProducts) {
    // Get the product name
    char productName[20];
    printf("Enter product name: ");
    scanf("%s", productName);

    // Search for the product
    int found = 0;
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, productName) == 0) {
            // Display the product information
            printf("Product name: %s\n", products[i].name);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: %.2lf\n", products[i].price);
            found = 1;
        }
    }

    // If the product was not found, display an error message
    if (!found) {
        printf("Product not found.\n");
    }
}

int main() {
    // Create an array of products
    Product *products = NULL;
    int numProducts = 0;

    // Add some products to the inventory
    addProduct(products, &numProducts);
    addProduct(products, &numProducts);
    addProduct(products, &numProducts);

    // Display the inventory
    displayInventory(products, numProducts);

    // Search for a product
    searchProduct(products, numProducts);

    return 0;
}