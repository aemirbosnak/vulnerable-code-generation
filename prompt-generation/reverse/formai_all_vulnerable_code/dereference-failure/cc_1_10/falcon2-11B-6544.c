//Falcon2-11B DATASET v1.0 Category: Stock market tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char name[50];
    char symbol[10];
    float price;
} Stock;

typedef struct {
    Stock *stocks;
    int size;
    int capacity;
} StockMarket;

StockMarket *createStockMarket() {
    StockMarket *market = malloc(sizeof(StockMarket));
    market->size = 0;
    market->capacity = 10;
    market->stocks = malloc(market->capacity * sizeof(Stock));
    return market;
}

void destroyStockMarket(StockMarket *market) {
    free(market->stocks);
    free(market);
}

void addStockToMarket(StockMarket *market, const char *name, const char *symbol, float price) {
    Stock *newStock = malloc(sizeof(Stock));
    strcpy(newStock->name, name);
    strcpy(newStock->symbol, symbol);
    newStock->price = price;
    if (market->size < market->capacity) {
        market->stocks[market->size] = *newStock;
        market->size++;
    } else {
        printf("Stock market is full. Cannot add new stock.\n");
    }
}

void removeStockFromMarket(StockMarket *market, const char *name, const char *symbol) {
    for (int i = 0; i < market->size; i++) {
        if (strcmp(market->stocks[i].name, name) == 0 && strcmp(market->stocks[i].symbol, symbol) == 0) {
            for (int j = i; j < market->size - 1; j++) {
                market->stocks[j] = market->stocks[j + 1];
            }
            market->size--;
            break;
        }
    }
}

float getStockPrice(StockMarket *market, const char *name, const char *symbol) {
    for (int i = 0; i < market->size; i++) {
        if (strcmp(market->stocks[i].name, name) == 0 && strcmp(market->stocks[i].symbol, symbol) == 0) {
            return market->stocks[i].price;
        }
    }
    return -1.0f;
}

float getStockPriceBySymbol(StockMarket *market, const char *symbol) {
    for (int i = 0; i < market->size; i++) {
        if (strcmp(market->stocks[i].symbol, symbol) == 0) {
            return market->stocks[i].price;
        }
    }
    return -1.0f;
}

char *getStockNameBySymbol(StockMarket *market, const char *symbol) {
    for (int i = 0; i < market->size; i++) {
        if (strcmp(market->stocks[i].symbol, symbol) == 0) {
            return strdup(market->stocks[i].name);
        }
    }
    return NULL;
}

char *getStockSymbolByName(StockMarket *market, const char *name) {
    for (int i = 0; i < market->size; i++) {
        if (strcmp(market->stocks[i].name, name) == 0) {
            return strdup(market->stocks[i].symbol);
        }
    }
    return NULL;
}

int getMarketSize(StockMarket *market) {
    return market->size;
}

float getTotalMarketValue(StockMarket *market) {
    float totalValue = 0.0f;
    for (int i = 0; i < market->size; i++) {
        totalValue += market->stocks[i].price;
    }
    return totalValue;
}

int main() {
    StockMarket *market = createStockMarket();
    printf("Welcome to the Stock Market Tracker!\n");

    addStockToMarket(market, "Apple", "AAPL", 150.0f);
    addStockToMarket(market, "Google", "GOOGL", 2200.0f);
    addStockToMarket(market, "Microsoft", "MSFT", 250.0f);

    printf("Stock Market:\n");
    for (int i = 0; i < market->size; i++) {
        printf("Stock name: %s\n", market->stocks[i].name);
        printf("Symbol: %s\n", market->stocks[i].symbol);
        printf("Price: %f\n", market->stocks[i].price);
    }

    removeStockFromMarket(market, "Apple", "AAPL");

    printf("Stock Market after removing Apple:\n");
    for (int i = 0; i < market->size; i++) {
        printf("Stock name: %s\n", market->stocks[i].name);
        printf("Symbol: %s\n", market->stocks[i].symbol);
        printf("Price: %f\n", market->stocks[i].price);
    }

    printf("Get price of Apple:\n");
    printf("Price: %f\n", getStockPrice(market, "Apple", "AAPL"));

    printf("Get price of Google:\n");
    printf("Price: %f\n", getStockPrice(market, "Google", "GOOGL"));

    printf("Get total market value:\n");
    printf("Total market value: %f\n", getTotalMarketValue(market));

    destroyStockMarket(market);
    return 0;
}