//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 10

typedef struct {
    char name[MAX_NAME_LEN];
    int price;
    int quantity;
} Item;

typedef struct {
    char customer_name[MAX_NAME_LEN];
    int customer_id;
    int total_price;
} Customer;

int main() {
    int num_items, num_customers;
    scanf("%d %d", &num_items, &num_customers);

    Item items[MAX_ITEMS];
    Customer customers[num_customers];

    for (int i = 0; i < num_items; i++) {
        scanf("%s %d %d", items[i].name, &items[i].price, &items[i].quantity);
    }

    for (int i = 0; i < num_customers; i++) {
        scanf("%s %d", customers[i].customer_name, &customers[i].customer_id);
    }

    for (int i = 0; i < num_customers; i++) {
        int total_price = 0;
        for (int j = 0; j < num_items; j++) {
            if (items[j].quantity > 0) {
                int price_per_item = items[j].price / items[j].quantity;
                if (customers[i].customer_id == j) {
                    total_price += price_per_item * items[j].quantity;
                }
            }
        }
        customers[i].total_price = total_price;
    }

    for (int i = 0; i < num_customers; i++) {
        printf("%s: $%d\n", customers[i].customer_name, customers[i].total_price);
    }

    return 0;
}