//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100

typedef struct {
    char *name;
    double price;
    int volume;
} Stock;

Stock **stocks;
int num_stocks;

void add_stock(char *name, double price, int volume) {
    if (num_stocks == MAX_STOCKS) {
        printf("Error: Maximum number of stocks reached.\n");
        return;
    }

    stocks[num_stocks] = malloc(sizeof(Stock));
    stocks[num_stocks]->name = strdup(name);
    stocks[num_stocks]->price = price;
    stocks[num_stocks]->volume = volume;
    num_stocks++;
}

void print_stocks() {
    for (int i = 0; i < num_stocks; i++) {
        printf("%s: $%.2f (%d)\n", stocks[i]->name, stocks[i]->price, stocks[i]->volume);
    }
}

void free_stocks() {
    for (int i = 0; i < num_stocks; i++) {
        free(stocks[i]->name);
        free(stocks[i]);
    }
    free(stocks);
}

int main() {
    stocks = malloc(sizeof(Stock *) * MAX_STOCKS);
    num_stocks = 0;

    add_stock("AAPL", 120.00, 10000);
    add_stock("GOOG", 800.00, 5000);
    add_stock("MSFT", 200.00, 15000);
    add_stock("AMZN", 1500.00, 2000);
    add_stock("TSLA", 700.00, 10000);

    print_stocks();

    free_stocks();

    return 0;
}