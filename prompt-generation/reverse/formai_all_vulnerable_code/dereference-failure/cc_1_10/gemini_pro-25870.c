//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A Linked List Node to store a product
typedef struct Product {
    char *name;
    int quantity;
    float price;
    struct Product *next;
} Product;

// A Product Inventory System
typedef struct Inventory {
    Product *head;
    int num_products;
} Inventory;

// Create a new product
Product *create_product(char *name, int quantity, float price) {
    Product *product = (Product *)malloc(sizeof(Product));
    product->name = strdup(name);
    product->quantity = quantity;
    product->price = price;
    product->next = NULL;
    return product;
}

// Add a product to the inventory
void add_product(Inventory *inventory, Product *product) {
    if (inventory->head == NULL) {
        inventory->head = product;
    } else {
        Product *current = inventory->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = product;
    }
    inventory->num_products++;
}

// Remove a product from the inventory
void remove_product(Inventory *inventory, char *name) {
    if (inventory->head == NULL) {
        return;
    } else if (strcmp(inventory->head->name, name) == 0) {
        Product *temp = inventory->head;
        inventory->head = inventory->head->next;
        free(temp->name);
        free(temp);
        inventory->num_products--;
    } else {
        Product *current = inventory->head;
        while (current->next != NULL) {
            if (strcmp(current->next->name, name) == 0) {
                Product *temp = current->next;
                current->next = current->next->next;
                free(temp->name);
                free(temp);
                inventory->num_products--;
                return;
            }
            current = current->next;
        }
    }
}

// Get the total value of the inventory
float get_total_value(Inventory *inventory) {
    float total_value = 0;
    Product *current = inventory->head;
    while (current != NULL) {
        total_value += current->quantity * current->price;
        current = current->next;
    }
    return total_value;
}

// Print the inventory
void print_inventory(Inventory *inventory) {
    if (inventory->head == NULL) {
        printf("The inventory is empty.\n");
    } else {
        printf("The inventory contains the following products:\n");
        Product *current = inventory->head;
        while (current != NULL) {
            printf("%s: %d units at $%.2f each\n", current->name, current->quantity, current->price);
            current = current->next;
        }
    }
}

// Free the inventory
void free_inventory(Inventory *inventory) {
    Product *current = inventory->head;
    while (current != NULL) {
        Product *temp = current;
        current = current->next;
        free(temp->name);
        free(temp);
    }
    free(inventory);
}

// MAIN
int main() {
    // Create a new inventory
    Inventory *inventory = (Inventory *)malloc(sizeof(Inventory));
    inventory->head = NULL;
    inventory->num_products = 0;

    // Add some products to the inventory
    add_product(inventory, create_product("Apple", 10, 0.5));
    add_product(inventory, create_product("Orange", 15, 0.6));
    add_product(inventory, create_product("Banana", 20, 0.7));

    // Print the inventory
    print_inventory(inventory);

    // Get the total value of the inventory
    printf("The total value of the inventory is: $%.2f\n", get_total_value(inventory));

    // Remove a product from the inventory
    remove_product(inventory, "Apple");

    // Print the inventory
    print_inventory(inventory);

    // Free the inventory
    free_inventory(inventory);

    return 0;
}