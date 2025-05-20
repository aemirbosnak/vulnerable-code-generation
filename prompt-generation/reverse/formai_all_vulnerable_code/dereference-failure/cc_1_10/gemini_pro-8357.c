//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Struct to store stock information
typedef struct stock {
    char *name;
    char *ticker;
    double price;
    double change;
} Stock;

// Global variables
Stock *stocks;
int num_stocks;

// Mutex to protect access to global variables
pthread_mutex_t mutex;

// Thread function to update stock prices
void *update_stock_prices(void *arg) {
    // Get the stock index
    int index = (int)arg;

    // Update the stock price
    stocks[index].price += (rand() % 100) / 100.0;
    stocks[index].change += (rand() % 100) / 100.0;

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    return NULL;
}

// Main function
int main() {
    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create the stock array
    stocks = malloc(sizeof(Stock) * 10);
    num_stocks = 10;

    // Initialize the stock array
    for (int i = 0; i < num_stocks; i++) {
        stocks[i].name = malloc(sizeof(char) * 32);
        stocks[i].ticker = malloc(sizeof(char) * 8);
        stocks[i].price = 100.0;
        stocks[i].change = 0.0;
    }

    // Create the threads
    pthread_t threads[num_stocks];
    for (int i = 0; i < num_stocks; i++) {
        pthread_create(&threads[i], NULL, update_stock_prices, (void *)i);
    }

    // Join the threads
    for (int i = 0; i < num_stocks; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the stock information
    for (int i = 0; i < num_stocks; i++) {
        printf("%s (%s): $%.2f (%.2f%%)\n", stocks[i].name, stocks[i].ticker, stocks[i].price, stocks[i].change);
    }

    // Free the stock array
    for (int i = 0; i < num_stocks; i++) {
        free(stocks[i].name);
        free(stocks[i].ticker);
    }
    free(stocks);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}