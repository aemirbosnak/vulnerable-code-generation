//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <errno.h>

#define WAREHOUSE_SIZE 100
#define MAX_ORDERS 100
#define MAX_ORDER_SIZE 100

typedef struct {
    int order_id;
    int num_items;
    int items[MAX_ORDER_SIZE];
} order_t;

typedef struct {
    int warehouse;
    int num_orders;
    order_t orders[MAX_ORDERS];
    pthread_mutex_t lock;
} warehouse_t;

warehouse_t warehouses[WAREHOUSE_SIZE];
pthread_t warehouse_threads[WAREHOUSE_SIZE];

bool orders_ready = false;

void *warehouse_thread(void *arg) {
    int warehouse = (int)arg;
    while (!orders_ready) {
        // Yield to other threads.
        usleep(100000);
    }
    pthread_mutex_lock(&warehouses[warehouse].lock);
    for (int i = 0; i < warehouses[warehouse].num_orders; i++) {
        order_t *order = &warehouses[warehouse].orders[i];
        for (int j = 0; j < order->num_items; j++) {
            // Process the item.
            printf("Processing item %d from order %d in warehouse %d\n", order->items[j], order->order_id, warehouse);
        }
    }
    pthread_mutex_unlock(&warehouses[warehouse].lock);
    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <num_warehouses>\n", argv[0]);
        return 1;
    }
    int num_warehouses = atoi(argv[1]);
    if (num_warehouses <= 0) {
        fprintf(stderr, "Invalid number of warehouses: %d\n", num_warehouses);
        return 1;
    }
    for (int i = 0; i < num_warehouses; i++) {
        warehouses[i].warehouse = i;
        warehouses[i].num_orders = 0;
        pthread_mutex_init(&warehouses[i].lock, NULL);
    }
    // Create the warehouse threads.
    for (int i = 0; i < num_warehouses; i++) {
        if (pthread_create(&warehouse_threads[i], NULL, warehouse_thread, (void *)i)) {
            fprintf(stderr, "Error creating warehouse thread: %s\n", strerror(errno));
            return 1;
        }
    }
    // Generate orders.
    for (int i = 0; i < MAX_ORDERS; i++) {
        int warehouse = rand() % num_warehouses;
        warehouses[warehouse].orders[warehouses[warehouse].num_orders].order_id = i;
        warehouses[warehouse].orders[warehouses[warehouse].num_orders].num_items = rand() % MAX_ORDER_SIZE;
        for (int j = 0; j < warehouses[warehouse].orders[warehouses[warehouse].num_orders].num_items; j++) {
            warehouses[warehouse].orders[warehouses[warehouse].num_orders].items[j] = rand() % 1000;
        }
        warehouses[warehouse].num_orders++;
    }
    orders_ready = true;
    // Wait for the warehouse threads to finish.
    for (int i = 0; i < num_warehouses; i++) {
        pthread_join(warehouse_threads[i], NULL);
    }
    return 0;
}