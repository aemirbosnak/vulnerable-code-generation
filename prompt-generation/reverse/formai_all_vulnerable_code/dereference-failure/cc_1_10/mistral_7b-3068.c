//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define PRODUCT_NAME_SIZE 50

typedef struct {
    char name[PRODUCT_NAME_SIZE];
    int quantity;
    struct product *next;
} product;

product *head = NULL;

void load_inventory(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return;

    char line[100];
    product *new_product;
    while (fgets(line, sizeof(line), file)) {
        product *new_product = malloc(sizeof(product));
        strcpy(new_product->name, strtok(line, ","));
        new_product->quantity = atoi(strtok(NULL, ",\n"));
        new_product->next = head;
        head = new_product;
    }

    fclose(file);
}

void save_inventory(const char *filename) {
    FILE *file = fopen(filename, "w");
    product *current = head;
    while (current) {
        fprintf(file, "%s,%d\n", current->name, current->quantity);
        current = current->next;
    }
    fclose(file);
}

void add_product(const char *name, int quantity) {
    product *new_product = malloc(sizeof(product));
    strcpy(new_product->name, name);
    new_product->quantity = quantity;
    new_product->next = head;
    head = new_product;
}

void remove_product(const char *name) {
    product *current = head, *previous = NULL;

    while (current && strcmp(current->name, name)) {
        previous = current;
        current = current->next;
    }

    if (!current) return;

    if (previous) previous->next = current->next;
    else head = current->next;

    free(current);
}

void display_inventory() {
    product *current = head;
    while (current) {
        printf("%s: %d\n", current->name, current->quantity);
        current = current->next;
    }
}

int main() {
    load_inventory("inventory.txt");

    add_product("Laptop", 5);
    add_product("Mouse", 10);

    display_inventory();

    save_inventory("inventory.txt");

    remove_product("Laptop");

    display_inventory();

    free(head);

    return 0;
}