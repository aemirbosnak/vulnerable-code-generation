//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[10];
    float price;
} Stock;

void print_stock(Stock stock) {
    printf("Name: %s\nSymbol: %s\nPrice: $%.2f\n", stock.name, stock.symbol, stock.price);
}

void print_stocks(Stock stocks[], int num_stocks) {
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    char input[MAX_NAME_LEN + MAX_PRICE_LEN + 3]; // +3 for symbol, space, and null terminator
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        if (num_stocks >= MAX_STOCKS) {
            printf("Error: Too many stocks.\n");
            break;
        }

        char *name_start = strtok(input, " ");
        strncpy(stocks[num_stocks].name, name_start, MAX_NAME_LEN - 1);
        stocks[num_stocks].name[MAX_NAME_LEN - 1] = '\0';

        char *symbol_start = strtok(NULL, " ");
        strncpy(stocks[num_stocks].symbol, symbol_start, sizeof(stocks[num_stocks].symbol) - 1);
        stocks[num_stocks].symbol[sizeof(stocks[num_stocks].symbol) - 1] = '\0';

        char *price_start = strtok(NULL, " ");
        stocks[num_stocks].price = atof(price_start);

        num_stocks++;
    }

    print_stocks(stocks, num_stocks);

    return 0;
}