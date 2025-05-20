//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to store a product
typedef struct product {
    char *name;
    int quantity;
    float price;
} product;

// Function to create a new product
product *create_product(char *name, int quantity, float price) {
    product *p = malloc(sizeof(product));
    p->name = strdup(name);
    p->quantity = quantity;
    p->price = price;
    return p;
}

// Function to print a product
void print_product(product *p) {
    printf("%s %d %.2f\n", p->name, p->quantity, p->price);
}

// Function to compare two products by name
int compare_products(product *p1, product *p2) {
    return strcmp(p1->name, p2->name);
}

// Function to add a product to the inventory
void add_product(product **inventory, int *size, product *p) {
    *inventory = realloc(*inventory, (*size + 1) * sizeof(product));
    (*inventory)[*size] = *p;
    (*size)++;
}

// Function to remove a product from the inventory
void remove_product(product **inventory, int *size, char *name) {
    int i;
    for (i = 0; i < *size; i++) {
        if (strcmp((*inventory)[i].name, name) == 0) {
            break;
        }
    }
    if (i < *size) {
        for (i; i < *size - 1; i++) {
            (*inventory)[i] = (*inventory)[i + 1];
        }
        (*size)--;
    }
}

// Function to find a product in the inventory
product *find_product(product **inventory, int size, char *name) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp((*inventory)[i].name, name) == 0) {
            return &(*inventory)[i];
        }
    }
    return NULL;
}

// Function to print the inventory
void print_inventory(product **inventory, int size) {
    int i;
    for (i = 0; i < size; i++) {
        print_product(&(*inventory)[i]);
    }
}

// Main function
int main() {
    product *inventory = NULL;
    int size = 0;

    // Add some products to the inventory
    add_product(&inventory, &size, create_product("Apple", 10, 1.0));
    add_product(&inventory, &size, create_product("Banana", 20, 2.0));
    add_product(&inventory, &size, create_product("Cherry", 30, 3.0));

    // Print the inventory
    printf("Inventory:\n");
    print_inventory(&inventory, size);

    // Find a product in the inventory
    product *p = find_product(&inventory, size, "Banana");
    if (p != NULL) {
        printf("Found product: %s\n", p->name);
    } else {
        printf("Product not found.\n");
    }

    // Remove a product from the inventory
    remove_product(&inventory, &size, "Cherry");

    // Print the inventory
    printf("Inventory:\n");
    print_inventory(&inventory, size);

    // Free the inventory
    for (int i = 0; i < size; i++) {
        free(inventory[i].name);
    }
    free(inventory);

    return 0;
}