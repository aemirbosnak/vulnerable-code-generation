//FormAI DATASET v1.0 Category: Product Inventory System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the product
typedef struct product {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

// Define the function to add product to the inventory
void addProduct(Product *inventory, int *numProducts) {
    int id, quantity;
    float price;
    char name[50];

    printf("Enter the product details:\n");
    printf("ID: ");
    scanf("%d", &id);

    for(int i=0; i<*numProducts; i++) {
        if(inventory[i].id == id) {
            printf("Product with ID %d already exists!\n", id);
            return;
        }
    }

    printf("Name: ");
    scanf("%s", name);

    printf("Price: ");
    scanf("%f", &price);

    printf("Quantity: ");
    scanf("%d", &quantity);

    // Create a new product and add it to the inventory
    Product newProduct = {id, name, price, quantity};
    inventory[*numProducts] = newProduct;
    (*numProducts)++;
    printf("Product added successfully!\n\n");
}

// Define the function to display all products in the inventory
void viewInventory(Product *inventory, int numProducts) {
    if(numProducts == 0) {
        printf("Inventory is empty!\n\n");
        return;
    }

    printf("Product inventory:\n");
    printf("| %-3s | %-20s | %-10s | %-8s |\n", "ID", "Name", "Price", "Quantity");
    for(int i=0; i<numProducts; i++) {
        printf("| %-3d | %-20s | %-10.2f | %-8d |\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
    printf("\n");
}

// Define the function to search a product in the inventory
void searchProduct(Product *inventory, int numProducts) {
    if(numProducts == 0) {
        printf("Inventory is empty!\n\n");
        return;
    }

    int id;
    printf("Enter the product ID to search: ");
    scanf("%d", &id);

    for(int i=0; i<numProducts; i++) {
        if(inventory[i].id == id) {
            printf("| %-3s | %-20s | %-10s | %-8s |\n", "ID", "Name", "Price", "Quantity");
            printf("| %-3d | %-20s | %-10.2f | %-8d |\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
            printf("\n");
            return;
        }
    }

    printf("Product with ID %d does not exist!\n\n", id);
}

int main() {
    int numProducts = 0, option;

    // Allocate memory for the inventory
    Product *inventory = malloc(10 * sizeof(Product));

    while(1) {
        printf("Welcome to the Product Inventory System!\n");
        printf("1. Add product\n");
        printf("2. View inventory\n");
        printf("3. Search product\n");
        printf("4. Exit\n");

        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                addProduct(inventory, &numProducts);
                break;
            case 2:
                viewInventory(inventory, numProducts);
                break;
            case 3:
                searchProduct(inventory, numProducts);
                break;
            case 4:
                printf("Thank you for using the Product Inventory System!\n");
                free(inventory);
                return 0;
            default:
                printf("Invalid option! Please try again.\n\n");
        }
    }
}