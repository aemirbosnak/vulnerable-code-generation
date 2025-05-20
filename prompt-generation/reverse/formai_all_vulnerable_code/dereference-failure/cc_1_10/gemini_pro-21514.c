//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STOCK_NAME_MAX_SIZE 32
#define STOCK_PRICE_MAX_SIZE 32
#define STOCKS_LIST_MAX_SIZE 10
#define HISTORIC_PRICES_MAX_SIZE 10

typedef struct {
    char name[STOCK_NAME_MAX_SIZE];
    double price;
} Stock;

typedef struct {
    Stock stocks[STOCKS_LIST_MAX_SIZE];
    int num_stocks;
} StocksList;

typedef struct {
    Stock stock;
    time_t timestamp;
    double price;
} HistoricPrice;

typedef struct {
    HistoricPrice historic_prices[HISTORIC_PRICES_MAX_SIZE];
    int num_historic_prices;
} HistoricPricesList;

StocksList* create_stocks_list() {
    StocksList* stocks_list = malloc(sizeof(StocksList));
    stocks_list->num_stocks = 0;
    return stocks_list;
}

void free_stocks_list(StocksList* stocks_list) {
    if (stocks_list != NULL) {
        free(stocks_list);
    }
}

void add_stock_to_list(StocksList* stocks_list, Stock stock) {
    if (stocks_list != NULL && stocks_list->num_stocks < STOCKS_LIST_MAX_SIZE) {
        stocks_list->stocks[stocks_list->num_stocks] = stock;
        stocks_list->num_stocks++;
    }
}

HistoricPricesList* create_historic_prices_list() {
    HistoricPricesList* historic_prices_list = malloc(sizeof(HistoricPricesList));
    historic_prices_list->num_historic_prices = 0;
    return historic_prices_list;
}

void free_historic_prices_list(HistoricPricesList* historic_prices_list) {
    if (historic_prices_list != NULL) {
        free(historic_prices_list);
    }
}

void add_historic_price_to_list(HistoricPricesList* historic_prices_list, HistoricPrice historic_price) {
    if (historic_prices_list != NULL && historic_prices_list->num_historic_prices < HISTORIC_PRICES_MAX_SIZE) {
        historic_prices_list->historic_prices[historic_prices_list->num_historic_prices] = historic_price;
        historic_prices_list->num_historic_prices++;
    }
}

int main() {
    StocksList* stocks_list = create_stocks_list();
    add_stock_to_list(stocks_list, (Stock) {"Apple", 100.0});
    add_stock_to_list(stocks_list, (Stock) {"Amazon", 150.0});
    add_stock_to_list(stocks_list, (Stock) {"Tesla", 200.0});

    HistoricPricesList* historic_prices_list = create_historic_prices_list();
    add_historic_price_to_list(historic_prices_list, (HistoricPrice) {stocks_list->stocks[0], time(NULL), 99.0});
    add_historic_price_to_list(historic_prices_list, (HistoricPrice) {stocks_list->stocks[0], time(NULL), 101.0});
    add_historic_price_to_list(historic_prices_list, (HistoricPrice) {stocks_list->stocks[0], time(NULL), 100.0});

    // Print the stocks list
    printf("Stocks list:\n");
    for (int i = 0; i < stocks_list->num_stocks; i++) {
        printf("- %s: $%.2f\n", stocks_list->stocks[i].name, stocks_list->stocks[i].price);
    }

    // Print the historic prices list
    printf("\nHistoric prices list:\n");
    for (int i = 0; i < historic_prices_list->num_historic_prices; i++) {
        printf("- %s: $%.2f at %s\n", historic_prices_list->historic_prices[i].stock.name, historic_prices_list->historic_prices[i].price, ctime(&historic_prices_list->historic_prices[i].timestamp));
    }

    free_stocks_list(stocks_list);
    free_historic_prices_list(historic_prices_list);

    return 0;
}