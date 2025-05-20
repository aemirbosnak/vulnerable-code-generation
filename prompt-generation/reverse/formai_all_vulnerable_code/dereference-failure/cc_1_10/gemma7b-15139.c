//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100
#define MAX_CUSTOMERS 50

struct product
{
    char name[20];
    int quantity;
    float price;
};

struct customer
{
    char name[20];
    int customer_id;
    float total_spent;
};

void add_product(struct product *products, int *num_products)
{
    products = (struct product *)realloc(products, (*num_products + 1) * sizeof(struct product));
    products[*num_products].quantity = 0;
    (*num_products)++;
}

void add_customer(struct customer *customers, int *num_customers)
{
    customers = (struct customer *)realloc(customers, (*num_customers + 1) * sizeof(struct customer));
    customers[*num_customers].total_spent = 0.0f;
    (*num_customers)++;
}

int main()
{
    struct product products[MAX_PRODUCTS];
    int num_products = 0;

    struct customer customers[MAX_CUSTOMERS];
    int num_customers = 0;

    // Add products and customers

    add_product(products, &num_products);
    add_product(products, &num_products);
    add_customer(customers, &num_customers);
    add_customer(customers, &num_customers);

    // Print products and customers

    for (int i = 0; i < num_products; i++)
    {
        printf("%s, %d, %.2f\n", products[i].name, products[i].quantity, products[i].price);
    }

    for (int i = 0; i < num_customers; i++)
    {
        printf("%s, %d, %.2f\n", customers[i].name, customers[i].customer_id, customers[i].total_spent);
    }

    return 0;
}