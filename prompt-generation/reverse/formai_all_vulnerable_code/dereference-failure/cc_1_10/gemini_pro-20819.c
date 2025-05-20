//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    char *symbol;
    double price;
} Stock;

pthread_mutex_t lock;
Stock *stocks;
int num_stocks;

void *update_stock_prices(void *args) {
    int i;
    while (1) {
        pthread_mutex_lock(&lock);
        for (i = 0; i < num_stocks; i++) {
            stocks[i].price = (rand() % 100) / 100.0;
        }
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

void *print_stock_prices(void *args) {
    int i;
    while (1) {
        pthread_mutex_lock(&lock);
        for (i = 0; i < num_stocks; i++) {
            printf("%s: %.2f\n", stocks[i].symbol, stocks[i].price);
        }
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

int main() {
    int i;
    pthread_t update_thread, print_thread;

    stocks = malloc(sizeof(Stock) * 5);
    stocks[0].symbol = "AAPL";
    stocks[1].symbol = "GOOG";
    stocks[2].symbol = "MSFT";
    stocks[3].symbol = "AMZN";
    stocks[4].symbol = "TSLA";

    num_stocks = 5;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&update_thread, NULL, update_stock_prices, NULL);
    pthread_create(&print_thread, NULL, print_stock_prices, NULL);

    pthread_join(update_thread, NULL);
    pthread_join(print_thread, NULL);

    pthread_mutex_destroy(&lock);

    free(stocks);
    return 0;
}