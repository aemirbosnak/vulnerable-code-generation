//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define BUF_SIZE 1024
#define MAX_STOCKS 100

typedef struct {
    char *symbol;
    float price;
    float change;
    float percent_change;
} stock_t;

stock_t *stocks[MAX_STOCKS];
int num_stocks = 0;

void add_stock(char *symbol, float price, float change, float percent_change) {
    if (num_stocks >= MAX_STOCKS) {
        printf("Error: maximum number of stocks reached\n");
        return;
    }

    stocks[num_stocks] = malloc(sizeof(stock_t));
    stocks[num_stocks]->symbol = strdup(symbol);
    stocks[num_stocks]->price = price;
    stocks[num_stocks]->change = change;
    stocks[num_stocks]->percent_change = percent_change;
    num_stocks++;
}

void print_stocks() {
    printf("--------------------------------------------------------------------------------\n");
    printf("| Symbol | Price | Change | Percent Change |\n");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("| %s | %.2f | %.2f | %.2f%% |\n", stocks[i]->symbol, stocks[i]->price, stocks[i]->change, stocks[i]->percent_change);
    }
    printf("--------------------------------------------------------------------------------\n");
}

void free_stocks() {
    for (int i = 0; i < num_stocks; i++) {
        free(stocks[i]->symbol);
        free(stocks[i]);
    }
    num_stocks = 0;
}

int main() {
    // initialize random number generator
    srand(time(NULL));

    // add some stocks to the list
    add_stock("AAPL", 170.00, 1.00, 0.59);
    add_stock("GOOG", 900.00, 2.00, 0.22);
    add_stock("AMZN", 1100.00, 3.00, 0.27);
    add_stock("TSLA", 200.00, 4.00, 2.00);
    add_stock("NVDA", 150.00, 5.00, 3.33);

    // print the initial list of stocks
    print_stocks();

    // simulate stock market activity
    for (int i = 0; i < 10; i++) {
        // update stock prices
        for (int j = 0; j < num_stocks; j++) {
            // generate a random change in price
            float change = ((float)rand() / (float)RAND_MAX) * 10.0 - 5.0;

            // update the stock price
            stocks[j]->price += change;

            // update the stock change
            stocks[j]->change = stocks[j]->price - stocks[j]->price;

            // update the stock percent change
            stocks[j]->percent_change = stocks[j]->change / stocks[j]->price * 100.0;
        }

        // print the updated list of stocks
        print_stocks();

        // sleep for a bit
        sleep(1);
    }

    // free the allocated memory
    free_stocks();

    return 0;
}