//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Warehouse capacity
#define CAPACITY 100

// Item structure
typedef struct item {
    int id;
    char name[20];
    int quantity;
} item_t;

// Warehouse structure
typedef struct warehouse {
    item_t items[CAPACITY];
    int count;
    pthread_mutex_t lock;
} warehouse_t;

// Warehouse instance
warehouse_t warehouse;

// Thread function to add items to the warehouse
void *add_item(void *arg) {
    item_t *item = (item_t *)arg;

    // Acquire the warehouse lock
    pthread_mutex_lock(&warehouse.lock);

    // Check if the warehouse is full
    if (warehouse.count == CAPACITY) {
        printf("Warehouse is full! Item %d (%s) cannot be added.\n", item->id, item->name);
    } else {
        // Add the item to the warehouse
        warehouse.items[warehouse.count++] = *item;
        printf("Item %d (%s) added to the warehouse.\n", item->id, item->name);
    }

    // Release the warehouse lock
    pthread_mutex_unlock(&warehouse.lock);

    return NULL;
}

// Thread function to remove items from the warehouse
void *remove_item(void *arg) {
    int id = *(int *)arg;

    // Acquire the warehouse lock
    pthread_mutex_lock(&warehouse.lock);

    // Find the item in the warehouse
    int index = -1;
    for (int i = 0; i < warehouse.count; i++) {
        if (warehouse.items[i].id == id) {
            index = i;
            break;
        }
    }

    // Check if the item was found
    if (index == -1) {
        printf("Item %d not found in the warehouse.\n", id);
    } else {
        // Remove the item from the warehouse
        warehouse.count--;
        for (int i = index; i < warehouse.count; i++) {
            warehouse.items[i] = warehouse.items[i + 1];
        }
        printf("Item %d removed from the warehouse.\n", id);
    }

    // Release the warehouse lock
    pthread_mutex_unlock(&warehouse.lock);

    return NULL;
}

int main() {
    // Initialize the warehouse
    warehouse.count = 0;
    pthread_mutex_init(&warehouse.lock, NULL);

    // Create threads to add and remove items from the warehouse
    pthread_t threads[10];
    for (int i = 0; i < 5; i++) {
        item_t item = { .id = i, .name = "Item A", .quantity = 10 };
        pthread_create(&threads[i], NULL, add_item, &item);
    }
    for (int i = 5; i < 10; i++) {
        int id = i;
        pthread_create(&threads[i], NULL, remove_item, &id);
    }

    // Join the threads
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the warehouse lock
    pthread_mutex_destroy(&warehouse.lock);

    return 0;
}