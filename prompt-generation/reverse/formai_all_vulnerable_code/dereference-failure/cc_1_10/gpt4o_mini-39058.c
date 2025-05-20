//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int product_count = 0;
pthread_mutex_t inventory_lock;
pthread_cond_t inventory_cond;

void* add_product(void* arg) {
    Product new_product = *(Product*)arg;

    pthread_mutex_lock(&inventory_lock);
    if (product_count < MAX_PRODUCTS) {
        inventory[product_count++] = new_product;
        printf("Added product: %s, Quantity: %d\n", new_product.name, new_product.quantity);
        pthread_cond_signal(&inventory_cond);
    } else {
        printf("Inventory full! Cannot add product: %s\n", new_product.name);
    }
    pthread_mutex_unlock(&inventory_lock);

    return NULL;
}

void* remove_product(void* arg) {
    char* product_name = (char*)arg;

    pthread_mutex_lock(&inventory_lock);
    for (int i = 0; i < product_count; i++) {
        if (strcmp(inventory[i].name, product_name) == 0) {
            printf("Removed product: %s\n", inventory[i].name);
            inventory[i] = inventory[--product_count];
            pthread_cond_signal(&inventory_cond);
            pthread_mutex_unlock(&inventory_lock);
            return NULL;
        }
    }
    printf("Product %s not found to remove.\n", product_name);
    pthread_mutex_unlock(&inventory_lock);

    return NULL;
}

void* display_inventory(void* arg) {
    pthread_mutex_lock(&inventory_lock);
    while (product_count == 0) {
        pthread_cond_wait(&inventory_cond, &inventory_lock);
    }

    printf("Current Inventory:\n");
    for (int i = 0; i < product_count; i++) {
        printf(" - %s, Quantity: %d\n", inventory[i].name, inventory[i].quantity);
    }
    pthread_mutex_unlock(&inventory_lock);

    return NULL;
}

int main() {
    pthread_t threads[10];
    pthread_mutex_init(&inventory_lock, NULL);
    pthread_cond_init(&inventory_cond, NULL);

    // Adding products
    for (int i = 0; i < 5; i++) {
        Product product;
        snprintf(product.name, NAME_LENGTH, "Product%d", i + 1);
        product.quantity = (i + 1) * 10;

        pthread_create(&threads[i], NULL, add_product, &product);
        usleep(100000); // Sleep to simulate delay
    }

    // Displaying inventory
    pthread_create(&threads[5], NULL, display_inventory, NULL);
    usleep(200000); // Sleep to allow time for adding products

    // Removing products
    for (int i = 0; i < 3; i++) {
        char* product_name = malloc(NAME_LENGTH);
        snprintf(product_name, NAME_LENGTH, "Product%d", i + 1);
        pthread_create(&threads[6 + i], NULL, remove_product, product_name);
        usleep(150000); // Sleep to simulate delay
    }

    // Waiting for all threads to finish
    for (int i = 0; i < 8; i++) {
        pthread_join(threads[i], NULL);
    }

    // Final display of inventory
    pthread_create(&threads[8], NULL, display_inventory, NULL);
    pthread_join(threads[8], NULL);

    pthread_mutex_destroy(&inventory_lock);
    pthread_cond_destroy(&inventory_cond);
    return 0;
}