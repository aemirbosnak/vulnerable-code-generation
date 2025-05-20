//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_CUSTOMERS 10
#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} product_t;

typedef struct {
    int id;
    char name[50];
    char address[100];
    char phone[20];
} customer_t;

typedef struct {
    int customer_id;
    int product_id;
    int quantity;
} order_t;

product_t products[MAX_PRODUCTS];
customer_t customers[MAX_CUSTOMERS];
order_t orders[MAX_PRODUCTS * MAX_CUSTOMERS];

sem_t mutex;
sem_t customer_queue;
sem_t product_queue;
sem_t order_queue;

int num_customers = 0;
int num_products = 0;
int num_orders = 0;

void *customer_thread(void *arg) {
    while (1) {
        sem_wait(&customer_queue);
        sem_wait(&mutex);

        // Get the next customer from the queue
        int customer_id = num_customers++;

        // Find a random product to order
        int product_id = rand() % num_products;

        // Create an order
        order_t order = {
            .customer_id = customer_id,
            .product_id = product_id,
            .quantity = rand() % 10
        };

        // Add the order to the queue
        orders[num_orders++] = order;

        sem_post(&mutex);
        sem_post(&product_queue);
    }

    return NULL;
}

void *product_thread(void *arg) {
    while (1) {
        sem_wait(&product_queue);
        sem_wait(&mutex);

        // Get the next order from the queue
        order_t order = orders[num_orders--];

        // Find the product that was ordered
        product_t product = products[order.product_id];

        // Check if the product is in stock
        if (product.quantity < order.quantity) {
            // The product is out of stock, so we need to reject the order
            printf("Product %s is out of stock\n", product.name);
            continue;
        }

        // Deduct the quantity of the product from the inventory
        product.quantity -= order.quantity;

        // Calculate the total price of the order
        float total_price = product.price * order.quantity;

        // Print the order details
        printf("Customer %s ordered %d units of product %s for a total price of %f\n", customers[order.customer_id].name, order.quantity, product.name, total_price);

        sem_post(&mutex);
        sem_post(&order_queue);
    }

    return NULL;
}

int main() {
    // Initialize the semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&customer_queue, 0, 0);
    sem_init(&product_queue, 0, 0);
    sem_init(&order_queue, 0, 0);

    // Create the customer threads
    pthread_t customer_threads[MAX_CUSTOMERS];
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        pthread_create(&customer_threads[i], NULL, customer_thread, NULL);
    }

    // Create the product threads
    pthread_t product_threads[MAX_PRODUCTS];
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        pthread_create(&product_threads[i], NULL, product_thread, NULL);
    }

    // Join the customer threads
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        pthread_join(customer_threads[i], NULL);
    }

    // Join the product threads
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        pthread_join(product_threads[i], NULL);
    }

    return 0;
}