//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: Dennis Ritchie
/*
 * Product Inventory System
 *
 * This program is a simple product inventory system that allows users to add,
 * remove, and search for products in a database. The program uses a linked
 * list to store the products, and it includes functions to traverse the list,
 * add a new product to the list, remove a product from the list, and search
 * for a product in the list.
 *
 * The program is written in a Dennis Ritchie style, which is a programming
 * style that is characterized by its use of simple, concise code and its
 * avoidance of unnecessary abstractions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * A product is a simple struct that contains a name, a price, and a quantity.
 */
typedef struct Product {
    char *name;
    float price;
    int quantity;
} Product;

/*
 * A linked list is a data structure that consists of a series of nodes,
 * where each node contains a pointer to the next node in the list.
 */
typedef struct Node {
    Product product;
    struct Node *next;
} Node;

/*
 * The head of the linked list is a pointer to the first node in the list.
 */
Node *head = NULL;

/*
 * create_product creates a new product and returns a pointer to the product.
 */
Product *create_product(char *name, float price, int quantity) {
    Product *product = malloc(sizeof(Product));
    product->name = strdup(name);
    product->price = price;
    product->quantity = quantity;
    return product;
}

/*
 * add_product adds a product to the linked list.
 */
void add_product(Product *product) {
    Node *node = malloc(sizeof(Node));
    node->product = *product;
    node->next = head;
    head = node;
}

/*
 * remove_product removes a product from the linked list.
 */
void remove_product(char *name) {
    Node *current = head;
    Node *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->product.name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }

        previous = current;
        current = current->next;
    }
}

/*
 * search_product searches for a product in the linked list.
 */
Product *search_product(char *name) {
    Node *current = head;

    while (current != NULL) {
        if (strcmp(current->product.name, name) == 0) {
            return &current->product;
        }

        current = current->next;
    }

    return NULL;
}

/*
 * print_list prints the linked list.
 */
void print_list() {
    Node *current = head;

    while (current != NULL) {
        printf("%s %f %d\n", current->product.name, current->product.price, current->product.quantity);
        current = current->next;
    }
}

/*
 * free_list frees the linked list.
 */
void free_list() {
    Node *current = head;

    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }

    head = NULL;
}

/*
 * The main function.
 */
int main() {
    Product *product1 = create_product("Apple", 1.00, 10);
    Product *product2 = create_product("Banana", 2.00, 20);
    Product *product3 = create_product("Orange", 3.00, 30);

    add_product(product1);
    add_product(product2);
    add_product(product3);

    print_list();

    Product *product = search_product("Apple");
    if (product != NULL) {
        printf("Found product: %s %f %d\n", product->name, product->price, product->quantity);
    } else {
        printf("Product not found.\n");
    }

    remove_product("Banana");

    print_list();

    free_list();

    return 0;
}