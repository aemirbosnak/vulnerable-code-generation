//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_NUM_ITEMS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    double price;
} Item;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Item items[MAX_NUM_ITEMS];
    int num_items;
} Customer;

void add_item(Item* item, Customer* customer) {
    if (customer->num_items >= MAX_NUM_ITEMS) {
        printf("Sorry, the customer has too many items!\n");
        return;
    }
    strcpy(item->name, customer->name);
    item->quantity = 1;
    item->price = 0.0;
    customer->items[customer->num_items] = *item;
    customer->num_items++;
}

void remove_item(Customer* customer, int index) {
    if (index >= customer->num_items || index < 0) {
        printf("Invalid item index!\n");
        return;
    }
    customer->num_items--;
    for (int i = index; i < customer->num_items; i++) {
        customer->items[i] = customer->items[i + 1];
    }
}

void display_items(Customer* customer) {
    printf("Items for %s:\n", customer->name);
    for (int i = 0; i < customer->num_items; i++) {
        printf("%s - %d - $%.2f\n", customer->items[i].name, customer->items[i].quantity, customer->items[i].price);
    }
}

int main() {
    Customer customer1;
    strcpy(customer1.name, "Alice");

    Item item1;
    strcpy(item1.name, "Apple");
    item1.quantity = 10;
    item1.price = 0.50;

    add_item(&item1, &customer1);

    display_items(&customer1);

    remove_item(&customer1, 0);

    display_items(&customer1);

    return 0;
}