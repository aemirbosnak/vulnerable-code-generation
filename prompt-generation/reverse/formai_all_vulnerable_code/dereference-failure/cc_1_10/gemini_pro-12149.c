//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100

typedef struct {
    char *name;
    double price;
    double change;
} Stock;

Stock *stocks[MAX_STOCKS];
int num_stocks = 0;

void add_stock(char *name, double price, double change) {
    if (num_stocks >= MAX_STOCKS) {
        printf("Error: too many stocks\n");
        return;
    }

    stocks[num_stocks] = malloc(sizeof(Stock));
    stocks[num_stocks]->name = strdup(name);
    stocks[num_stocks]->price = price;
    stocks[num_stocks]->change = change;

    num_stocks++;
}

void print_stocks() {
    for (int i = 0; i < num_stocks; i++) {
        printf("%s: $%.2f (%.2f%%)\n", stocks[i]->name, stocks[i]->price, stocks[i]->change);
    }
}

void free_stocks() {
    for (int i = 0; i < num_stocks; i++) {
        free(stocks[i]);
    }
}

int main() {
    add_stock("AAPL", 123.45, 1.23);
    add_stock("GOOG", 987.65, -2.34);
    add_stock("MSFT", 234.56, 3.45);

    print_stocks();

    free_stocks();

    return 0;
}