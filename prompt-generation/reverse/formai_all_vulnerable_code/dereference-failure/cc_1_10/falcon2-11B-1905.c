//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int product_id;
    char name[50];
    int price;
    int quantity;
} Product;

typedef struct {
    int product_id;
    char name[50];
    int price;
    int quantity;
    Product* next;
} ProductList;

ProductList* head = NULL;

void add_product(Product* product) {
    ProductList* new_list = malloc(sizeof(ProductList));
    new_list->product_id = product->product_id;
    strcpy(new_list->name, product->name);
    new_list->price = product->price;
    new_list->quantity = product->quantity;
    new_list->next = NULL;

    if (head == NULL) {
        head = new_list;
    } else {
        ProductList* current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_list;
    }
}

void print_product_list() {
    if (head == NULL) {
        printf("Inventory is empty.\n");
    } else {
        ProductList* current = head;
        printf("Inventory:\n");
        while (current!= NULL) {
            printf("Product ID: %d, Name: %s, Price: %d, Quantity: %d\n",
                   current->product_id, current->name, current->price, current->quantity);
            current = current->next;
        }
    }
}

void remove_product(int product_id) {
    if (head == NULL) {
        printf("Inventory is empty.\n");
    } else {
        ProductList* current = head;
        while (current!= NULL) {
            if (current->product_id == product_id) {
                break;
            }
            current = current->next;
        }
        if (current == NULL) {
            printf("Product not found.\n");
        } else {
            ProductList* temp = head;
            while (temp->next!= NULL) {
                if (temp->next == current) {
                    break;
                }
                temp = temp->next;
            }
            if (temp->next == NULL) {
                head = NULL;
            } else {
                temp->next = current->next;
                free(current);
            }
        }
    }
}

void update_product_price(int product_id, int new_price) {
    if (head == NULL) {
        printf("Inventory is empty.\n");
    } else {
        ProductList* current = head;
        while (current!= NULL) {
            if (current->product_id == product_id) {
                current->price = new_price;
                break;
            }
            current = current->next;
        }
        if (current == NULL) {
            printf("Product not found.\n");
        }
    }
}

void update_product_quantity(int product_id, int new_quantity) {
    if (head == NULL) {
        printf("Inventory is empty.\n");
    } else {
        ProductList* current = head;
        while (current!= NULL) {
            if (current->product_id == product_id) {
                current->quantity = new_quantity;
                break;
            }
            current = current->next;
        }
        if (current == NULL) {
            printf("Product not found.\n");
        }
    }
}

int main() {
    // Add products to the inventory
    add_product(&(Product){1, "Apple", 0.99, 100});
    add_product(&(Product){2, "Banana", 0.75, 75});
    add_product(&(Product){3, "Orange", 1.25, 50});

    // Print the inventory
    printf("Inventory:\n");
    print_product_list();

    // Remove a product from the inventory
    remove_product(1);

    // Update the price of a product in the inventory
    update_product_price(2, 0.85);

    // Update the quantity of a product in the inventory
    update_product_quantity(3, 60);

    // Print the updated inventory
    printf("Inventory:\n");
    print_product_list();

    return 0;
}