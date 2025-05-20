//FormAI DATASET v1.0 Category: Product Inventory System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define maximum length of product name string
#define MAX_NAME_LENGTH 50 

//define product structure
typedef struct product {
    int id; //product ID
    char name[MAX_NAME_LENGTH]; //product name
    int quantity; //product quantity
    float price; //product price
} product_t;

//define function to create new product
product_t* create_product(int id, char name[], int quantity, float price) {
    //allocate memory for new product
    product_t* new_product = (product_t*) malloc(sizeof(product_t));
    
    //set product properties
    new_product->id = id;
    strcpy(new_product->name, name);
    new_product->quantity = quantity;
    new_product->price = price;
    
    //return newly created product
    return new_product;
}

//define function to add product to inventory
void add_product(product_t* inventory[], int* count, product_t* product) {
    inventory[*count] = product;
    *count += 1;
}

//define function to print all products in inventory
void print_inventory(product_t* inventory[], int count) {
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i=0; i<count; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", inventory[i]->id, inventory[i]->name, inventory[i]->quantity, inventory[i]->price);
    }
}

int main() {
    //initialize inventory array
    product_t* inventory[50];
    int inventory_count = 0;
    
    //create and add products to inventory
    product_t* product1 = create_product(1, "Product 1", 10, 9.99);
    add_product(inventory, &inventory_count, product1);
    
    product_t* product2 = create_product(2, "Product 2", 5, 19.99);
    add_product(inventory, &inventory_count, product2);
    
    //print inventory
    print_inventory(inventory, inventory_count);
    
    //free memory allocated for products
    free(product1);
    free(product2);
    
    return 0;
}