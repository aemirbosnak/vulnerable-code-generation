//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    int quantity;
    float price;
};

struct customer {
    char name[50];
    char address[100];
    char phone[20];
};

struct order {
    int order_id;
    char date[20];
    struct medicine *medicines;
    int *quantities;
    int num_medicines;
    float total_price;
};

struct medical_store {
    struct medicine *medicines;
    int num_medicines;
    struct customer *customers;
    int num_customers;
    struct order *orders;
    int num_orders;
};

int main() {
    struct medical_store *store = malloc(sizeof(struct medical_store));
    store->medicines = malloc(100 * sizeof(struct medicine));
    store->num_medicines = 0;
    store->customers = malloc(100 * sizeof(struct customer));
    store->num_customers = 0;
    store->orders = malloc(100 * sizeof(struct order));
    store->num_orders = 0;

    // Add some sample medicines
    strcpy(store->medicines[0].name, "Paracetamol");
    store->medicines[0].quantity = 100;
    store->medicines[0].price = 10.0;

    strcpy(store->medicines[1].name, "Ibuprofen");
    store->medicines[1].quantity = 50;
    store->medicines[1].price = 15.0;

    strcpy(store->medicines[2].name, "Aspirin");
    store->medicines[2].quantity = 25;
    store->medicines[2].price = 5.0;

    // Add some sample customers
    strcpy(store->customers[0].name, "John Doe");
    strcpy(store->customers[0].address, "123 Main Street");
    strcpy(store->customers[0].phone, "555-1212");

    strcpy(store->customers[1].name, "Jane Doe");
    strcpy(store->customers[1].address, "456 Elm Street");
    strcpy(store->customers[1].phone, "555-1213");

    // Add some sample orders
    store->orders[0].order_id = 1;
    strcpy(store->orders[0].date, "2023-01-01");
    store->orders[0].medicines = malloc(2 * sizeof(struct medicine));
    store->orders[0].quantities = malloc(2 * sizeof(int));
    store->orders[0].num_medicines = 2;
    store->orders[0].total_price = 30.0;

    store->orders[1].order_id = 2;
    strcpy(store->orders[1].date, "2023-01-02");
    store->orders[1].medicines = malloc(3 * sizeof(struct medicine));
    store->orders[1].quantities = malloc(3 * sizeof(int));
    store->orders[1].num_medicines = 3;
    store->orders[1].total_price = 45.0;

    // Print the store's inventory
    printf("Inventory:\n");
    for (int i = 0; i < store->num_medicines; i++) {
        printf("%s: %d units, $%.2f\n", store->medicines[i].name, store->medicines[i].quantity, store->medicines[i].price);
    }

    // Print the store's customers
    printf("Customers:\n");
    for (int i = 0; i < store->num_customers; i++) {
        printf("%s: %s, %s, %s\n", store->customers[i].name, store->customers[i].address, store->customers[i].phone);
    }

    // Print the store's orders
    printf("Orders:\n");
    for (int i = 0; i < store->num_orders; i++) {
        printf("Order %d: %s, $%.2f\n", store->orders[i].order_id, store->orders[i].date, store->orders[i].total_price);
    }

    return 0;
}