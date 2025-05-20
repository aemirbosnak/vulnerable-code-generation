//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    char name[50];
    int quantity;
    float price;
} product;

typedef struct node {
    product data;
    struct node *next;
} node;

typedef struct inventory {
    node *head;
    node *tail;
    int size;
} inventory;

inventory *create_inventory() {
    inventory *new_inventory = (inventory *)malloc(sizeof(inventory));
    new_inventory->head = NULL;
    new_inventory->tail = NULL;
    new_inventory->size = 0;
    return new_inventory;
}

void add_product(inventory *inv, product new_product) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = new_product;
    new_node->next = NULL;
    if (inv->head == NULL) {
        inv->head = new_node;
        inv->tail = new_node;
    } else {
        inv->tail->next = new_node;
        inv->tail = new_node;
    }
    inv->size++;
}

product *find_product(inventory *inv, char *name) {
    node *current = inv->head;
    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            return &(current->data);
        }
        current = current->next;
    }
    return NULL;
}

void update_product(inventory *inv, char *name, product updated_product) {
    product *product_to_update = find_product(inv, name);
    if (product_to_update != NULL) {
        product_to_update->quantity = updated_product.quantity;
        product_to_update->price = updated_product.price;
    }
}

void delete_product(inventory *inv, char *name) {
    node *current = inv->head;
    node *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            if (current == inv->head) {
                inv->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            inv->size--;
            return;
        }
        previous = current;
        current = current->next;
    }
}

void print_inventory(inventory *inv) {
    node *current = inv->head;
    while (current != NULL) {
        printf("Product: %s, Quantity: %d, Price: %.2f\n", current->data.name, current->data.quantity, current->data.price);
        current = current->next;
    }
}

int main() {
    inventory *my_inventory = create_inventory();
    product product1 = {"iPhone", 10, 1000.0};
    product product2 = {"iPad", 5, 500.0};
    product product3 = {"MacBook", 3, 1500.0};
    add_product(my_inventory, product1);
    add_product(my_inventory, product2);
    add_product(my_inventory, product3);
    print_inventory(my_inventory);
    product *product_to_update = find_product(my_inventory, "iPhone");
    if (product_to_update != NULL) {
        product_to_update->quantity = 15;
        product_to_update->price = 1200.0;
    }
    update_product(my_inventory, "iPad", (product){"iPad", 7, 550.0});
    delete_product(my_inventory, "MacBook");
    print_inventory(my_inventory);
    return 0;
}