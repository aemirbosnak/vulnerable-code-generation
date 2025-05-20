//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
    char *symbol;
    double price;
} stock_t;

typedef struct {
    stock_t *stocks;
    int num_stocks;
} portfolio_t;

portfolio_t *portfolio;

void *update_stock_prices(void *arg) {
    while (1) {
        for (int i = 0; i < portfolio->num_stocks; i++) {
            // Simulate getting the stock price from a remote source
            double new_price = portfolio->stocks[i].price * (1.0 + (rand() % 100 - 50) / 100.0);
            portfolio->stocks[i].price = new_price;
        }
        sleep(1);
    }
    return NULL;
}

void print_portfolio() {
    printf("Portfolio:\n");
    for (int i = 0; i < portfolio->num_stocks; i++) {
        printf("%s: $%.2f\n", portfolio->stocks[i].symbol, portfolio->stocks[i].price);
    }
    printf("\n");
}

int main() {
    // Initialize the portfolio
    portfolio = malloc(sizeof(portfolio_t));
    portfolio->stocks = malloc(sizeof(stock_t) * 5);
    portfolio->num_stocks = 5;
    portfolio->stocks[0] = (stock_t) {"AAPL", 120.0};
    portfolio->stocks[1] = (stock_t) {"GOOG", 100.0};
    portfolio->stocks[2] = (stock_t) {"AMZN", 150.0};
    portfolio->stocks[3] = (stock_t) {"TSLA", 200.0};
    portfolio->stocks[4] = (stock_t) {"MSFT", 180.0};

    // Create a thread to update the stock prices
    pthread_t thread;
    pthread_create(&thread, NULL, update_stock_prices, NULL);

    // Continuously print the portfolio
    while (1) {
        print_portfolio();
        sleep(5);
    }

    // Join the thread
    pthread_join(thread, NULL);

    // Free the memory
    free(portfolio->stocks);
    free(portfolio);

    return 0;
}