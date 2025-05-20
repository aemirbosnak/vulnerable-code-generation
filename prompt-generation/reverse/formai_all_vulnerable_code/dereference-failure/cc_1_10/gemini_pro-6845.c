//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
    int id;
    char *name;
    int quantity;
    float price;
} product;

typedef struct {
    int id;
    int quantity;
} order;

typedef struct {
    product *product;
    int quantity;
} order_item;

typedef struct {
    order *order;
    order_item *order_items;
    int num_order_items;
} transaction;

pthread_mutex_t inventory_mutex = PTHREAD_MUTEX_INITIALIZER;

product *inventory;
int num_products;

void *handle_transaction(void *arg) {
    transaction *t = (transaction *)arg;

    pthread_mutex_lock(&inventory_mutex);

    for (int i = 0; i < t->num_order_items; i++) {
        product *p = t->order_items[i].product;
        int quantity = t->order_items[i].quantity;

        if (p->quantity < quantity) {
            printf("Product %s is out of stock\n", p->name);
            pthread_mutex_unlock(&inventory_mutex);
            return NULL;
        }

        p->quantity -= quantity;
    }

    pthread_mutex_unlock(&inventory_mutex);

    printf("Transaction complete\n");

    return NULL;
}

int main() {
    inventory = malloc(sizeof(product) * 10);
    num_products = 10;

    inventory[0].id = 1;
    inventory[0].name = "Apple";
    inventory[0].quantity = 100;
    inventory[0].price = 1.0;

    inventory[1].id = 2;
    inventory[1].name = "Banana";
    inventory[1].quantity = 50;
    inventory[1].price = 2.0;

    inventory[2].id = 3;
    inventory[2].name = "Orange";
    inventory[2].quantity = 25;
    inventory[2].price = 3.0;

    inventory[3].id = 4;
    inventory[3].name = "Grape";
    inventory[3].quantity = 15;
    inventory[3].price = 4.0;

    inventory[4].id = 5;
    inventory[4].name = "Strawberry";
    inventory[4].quantity = 10;
    inventory[4].price = 5.0;

    inventory[5].id = 6;
    inventory[5].name = "Blueberry";
    inventory[5].quantity = 5;
    inventory[5].price = 6.0;

    inventory[6].id = 7;
    inventory[6].name = "Raspberry";
    inventory[6].quantity = 3;
    inventory[6].price = 7.0;

    inventory[7].id = 8;
    inventory[7].name = "Blackberry";
    inventory[7].quantity = 2;
    inventory[7].price = 8.0;

    inventory[8].id = 9;
    inventory[8].name = "Pineapple";
    inventory[8].quantity = 1;
    inventory[8].price = 9.0;

    inventory[9].id = 10;
    inventory[9].name = "Mango";
    inventory[9].quantity = 0;
    inventory[9].price = 10.0;

    order *o = malloc(sizeof(order));
    o->id = 1;
    o->quantity = 3;

    order_item *oi = malloc(sizeof(order_item) * o->quantity);
    oi[0].product = &inventory[0];
    oi[0].quantity = 1;
    oi[1].product = &inventory[1];
    oi[1].quantity = 1;
    oi[2].product = &inventory[2];
    oi[2].quantity = 1;

    transaction *t = malloc(sizeof(transaction));
    t->order = o;
    t->order_items = oi;
    t->num_order_items = o->quantity;

    pthread_t tid;
    pthread_create(&tid, NULL, handle_transaction, t);

    pthread_join(tid, NULL);

    return 0;
}