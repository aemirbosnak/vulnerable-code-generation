//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// Define the data structure for each item in the warehouse
typedef struct {
    int itemId;
    char itemName[100];
    int quantity;
} Item;

// Define the data structure for the warehouse itself
typedef struct {
    Item items[100];
    int numItems;
    int numThreads;
    int numSemaphores;
    sem_t *semaphores;
} Warehouse;

// Function to initialize the warehouse
void initWarehouse(Warehouse *warehouse, int numItems, int numThreads, int numSemaphores) {
    warehouse->numItems = numItems;
    warehouse->numThreads = numThreads;
    warehouse->numSemaphores = numSemaphores;
    warehouse->semaphores = (sem_t *)malloc(sizeof(sem_t) * numSemaphores);
    for (int i = 0; i < numSemaphores; i++) {
        sem_init(&warehouse->semaphores[i], 0, 0);
    }
}

// Function to add items to the warehouse
void addItem(Warehouse *warehouse, int itemId, char *itemName, int quantity) {
    if (warehouse->numItems >= 100) {
        printf("Warehouse is full, cannot add more items.\n");
        return;
    }
    Item newItem;
    strcpy(newItem.itemName, itemName);
    newItem.itemId = itemId;
    newItem.quantity = quantity;
    warehouse->items[warehouse->numItems] = newItem;
    warehouse->numItems++;
}

// Function to remove items from the warehouse
void removeItem(Warehouse *warehouse, int itemId) {
    for (int i = 0; i < warehouse->numItems; i++) {
        if (warehouse->items[i].itemId == itemId) {
            Item tempItem;
            strcpy(tempItem.itemName, warehouse->items[i].itemName);
            tempItem.itemId = itemId;
            tempItem.quantity = 0;
            warehouse->items[i] = tempItem;
            break;
        }
    }
}

// Function to update the quantity of an item in the warehouse
void updateQuantity(Warehouse *warehouse, int itemId, int quantity) {
    for (int i = 0; i < warehouse->numItems; i++) {
        if (warehouse->items[i].itemId == itemId) {
            warehouse->items[i].quantity = quantity;
            break;
        }
    }
}

// Function to print the current state of the warehouse
void printWarehouse(Warehouse *warehouse) {
    for (int i = 0; i < warehouse->numItems; i++) {
        printf("Item %d: %s (%d)\n", warehouse->items[i].itemId, warehouse->items[i].itemName, warehouse->items[i].quantity);
    }
}

// Function to simulate the warehouse workers
void *workerThread(void *warehousePtr) {
    Warehouse *warehouse = (Warehouse *)warehousePtr;
    for (int i = 0; i < warehouse->numItems; i++) {
        if (warehouse->items[i].quantity > 0) {
            printf("Worker %d is removing item %d from the warehouse\n", i, warehouse->items[i].itemId);
            sem_wait(&warehouse->semaphores[i]);
            warehouse->items[i].quantity = 0;
            sem_post(&warehouse->semaphores[i]);
        } else {
            printf("Worker %d cannot remove item %d from the warehouse, it is out of stock\n", i, warehouse->items[i].itemId);
        }
    }
}

// Main function
int main() {
    // Initialize the warehouse
    Warehouse warehouse;
    initWarehouse(&warehouse, 100, 4, 4);

    // Add some items to the warehouse
    addItem(&warehouse, 1, "Apple", 10);
    addItem(&warehouse, 2, "Orange", 5);
    addItem(&warehouse, 3, "Banana", 8);
    addItem(&warehouse, 4, "Grapes", 3);
    addItem(&warehouse, 5, "Strawberries", 9);

    // Print the current state of the warehouse
    printWarehouse(&warehouse);

    // Start the worker threads
    pthread_t threads[4];
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, workerThread, &warehouse);
    }

    // Wait for the worker threads to finish
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the current state of the warehouse after the workers have removed items
    printWarehouse(&warehouse);

    return 0;
}