//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define NUM_STOCKS 5

typedef struct stock {
    char *name;
    double price;
} stock_t;

typedef struct stock_update {
    stock_t *stock;
    double new_price;
} stock_update_t;

pthread_mutex_t mutex;
pthread_cond_t cond;
stock_t *stocks[NUM_STOCKS];
double stock_prices[NUM_STOCKS];

void *stock_update_thread(void *arg) {
    stock_update_t *update = (stock_update_t *)arg;

    pthread_mutex_lock(&mutex);
    update->stock->price = update->new_price;
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&mutex);

    free(update);
    return NULL;
}

void create_stock_update_thread(stock_t *stock, double new_price) {
    stock_update_t *update = malloc(sizeof(stock_update_t));
    update->stock = stock;
    update->new_price = new_price;

    pthread_t thread;
    pthread_create(&thread, NULL, stock_update_thread, update);
    pthread_detach(thread);
}

void init_stocks() {
    stocks[0] = malloc(sizeof(stock_t));
    stocks[0]->name = "Apple";
    stocks[0]->price = 100.0;

    stocks[1] = malloc(sizeof(stock_t));
    stocks[1]->name = "Google";
    stocks[1]->price = 120.0;

    stocks[2] = malloc(sizeof(stock_t));
    stocks[2]->name = "Microsoft";
    stocks[2]->price = 140.0;

    stocks[3] = malloc(sizeof(stock_t));
    stocks[3]->name = "Amazon";
    stocks[3]->price = 160.0;

    stocks[4] = malloc(sizeof(stock_t));
    stocks[4]->name = "Tesla";
    stocks[4]->price = 180.0;
}

void print_stocks() {
    for (int i = 0; i < NUM_STOCKS; i++) {
        printf("%s: %.2f\n", stocks[i]->name, stocks[i]->price);
    }
}

int main() {
    init_stocks();

    // Create a thread to update the price of Apple stock
    create_stock_update_thread(stocks[0], 101.0);

    // Wait for the price update to complete
    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&cond, &mutex);
    pthread_mutex_unlock(&mutex);

    // Print the updated stock prices
    print_stocks();

    return 0;
}