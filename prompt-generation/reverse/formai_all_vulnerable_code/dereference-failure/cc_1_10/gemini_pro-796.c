//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char *name;
    int quantity;
    double price;
} Product;

Product *products;
int num_products;

void add_product(Product product) {
    products = realloc(products, (num_products + 1) * sizeof(Product));
    products[num_products] = product;
    num_products++;
}

Product *find_product_by_id(int id) {
    for (int i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            return &products[i];
        }
    }
    return NULL;
}

Product *find_product_by_name(char *name) {
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            return &products[i];
        }
    }
    return NULL;
}

void print_product(Product product) {
    printf("ID: %d\n", product.id);
    printf("Name: %s\n", product.name);
    printf("Quantity: %d\n", product.quantity);
    printf("Price: %f\n", product.price);
}

void print_all_products() {
    for (int i = 0; i < num_products; i++) {
        print_product(products[i]);
        printf("\n");
    }
}

int main() {
    // Create some products
    Product product1 = {1, "Apple", 10, 1.0};
    Product product2 = {2, "Orange", 20, 1.5};
    Product product3 = {3, "Banana", 30, 2.0};
    
    // Add the products to the warehouse
    add_product(product1);
    add_product(product2);
    add_product(product3);
    
    // Print all the products
    printf("All products:\n");
    print_all_products();
    
    // Find a product by ID
    Product *product_by_id = find_product_by_id(2);
    if (product_by_id == NULL) {
        printf("Product with ID 2 not found.\n");
    } else {
        printf("Product with ID 2:\n");
        print_product(*product_by_id);
    }
    
    // Find a product by name
    Product *product_by_name = find_product_by_name("Banana");
    if (product_by_name == NULL) {
        printf("Product with name Banana not found.\n");
    } else {
        printf("Product with name Banana:\n");
        print_product(*product_by_name);
    }
    
    return 0;
}