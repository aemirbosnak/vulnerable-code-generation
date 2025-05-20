//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Product structure
typedef struct product {
    int id;
    char *name;
    int quantity;
    int price;
} product;

// Inventory list
product *inventory;
int inventory_size = 0;

// Mutex for inventory access
pthread_mutex_t inventory_mutex;

// Thread function to add product to inventory
void *add_product(void *arg) {
    product *new_product = (product *)arg;

    pthread_mutex_lock(&inventory_mutex);
    inventory = realloc(inventory, (inventory_size + 1) * sizeof(product));
    inventory[inventory_size++] = *new_product;
    pthread_mutex_unlock(&inventory_mutex);

    return NULL;
}

// Thread function to remove product from inventory
void *remove_product(void *arg) {
    int product_id = *(int *)arg;

    pthread_mutex_lock(&inventory_mutex);
    for (int i = 0; i < inventory_size; i++) {
        if (inventory[i].id == product_id) {
            for (int j = i; j < inventory_size - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            inventory_size--;
            break;
        }
    }
    pthread_mutex_unlock(&inventory_mutex);

    return NULL;
}

// Thread function to list products in inventory
void *list_products(void *arg) {
    pthread_mutex_lock(&inventory_mutex);
    for (int i = 0; i < inventory_size; i++) {
        printf("Product %d: %s, Quantity: %d, Price: %d\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    pthread_mutex_unlock(&inventory_mutex);

    return NULL;
}

int main() {
    // Initialize inventory mutex
    pthread_mutex_init(&inventory_mutex, NULL);

    // Create threads to add products to inventory
    pthread_t add_threads[3];
    product products[3] = {
        {1, "Product 1", 10, 100},
        {2, "Product 2", 20, 200},
        {3, "Product 3", 30, 300}
    };
    for (int i = 0; i < 3; i++) {
        pthread_create(&add_threads[i], NULL, add_product, &products[i]);
    }

    // Join add threads
    for (int i = 0; i < 3; i++) {
        pthread_join(add_threads[i], NULL);
    }

    // Create thread to remove product from inventory
    pthread_t remove_thread;
    int product_id = 2;
    pthread_create(&remove_thread, NULL, remove_product, &product_id);

    // Join remove thread
    pthread_join(remove_thread, NULL);

    // Create thread to list products in inventory
    pthread_t list_thread;
    pthread_create(&list_thread, NULL, list_products, NULL);

    // Join list thread
    pthread_join(list_thread, NULL);

    // Destroy inventory mutex
    pthread_mutex_destroy(&inventory_mutex);

    return 0;
}