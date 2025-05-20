//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    char name[50];
    float price;
    int quantity;
    struct product *next;
} Product;

void add_product(Product **head, const char *name, float price, int quantity);
Product *search_product(Product *head, const char *name);
void display_inventory(Product *head);

int main() {
    Product *head = NULL;

    add_product(&head, "Laptop", 800.0, 5);
    add_product(&head, "Monitor", 200.0, 10);
    add_product(&head, "Keyboard", 20.0, 20);
    add_product(&head, "Mouse", 15.0, 30);

    display_inventory(head);

    Product *product = search_product(head, "Monitor");
    if (product != NULL) {
        printf("Found product 'Monitor'. Current quantity: %d\n", product->quantity);
    } else {
        printf("Product 'Monitor' not found.\n");
    }

    return 0;
}

void add_product(Product **head, const char *name, float price, int quantity) {
    Product *new_product = (Product *)malloc(sizeof(Product));

    strcpy(new_product->name, name);
    new_product->price = price;
    new_product->quantity = quantity;
    new_product->next = *head;

    *head = new_product;
}

Product *search_product(Product *head, const char *name) {
    Product *current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

void display_inventory(Product *head) {
    Product *current = head;

    printf("\nProduct Inventory:\n");
    while (current != NULL) {
        printf("%-20s %6.2f %d\n", current->name, current->price, current->quantity);
        current = current->next;
    }
}