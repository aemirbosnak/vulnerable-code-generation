//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: Donald Knuth
/* A Product Inventory System in the Style of Donald Knuth
 *
 * This program is a demonstration of how to write a product inventory system in the
 * style of Donald Knuth. Knuth is a renowned computer scientist who is known for
 * his contributions to the fields of algorithms, data structures, and programming
 * languages. His writing style is characterized by its clarity, precision, and
 * attention to detail.
 *
 * This program is not intended to be a complete or production-quality inventory
 * system. Rather, it is simply a demonstration of how Knuth's writing style can
 * be applied to the task of writing a software program.
 */

/* Include the necessary header files. */
#include <stdio.h>
#include <stdlib.h>

/* Define the maximum number of products that can be stored in the inventory. */
#define MAX_PRODUCTS 100

/* Define the structure of a product. */
typedef struct {
    char *name;
    int quantity;
    double price;
} product;

/* Define the structure of the inventory. */
typedef struct {
    product products[MAX_PRODUCTS];
    int num_products;
} inventory;

/* Create a new inventory. */
inventory *create_inventory() {
    inventory *inv = malloc(sizeof(inventory));
    if (inv == NULL) {
        return NULL;
    }
    inv->num_products = 0;
    return inv;
}

/* Add a product to the inventory. */
int add_product(inventory *inv, product *prod) {
    if (inv->num_products >= MAX_PRODUCTS) {
        return -1;
    }
    inv->products[inv->num_products++] = *prod;
    return 0;
}

/* Remove a product from the inventory. */
int remove_product(inventory *inv, product *prod) {
    int i;
    for (i = 0; i < inv->num_products; i++) {
        if (strcmp(inv->products[i].name, prod->name) == 0) {
            inv->products[i] = inv->products[inv->num_products - 1];
            inv->num_products--;
            return 0;
        }
    }
    return -1;
}

/* Find a product in the inventory. */
product *find_product(inventory *inv, char *name) {
    int i;
    for (i = 0; i < inv->num_products; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            return &inv->products[i];
        }
    }
    return NULL;
}

/* Print the inventory. */
void print_inventory(inventory *inv) {
    int i;
    for (i = 0; i < inv->num_products; i++) {
        printf("%s %d %f\n", inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
}

/* Free the memory allocated for the inventory. */
void free_inventory(inventory *inv) {
    int i;
    for (i = 0; i < inv->num_products; i++) {
        free(inv->products[i].name);
    }
    free(inv);
}

/* Main function. */
int main() {
    inventory *inv = create_inventory();
    product prod1 = {"Prod1", 10, 10.0};
    product prod2 = {"Prod2", 20, 20.0};
    product prod3 = {"Prod3", 30, 30.0};
    add_product(inv, &prod1);
    add_product(inv, &prod2);
    add_product(inv, &prod3);
    print_inventory(inv);
    product *prod4 = find_product(inv, "Prod2");
    printf("%s %d %f\n", prod4->name, prod4->quantity, prod4->price);
    remove_product(inv, &prod3);
    print_inventory(inv);
    free_inventory(inv);
    return 0;
}