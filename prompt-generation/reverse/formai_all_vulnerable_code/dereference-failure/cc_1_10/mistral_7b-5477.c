//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define TABLE_SIZE 101

typedef struct Product {
    char name[50];
    int stock;
    struct Product *next;
} Product;

typedef struct HashTable {
    Product **data;
} HashTable;

HashTable create_hash_table() {
    HashTable table;
    table.data = malloc(TABLE_SIZE * sizeof(Product*));
    for (int i = 0; i < TABLE_SIZE; ++i) {
        table.data[i] = NULL;
    }
    return table;
}

int hash_function(const char *name) {
    int hash = 0;
    for (int i = 0; i < strlen(name); ++i) {
        hash += tolower((unsigned char)name[i]);
    }
    return hash % TABLE_SIZE;
}

Product *create_product(const char *name, int stock) {
    Product *product = malloc(sizeof(Product));
    strcpy(product->name, name);
    product->stock = stock;
    product->next = NULL;
    return product;
}

void add_product(HashTable *table, const char *name, int stock) {
    int hash = hash_function(name);
    Product *product = create_product(name, stock);

    if (table->data[hash] == NULL) {
        table->data[hash] = product;
    } else {
        Product *current = table->data[hash];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = product;
    }
}

Product *find_product(HashTable *table, const char *name) {
    int hash = hash_function(name);
    Product *current = table->data[hash];

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

void remove_product(HashTable *table, const char *name) {
    int hash = hash_function(name);
    Product *prev = NULL, *current = table->data[hash];

    while (current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    if (prev == NULL) {
        table->data[hash] = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

int main() {
    HashTable table = create_hash_table();

    add_product(&table, "Apple", 10);
    add_product(&table, "Banana", 5);
    add_product(&table, "Cherry", 8);

    printf("Product: Apple, Stock: %d\n", find_product(&table, "Apple")->stock);
    printf("Product: Grape, Stock: %d\n", find_product(&table, "Grape")->stock);

    remove_product(&table, "Apple");

    return 0;
}