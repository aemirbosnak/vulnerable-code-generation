//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a product
typedef struct product {
    int id;
    char name[50];
    int quantity;
    float price;
} product;

// Structure to represent a warehouse
typedef struct warehouse {
    int id;
    char name[50];
    product *products;
    int num_products;
} warehouse;

// Function to create a new product
product *create_product(int id, char *name, int quantity, float price) {
    product *p = malloc(sizeof(product));
    p->id = id;
    strcpy(p->name, name);
    p->quantity = quantity;
    p->price = price;
    return p;
}

// Function to create a new warehouse
warehouse *create_warehouse(int id, char *name) {
    warehouse *w = malloc(sizeof(warehouse));
    w->id = id;
    strcpy(w->name, name);
    w->products = NULL;
    w->num_products = 0;
    return w;
}

// Function to add a product to a warehouse
void add_product(warehouse *w, product *p) {
    w->products = realloc(w->products, (w->num_products + 1) * sizeof(product));
    w->products[w->num_products++] = *p;
}

// Function to remove a product from a warehouse
void remove_product(warehouse *w, int id) {
    int i;
    for (i = 0; i < w->num_products; i++) {
        if (w->products[i].id == id) {
            break;
        }
    }
    if (i < w->num_products) {
        for (int j = i; j < w->num_products - 1; j++) {
            w->products[j] = w->products[j + 1];
        }
        w->num_products--;
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

// Function to print the details of a warehouse
void print_warehouse(warehouse *w) {
    printf("Warehouse ID: %d\n", w->id);
    printf("Warehouse Name: %s\n", w->name);
    printf("Number of Products: %d\n", w->num_products);
    printf("Total Value: %.2f\n", get_total_value(w));
    printf("Products:\n");
    for (int i = 0; i < w->num_products; i++) {
        printf("  - ID: %d\n", w->products[i].id);
        printf("    Name: %s\n", w->products[i].name);
        printf("    Quantity: %d\n", w->products[i].quantity);
        printf("    Price: %.2f\n", w->products[i].price);
    }
}

int main() {
    // Create a new warehouse
    warehouse *w = create_warehouse(1, "Warehouse 1");

    // Add some products to the warehouse
    product *p1 = create_product(1, "Product 1", 10, 10.0);
    add_product(w, p1);
    product *p2 = create_product(2, "Product 2", 20, 20.0);
    add_product(w, p2);
    product *p3 = create_product(3, "Product 3", 30, 30.0);
    add_product(w, p3);

    // Print the details of the warehouse
    print_warehouse(w);

    // Remove a product from the warehouse
    remove_product(w, 2);

    // Print the details of the warehouse again
    print_warehouse(w);

    return 0;
}