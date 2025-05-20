//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the product structure
typedef struct product {
    int id;
    char *name;
    int quantity;
    float price;
} product_t;

// Create a mutex to protect the shared product inventory
pthread_mutex_t inventory_mutex = PTHREAD_MUTEX_INITIALIZER;

// Create a condition variable to signal when the inventory has changed
pthread_cond_t inventory_cond = PTHREAD_COND_INITIALIZER;

// Create an array of products
product_t products[] = {
    {1, "Apple", 100, 1.0},
    {2, "Orange", 50, 1.5},
    {3, "Banana", 25, 2.0},
    {4, "Grape", 10, 2.5},
    {5, "Strawberry", 5, 3.0}
};

// The number of products in the inventory
int num_products = sizeof(products) / sizeof(product_t);

// Create a thread to simulate a customer purchasing a product
void *customer_thread(void *arg) {
    // Get the product ID from the argument
    int product_id = *(int *)arg;

    // Lock the mutex to protect the shared product inventory
    pthread_mutex_lock(&inventory_mutex);

    // Find the product in the inventory
    product_t *product = NULL;
    for (int i = 0; i < num_products; i++) {
        if (products[i].id == product_id) {
            product = &products[i];
            break;
        }
    }

    // If the product was found, decrement its quantity
    if (product != NULL) {
        product->quantity--;
        printf("Customer purchased %s (quantity: %d)\n", product->name, product->quantity);
    } else {
        printf("Product not found\n");
    }

    // Signal that the inventory has changed
    pthread_cond_signal(&inventory_cond);

    // Unlock the mutex
    pthread_mutex_unlock(&inventory_mutex);

    return NULL;
}

// Create a thread to simulate a supplier restocking a product
void *supplier_thread(void *arg) {
    // Get the product ID from the argument
    int product_id = *(int *)arg;

    // Lock the mutex to protect the shared product inventory
    pthread_mutex_lock(&inventory_mutex);

    // Find the product in the inventory
    product_t *product = NULL;
    for (int i = 0; i < num_products; i++) {
        if (products[i].id == product_id) {
            product = &products[i];
            break;
        }
    }

    // If the product was found, increment its quantity
    if (product != NULL) {
        product->quantity++;
        printf("Supplier restocked %s (quantity: %d)\n", product->name, product->quantity);
    } else {
        printf("Product not found\n");
    }

    // Signal that the inventory has changed
    pthread_cond_signal(&inventory_cond);

    // Unlock the mutex
    pthread_mutex_unlock(&inventory_mutex);

    return NULL;
}

int main() {
    // Create a thread pool to simulate multiple customers and suppliers
    pthread_t thread_pool[10];

    // Create a customer thread for each product
    for (int i = 0; i < num_products; i++) {
        int *product_id = malloc(sizeof(int));
        *product_id = products[i].id;
        pthread_create(&thread_pool[i], NULL, customer_thread, product_id);
    }

    // Create a supplier thread for each product
    for (int i = 0; i < num_products; i++) {
        int *product_id = malloc(sizeof(int));
        *product_id = products[i].id;
        pthread_create(&thread_pool[i + num_products], NULL, supplier_thread, product_id);
    }

    // Join all the threads
    for (int i = 0; i < 10; i++) {
        pthread_join(thread_pool[i], NULL);
    }

    // Destroy the mutex and condition variable
    pthread_mutex_destroy(&inventory_mutex);
    pthread_cond_destroy(&inventory_cond);

    return 0;
}