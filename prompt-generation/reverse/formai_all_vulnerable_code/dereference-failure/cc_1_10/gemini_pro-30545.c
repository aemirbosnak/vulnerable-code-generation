//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STOCKS 100
#define MAX_DAYS 252

struct stock {
    char *name;
    double *prices;
    int num_days;
};

struct stock_market {
    struct stock *stocks;
    int num_stocks;
};

struct stock_market *create_stock_market(int num_stocks) {
    struct stock_market *market = malloc(sizeof(struct stock_market));
    market->stocks = malloc(sizeof(struct stock) * num_stocks);
    market->num_stocks = num_stocks;
    return market;
}

void add_stock(struct stock_market *market, char *name, double *prices, int num_days) {
    struct stock *stock = &market->stocks[market->num_stocks++];
    stock->name = name;
    stock->prices = prices;
    stock->num_days = num_days;
}

void print_stock_market(struct stock_market *market) {
    for (int i = 0; i < market->num_stocks; i++) {
        struct stock *stock = &market->stocks[i];
        printf("%s\n", stock->name);
        for (int j = 0; j < stock->num_days; j++) {
            printf("%f\n", stock->prices[j]);
        }
    }
}

void free_stock_market(struct stock_market *market) {
    for (int i = 0; i < market->num_stocks; i++) {
        struct stock *stock = &market->stocks[i];
        free(stock->name);
        free(stock->prices);
    }
    free(market->stocks);
    free(market);
}

int main() {
    struct stock_market *market = create_stock_market(3);
    add_stock(market, "AAPL", (double[]){100.0, 101.0, 102.0, 103.0}, 4);
    add_stock(market, "GOOG", (double[]){500.0, 501.0, 502.0, 503.0}, 4);
    add_stock(market, "MSFT", (double[]){200.0, 201.0, 202.0, 203.0}, 4);
    print_stock_market(market);
    free_stock_market(market);
    return 0;
}