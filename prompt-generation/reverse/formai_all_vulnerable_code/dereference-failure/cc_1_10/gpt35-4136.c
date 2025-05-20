//FormAI DATASET v1.0 Category: Product Inventory System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    int quantity;
    float price;
    int id;
} Product;

typedef struct {
    Product *products;
    int size;
    int capacity;
} Inventory;

Inventory *create_inventory(int capacity)
{
    Inventory *inv = malloc(sizeof(Inventory));
    inv->products = malloc(sizeof(Product) * capacity);
    inv->size = 0;
    inv->capacity = capacity;
    return inv;
}

void destroy_inventory(Inventory *inv)
{
    for (int i = 0; i < inv->size; i++) {
        free(inv->products[i].name);
    }
    free(inv->products);
    free(inv);
}

void add_product(Inventory *inv, char *name, int quantity, float price)
{
    if (inv->size >= inv->capacity) {
        inv->capacity *= 2;
        inv->products = realloc(inv->products, sizeof(Product) * inv->capacity);
    }
    int id = inv->size++;
    inv->products[id].name = malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(inv->products[id].name, name);
    inv->products[id].quantity = quantity;
    inv->products[id].price = price;
    inv->products[id].id = id;
}

void remove_product(Inventory *inv, int id)
{
    free(inv->products[id].name);
    for (int i = id; i < inv->size - 1; i++) {
        inv->products[i] = inv->products[i+1];
        inv->products[i].id = i;
    }
    inv->size--;
}

void print_inventory(Inventory *inv)
{
    printf("ID | Product Name | Quantity | Price\n");
    for (int i = 0; i < inv->size; i++) {
        printf("%d | %s | %d | %.2f\n", inv->products[i].id, inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
}

int main()
{
    Inventory *inv = create_inventory(10);
    add_product(inv, "Shampoo", 5, 3.50);
    add_product(inv, "Toothpaste", 10, 2.00);
    add_product(inv, "Soap", 7, 1.50);
    add_product(inv, "Body Lotion", 3, 4.75);
    print_inventory(inv);
    remove_product(inv, 1);
    printf("\nAfter removing Toothpaste:\n");
    print_inventory(inv);
    destroy_inventory(inv);
    return 0;
}