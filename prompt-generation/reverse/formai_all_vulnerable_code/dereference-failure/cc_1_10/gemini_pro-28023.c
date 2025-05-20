//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the product struct
typedef struct product {
    int id;
    char *name;
    int quantity;
    double price;
} product_t;

// Define the inventory list
product_t *inventory;
int inventory_size = 0;

// Define the mutex lock
pthread_mutex_t inventory_lock;

// Define the thread function
void *thread_func(void *arg) {
    // Get the product ID
    int product_id = (int)arg;

    // Acquire the mutex lock
    pthread_mutex_lock(&inventory_lock);

    // Find the product in the inventory
    int i;
    for (i = 0; i < inventory_size; i++) {
        if (inventory[i].id == product_id) {
            break;
        }
    }

    // If the product was found, decrement the quantity
    if (i < inventory_size) {
        inventory[i].quantity--;
    }

    // Release the mutex lock
    pthread_mutex_unlock(&inventory_lock);

    return NULL;
}

// Main function
int main() {
    // Initialize the inventory list
    inventory = malloc(sizeof(product_t) * 10);
    inventory_size = 10;

    // Initialize the mutex lock
    pthread_mutex_init(&inventory_lock, NULL);

    // Create the threads
    pthread_t threads[10];
    int i;
    for (i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *)i);
    }

    // Join the threads
    for (i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex lock
    pthread_mutex_destroy(&inventory_lock);

    // Free the inventory list
    free(inventory);

    return 0;
}