//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} product_t;

typedef struct {
    product_t *products;
    int size;
    int capacity;
} inventory_t;

inventory_t *inventory_create(int capacity) {
    inventory_t *inventory = malloc(sizeof(inventory_t));
    inventory->products = malloc(sizeof(product_t) * capacity);
    inventory->size = 0;
    inventory->capacity = capacity;
    return inventory;
}

void inventory_destroy(inventory_t *inventory) {
    free(inventory->products);
    free(inventory);
}

void inventory_add_product(inventory_t *inventory, product_t *product) {
    if (inventory->size == inventory->capacity) {
        inventory->capacity *= 2;
        inventory->products = realloc(inventory->products, sizeof(product_t) * inventory->capacity);
    }
    inventory->products[inventory->size++] = *product;
}

void inventory_remove_product(inventory_t *inventory, char *name) {
    int i;
    for (i = 0; i < inventory->size; i++) {
        if (strcmp(inventory->products[i].name, name) == 0) {
            inventory->products[i] = inventory->products[inventory->size - 1];
            inventory->size--;
            break;
        }
    }
}

product_t *inventory_get_product(inventory_t *inventory, char *name) {
    int i;
    for (i = 0; i < inventory->size; i++) {
        if (strcmp(inventory->products[i].name, name) == 0) {
            return &inventory->products[i];
        }
    }
    return NULL;
}

void inventory_print(inventory_t *inventory) {
    int i;
    for (i = 0; i < inventory->size; i++) {
        printf("%s %d %.2f\n", inventory->products[i].name, inventory->products[i].quantity, inventory->products[i].price);
    }
}

int main() {
    inventory_t *inventory = inventory_create(10);
    
    product_t product1 = {"Apple", 10, 1.00};
    inventory_add_product(inventory, &product1);
    
    product_t product2 = {"Banana", 20, 1.50};
    inventory_add_product(inventory, &product2);
    
    product_t product3 = {"Cherry", 30, 2.00};
    inventory_add_product(inventory, &product3);
    
    inventory_print(inventory);
    
    product_t *product = inventory_get_product(inventory, "Banana");
    if (product != NULL) {
        product->quantity += 10;
    }
    
    inventory_remove_product(inventory, "Cherry");
    
    inventory_print(inventory);
    
    inventory_destroy(inventory);
    
    return 0;
}