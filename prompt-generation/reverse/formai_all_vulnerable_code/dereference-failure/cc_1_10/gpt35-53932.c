//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    int quantity;
    float price;
} Product;

typedef struct {
    int id;
    char name[20];
    char location[20];
    int capacity;
    Product *products;
    int size;
} Warehouse;

void printProduct(Product p) {
    printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", p.id, p.name, p.quantity, p.price);
}

void printWarehouse(Warehouse w) {
    printf("ID: %d, Name: %s, Location: %s, Capacity: %d\n", w.id, w.name, w.location, w.capacity);
    printf("Products:\n");
    for (int i = 0; i < w.size; i++) {
        printProduct(w.products[i]);
    }
}

void addProduct(Warehouse *w, Product p) {
    if (w->size == w->capacity) {
        printf("Warehouse is full!\n");
        return;
    }
    w->products[w->size] = p;
    w->size++;
}

void removeProduct(Warehouse *w, int id) {
    int index = -1;
    for (int i = 0; i < w->size; i++) {
        if (w->products[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Product not found!\n");
        return;
    }
    for (int i = index; i < w->size - 1; i++) {
        w->products[i] = w->products[i + 1];
    }
    w->size--;
}

int main() {
    // Create a warehouse
    Warehouse w1 = {1, "Warehouse 1", "Location 1", 10, malloc(sizeof(Product) * 10), 0};
    
    // Add some products
    addProduct(&w1, (Product) {1, "Product 1", 5, 10.99});
    addProduct(&w1, (Product) {2, "Product 2", 3, 20.99});
    addProduct(&w1, (Product) {3, "Product 3", 2, 5.99});
    addProduct(&w1, (Product) {4, "Product 4", 1, 50.00});
    
    // Print the warehouse and its products
    printWarehouse(w1);
    
    // Remove a product
    removeProduct(&w1, 2);
    
    // Print the warehouse and its products again
    printWarehouse(w1);
    
    // Free the memory allocated for the products
    free(w1.products);
    
    return 0;
}