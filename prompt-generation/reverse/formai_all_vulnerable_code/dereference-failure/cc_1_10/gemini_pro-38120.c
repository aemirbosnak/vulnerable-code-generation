//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stock {
    char *name;
    float price;
    float change;
};

struct StockMarket {
    struct Stock *stocks;
    int num_stocks;
};

struct StockMarket *stock_market_init(int num_stocks) {
    struct StockMarket *market = malloc(sizeof(struct StockMarket));
    market->stocks = malloc(sizeof(struct Stock) * num_stocks);
    market->num_stocks = num_stocks;
    return market;
}

void stock_market_free(struct StockMarket *market) {
    for (int i = 0; i < market->num_stocks; i++) {
        free(market->stocks[i].name);
    }
    free(market->stocks);
    free(market);
}

void stock_market_add_stock(struct StockMarket *market, char *name, float price, float change) {
    struct Stock *stock = &market->stocks[market->num_stocks];
    stock->name = strdup(name);
    stock->price = price;
    stock->change = change;
    market->num_stocks++;
}

void stock_market_print(struct StockMarket *market) {
    printf("Stock Market:\n");
    printf("====================\n");
    for (int i = 0; i < market->num_stocks; i++) {
        struct Stock *stock = &market->stocks[i];
        printf("%s: $%.2f (%+.2f%%)\n", stock->name, stock->price, stock->change);
    }
}

int main() {
    // Initialize the stock market
    struct StockMarket *market = stock_market_init(3);

    // Add some stocks to the market
    stock_market_add_stock(market, "Apple", 123.45, 1.23);
    stock_market_add_stock(market, "Microsoft", 145.67, -2.34);
    stock_market_add_stock(market, "Amazon", 167.89, 3.45);

    // Print the stock market
    stock_market_print(market);

    // Free the stock market
    stock_market_free(market);

    return 0;
}