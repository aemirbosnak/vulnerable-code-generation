//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct {
    int id;
    char *name;
    int quantity;
    float price;
} Product;

Product *products;
int num_products;

sem_t mutex;
sem_t cond;

void *producer(void *args) {
    while (true) {
        // Produce a new product
        Product product;
        product.id = rand() % 1000;
        product.name = "Product";
        product.quantity = rand() % 100;
        product.price = rand() % 100;

        // Acquire the lock
        sem_wait(&mutex);

        // Add the new product to the inventory
        products = realloc(products, sizeof(Product) * (num_products + 1));
        products[num_products++] = product;

        // Signal that the producer has produced a new product
        sem_post(&cond);

        // Release the lock
        sem_post(&mutex);
    }
}

void *consumer(void *args) {
    while (true) {
        // Acquire the lock
        sem_wait(&mutex);

        // Wait until a new product is available
        sem_wait(&cond);

        // Consume the new product
        printf("Consumed product %d\n", products[num_products - 1].id);

        // Remove the consumed product from the inventory
        num_products--;
        products = realloc(products, sizeof(Product) * num_products);

        // Release the lock
        sem_post(&mutex);
    }
}

int main(void) {
    // Initialize the semaphore
    sem_init(&mutex, 0, 1);
    sem_init(&cond, 0, 0);

    // Create the producer and consumer threads
    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Join the producer and consumer threads
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Destroy the semaphore
    sem_destroy(&mutex);
    sem_destroy(&cond);

    return 0;
}