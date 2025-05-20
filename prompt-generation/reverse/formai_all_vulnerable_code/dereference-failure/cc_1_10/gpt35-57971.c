//FormAI DATASET v1.0 Category: Product Inventory System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the product struct
typedef struct Product{
    char *name;
    int id;
    float price;
    int quantity;
} Product;

// Function to create new products
Product *create_product(char *name, int id, float price, int quantity){
    Product *new_product = malloc(sizeof(Product));
    new_product->name = name;
    new_product->id = id;
    new_product->price = price;
    new_product->quantity = quantity;
    return new_product;
}

// Function to add new products to the inventory
void add_product(Product *inventory[], Product *new_product, int size){
    inventory[size] = new_product;
}

// Function to display all products in the inventory
void display_products(Product *inventory[], int size){
    printf("---Product Inventory System---\n\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for(int i=0; i<size; i++){
        printf("%d\t%s\t%d\t\t%.2f\n", inventory[i]->id, inventory[i]->name, inventory[i]->quantity, inventory[i]->price);
    }
}

int main(){
    // Define the inventory array
    Product *inventory[10];

    // Create some initial products
    Product *p1 = create_product("Pen", 1, 1.50, 100);
    Product *p2 = create_product("Notebook", 2, 3.99, 50);
    Product *p3 = create_product("Pencil", 3, 0.99, 200);

    // Add the initial products to the inventory
    add_product(inventory, p1, 0);
    add_product(inventory, p2, 1);
    add_product(inventory, p3, 2);

    // Display the initial products
    display_products(inventory, 3);

    // Create a new product
    Product *p4 = create_product("Marker", 4, 2.49, 75);

    // Add the new product to the inventory
    add_product(inventory, p4, 3);

    // Display all products again
    display_products(inventory, 4);

    return 0;
}