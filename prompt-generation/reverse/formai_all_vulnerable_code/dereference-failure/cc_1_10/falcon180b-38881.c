//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10
#define MAX_VOLUME_LEN 10
#define MAX_DATE_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char price[MAX_PRICE_LEN];
    char volume[MAX_VOLUME_LEN];
    char date[MAX_DATE_LEN];
} stock_t;

stock_t stocks[MAX_STOCKS];
int num_stocks = 0;

void add_stock(char* name, char* symbol, char* price, char* volume, char* date) {
    if (num_stocks >= MAX_STOCKS) {
        printf("Error: Maximum number of stocks reached.\n");
        return;
    }

    strcpy(stocks[num_stocks].name, name);
    strcpy(stocks[num_stocks].symbol, symbol);
    strcpy(stocks[num_stocks].price, price);
    strcpy(stocks[num_stocks].volume, volume);
    strcpy(stocks[num_stocks].date, date);

    num_stocks++;
}

void print_stocks() {
    printf("Name\tSymbol\tPrice\tVolume\tDate\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%-20s %-10s %-10s %-10s %-20s\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].volume, stocks[i].date);
    }
}

int main() {
    time_t now = time(NULL);
    struct tm* tm = localtime(&now);
    char date[MAX_DATE_LEN];
    strftime(date, MAX_DATE_LEN, "%Y-%m-%d", tm);

    add_stock("Apple Inc.", "AAPL", "145.52", "20,000,000", date);
    add_stock("Microsoft Corporation", "MSFT", "254.45", "15,000,000", date);
    add_stock("Amazon.com Inc.", "AMZN", "3,331.36", "5,000,000", date);

    print_stocks();

    return 0;
}