//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: portable
#include <stdio.h>
#include <stdlib.h>

struct product {
    char name[20];
    float price;
    int quantity;
};

struct product* create_product(char name[], float price, int quantity) {
    struct product* new_product = malloc(sizeof(struct product));
    if (new_product == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    strcpy(new_product->name, name);
    new_product->price = price;
    new_product->quantity = quantity;
    return new_product;
}

void print_product(struct product* product) {
    printf("Name: %s, Price: %.2f, Quantity: %d\n", product->name, product->price, product->quantity);
}

void update_product(struct product* product, char name[], float price, int quantity) {
    if (product == NULL) {
        printf("Product not found\n");
        return;
    }
    strcpy(product->name, name);
    product->price = price;
    product->quantity = quantity;
}

void delete_product(struct product* product) {
    if (product == NULL) {
        printf("Product not found\n");
        return;
    }
    free(product);
}

int main() {
    struct product* product1 = create_product("Apple", 0.99, 10);
    print_product(product1);
    update_product(product1, "Banana", 1.50, 5);
    print_product(product1);
    delete_product(product1);
    return 0;
}