//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: introspective
// WMS - Warehouse Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_ORDERS 50

enum {
    PRODUCT_NAME = 1,
    PRODUCT_QUANTITY = 2,
    PRODUCT_PRICE = 3,
    PRODUCT_LOCATION = 4,
    PRODUCT_CATEGORY = 5,
    PRODUCT_SUPPLIER = 6
};

enum {
    ORDER_ID = 1,
    ORDER_DATE = 2,
    ORDER_TOTAL = 3,
    ORDER_STATUS = 4
};

struct product {
    char name[100];
    int quantity;
    float price;
    char location[50];
    char category[50];
    char supplier[100];
};

struct order {
    int id;
    char date[20];
    float total;
    char status[20];
};

int main() {
    FILE *products_file = fopen("products.txt", "r+");
    FILE *orders_file = fopen("orders.txt", "r+");

    if (products_file == NULL || orders_file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    struct product products[MAX_PRODUCTS];
    struct order orders[MAX_ORDERS];

    int num_products = 0, num_orders = 0;

    while (fgets(orders[num_orders].date, sizeof(orders[num_orders].date), orders_file)!= NULL) {
        sscanf(orders[num_orders].date, "%s %d", orders[num_orders].status, &orders[num_orders].id);
        num_orders++;
    }

    while (fgets(products[num_products].name, sizeof(products[num_products].name), products_file)!= NULL) {
        sscanf(products[num_products].name, "%s %d %s %s %s %s", products[num_products].name, &products[num_products].quantity, products[num_products].price, products[num_products].location, products[num_products].category, products[num_products].supplier);
        num_products++;
    }

    fclose(products_file);
    fclose(orders_file);

    printf("Number of products: %d\n", num_products);
    printf("Number of orders: %d\n", num_orders);

    return 0;
}