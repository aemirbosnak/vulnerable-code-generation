//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

struct product {
    char name[100];
    int quantity;
    float price;
};

struct product* create_product(char name[], int quantity, float price) {
    struct product* new_product = (struct product*)malloc(sizeof(struct product));
    if (new_product == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for new product\n");
        return NULL;
    }
    strcpy(new_product->name, name);
    new_product->quantity = quantity;
    new_product->price = price;
    return new_product;
}

void destroy_product(struct product* product) {
    if (product!= NULL) {
        free(product);
    }
}

void print_product(struct product* product) {
    printf("Name: %s\n", product->name);
    printf("Quantity: %d\n", product->quantity);
    printf("Price: $%.2f\n", product->price);
}

int main() {
    struct product* product1 = create_product("Apple", 10, 1.99);
    struct product* product2 = create_product("Banana", 20, 0.99);
    struct product* product3 = create_product("Orange", 30, 2.49);

    printf("Product 1: %s\n", product1->name);
    printf("Quantity: %d\n", product1->quantity);
    printf("Price: $%.2f\n", product1->price);
    print_product(product1);

    printf("Product 2: %s\n", product2->name);
    printf("Quantity: %d\n", product2->quantity);
    printf("Price: $%.2f\n", product2->price);
    print_product(product2);

    printf("Product 3: %s\n", product3->name);
    printf("Quantity: %d\n", product3->quantity);
    printf("Price: $%.2f\n", product3->price);
    print_product(product3);

    destroy_product(product1);
    destroy_product(product2);
    destroy_product(product3);

    return 0;
}