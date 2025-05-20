//FormAI DATASET v1.0 Category: Product Inventory System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure to store Product details
typedef struct Product {
    int id; //unique product id
    char name[50]; //product name
    int quantity; //quantity of product
    float price; //price of the product
} Product;

//Function to create new Product
Product* createProduct(int id, char* name, int quantity, float price) {
    //Create memory allocation for product
    Product* new_product = (Product*) malloc(sizeof(Product));
    new_product->id = id;
    strcpy(new_product->name, name);
    new_product->quantity = quantity;
    new_product->price = price;
    return new_product;
}

//Function to add Product to Inventory
void addProduct(Product* inventory[], int index, Product* new_product) {
    inventory[index] = new_product;
}

//Function to search for Product in Inventory
Product* searchProduct(Product* inventory[], int index, int id) {
    for(int i=0; i<index; i++) {
        if(inventory[i]->id == id) {
            return inventory[i];
        }
    }
    return NULL;
}

int main() {
    //Create Inventory to store products
    Product* inventory[50];
    int inventory_size = 0;

    //Add products to inventory
    Product* product1 = createProduct(1001, "Apple iPhone XR", 20, 749.00);
    addProduct(inventory, inventory_size, product1);
    inventory_size++;

    Product* product2 = createProduct(1002, "Samsung Galaxy S10", 15, 899.00);
    addProduct(inventory, inventory_size, product2);
    inventory_size++;

    //Search for a product
    Product* found_product = searchProduct(inventory, inventory_size, 1001);
    if(found_product != NULL) {
        printf("Product found: %s\n", found_product->name);
    } else {
        printf("Product not found.\n");
    }

    return 0;
}