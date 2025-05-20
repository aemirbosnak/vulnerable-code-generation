//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct customer {
    char name[50];
    int id;
};

struct item {
    char name[50];
    float price;
};

struct bill {
    struct customer customer;
    struct item items[10];
    int num_items;
    float total;
};

void add_item(struct bill *b, struct item i) {
    b->num_items++;
    strcpy(b->items[b->num_items-1].name, i.name);
    b->items[b->num_items-1].price = i.price;
}

float calculate_total(struct bill *b) {
    float total = 0;
    for (int i = 0; i < b->num_items; i++) {
        total += b->items[i].price;
    }
    return total;
}

void print_bill(struct bill *b) {
    printf("Customer: %s\n", b->customer.name);
    printf("Items:\n");
    for (int i = 0; i < b->num_items; i++) {
        printf("- %s: %.2f\n", b->items[i].name, b->items[i].price);
    }
    printf("Total: %.2f\n", calculate_total(b));
}

int main() {
    struct bill b;
    struct item item1 = {"Coffee", 2.50};
    struct item item2 = {"Tea", 1.50};
    add_item(&b, item1);
    add_item(&b, item2);
    print_bill(&b);
    return 0;
}