//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a product
typedef struct product {
    int id;
    char *name;
    int quantity;
    float price;
} product;

// Structure to represent a warehouse
typedef struct warehouse {
    char *name;
    int num_products;
    product *products;
} warehouse;

// Function to create a new product
product *create_product(int id, char *name, int quantity, float price) {
    product *p = malloc(sizeof(product));
    p->id = id;
    p->name = strdup(name);
    p->quantity = quantity;
    p->price = price;
    return p;
}

// Function to create a new warehouse
warehouse *create_warehouse(char *name) {
    warehouse *w = malloc(sizeof(warehouse));
    w->name = strdup(name);
    w->num_products = 0;
    w->products = NULL;
    return w;
}

// Function to add a product to a warehouse
void add_product(warehouse *w, product *p) {
    w->products = realloc(w->products, (w->num_products + 1) * sizeof(product));
    w->products[w->num_products++] = *p;
}

// Function to remove a product from a warehouse
void remove_product(warehouse *w, int id) {
    for (int i = 0; i < w->num_products; i++) {
        if (w->products[i].id == id) {
            for (int j = i; j < w->num_products - 1; j++) {
                w->products[j] = w->products[j + 1];
            }
            w->num_products--;
            break;
        }
    }
}

// Function to get the total value of a warehouse
float get_total_value(warehouse *w) {
    float total = 0;
    for (int i = 0; i < w->num_products; i++) {
        total += w->products[i].quantity * w->products[i].price;
    }
    return total;
}

// Function to print the contents of a warehouse
void print_warehouse(warehouse *w) {
    printf("Warehouse: %s\n", w->name);
    printf("Number of products: %d\n", w->num_products);
    for (int i = 0; i < w->num_products; i++) {
        printf("Product: %s\n", w->products[i].name);
        printf("ID: %d\n", w->products[i].id);
        printf("Quantity: %d\n", w->products[i].quantity);
        printf("Price: %.2f\n", w->products[i].price);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new warehouse
    warehouse *w = create_warehouse("Warehouse 1");

    // Add some products to the warehouse
    product *p1 = create_product(1, "Product 1", 10, 10.0);
    add_product(w, p1);
    product *p2 = create_product(2, "Product 2", 20, 20.0);
    add_product(w, p2);
    product *p3 = create_product(3, "Product 3", 30, 30.0);
    add_product(w, p3);

    // Print the contents of the warehouse
    print_warehouse(w);

    // Get the total value of the warehouse
    float total_value = get_total_value(w);
    printf("Total value of the warehouse: %.2f\n", total_value);

    // Remove a product from the warehouse
    remove_product(w, 2);

    // Print the contents of the warehouse again
    print_warehouse(w);

    // Free the memory allocated for the warehouse and its products
    for (int i = 0; i < w->num_products; i++) {
        free(w->products[i].name);
    }
    free(w->products);
    free(w->name);
    free(w);

    return 0;
}