//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LEN 1000
#define MAX_FEAT 50

typedef struct {
    char *name;
    int age;
    float income;
} customer_t;

typedef struct {
    char *product;
    int price;
} product_t;

typedef struct {
    customer_t *customers;
    product_t *products;
    int num_customers;
    int num_products;
} database_t;

database_t *load_database(const char *file_name) {
    database_t *db = malloc(sizeof(database_t));
    FILE *file = fopen(file_name, "r");
    char line[MAX_LEN];
    int i, j;

    // Load customers
    db->num_customers = 0;
    while (fgets(line, MAX_LEN, file) != NULL) {
        customer_t *customer = malloc(sizeof(customer_t));
        sscanf(line, "%s %d %f", customer->name, &customer->age, &customer->income);
        db->customers = realloc(db->customers, (db->num_customers + 1) * sizeof(customer_t));
        db->customers[db->num_customers] = *customer;
        db->num_customers++;
    }

    // Load products
    db->num_products = 0;
    while (fgets(line, MAX_LEN, file) != NULL) {
        product_t *product = malloc(sizeof(product_t));
        sscanf(line, "%s %d", product->product, &product->price);
        db->products = realloc(db->products, (db->num_products + 1) * sizeof(product_t));
        db->products[db->num_products] = *product;
        db->num_products++;
    }

    fclose(file);
    return db;
}

void print_database(database_t *db) {
    int i, j;
    for (i = 0; i < db->num_customers; i++) {
        for (j = 0; j < db->num_products; j++) {
            printf("%s (%d) purchased %s for %d\n", db->customers[i].name, db->customers[i].age, db->products[j].product, db->products[j].price);
        }
    }
}

int main() {
    database_t *db = load_database("customer_data.txt");
    print_database(db);
    return 0;
}