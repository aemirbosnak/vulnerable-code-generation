//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int stock;
    float price;
    struct product *next;
} product;

typedef product *product_ptr;

product_ptr head = NULL;

void addProduct(char *name, int stock, float price) {
    product_ptr newProduct = (product_ptr) malloc(sizeof(product));

    strcpy(newProduct->name, name);
    newProduct->stock = stock;
    newProduct->price = price;
    newProduct->next = head;

    head = newProduct;
}

void displayInventory() {
    product_ptr temp = head;

    printf("\nProduct Inventory System\n");
    printf("-------------------------\n");

    while (temp != NULL) {
        printf("%s\tStock: %d\tPrice: %.2f\n", temp->name, temp->stock, temp->price);
        temp = temp->next;
    }
}

void updateStock(char *name, int newStock) {
    product_ptr current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            current->stock = newStock;
            printf("Stock updated for %s\n", name);
            break;
        }
        current = current->next;
    }
}

void deleteProduct(char *name) {
    product_ptr current = head, previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("%s deleted from inventory\n", name);
            break;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    addProduct("Laptop", 10, 1000.50);
    addProduct("Monitor", 5, 200.00);
    addProduct("Mouse", 15, 10.00);
    addProduct("Keyboard", 12, 25.00);

    displayInventory();

    updateStock("Laptop", 8);
    updateStock("Monitor", 3);

    displayInventory();

    deleteProduct("Mouse");

    displayInventory();

    return 0;
}