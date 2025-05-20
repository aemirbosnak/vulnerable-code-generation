//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCK_NUM 10

typedef struct Stock {
    char name[20];
    double current_price;
    double previous_price;
    double change_percentage;
} Stock;

Stock stocks[MAX_STOCK_NUM];

void update_stock_prices() {
    for (int i = 0; i < MAX_STOCK_NUM; i++) {
        stocks[i].previous_price = stocks[i].current_price;
        stocks[i].current_price = rand() % 1000;
        stocks[i].change_percentage = (stocks[i].current_price - stocks[i].previous_price) / stocks[i].previous_price * 100;
    }
}

void print_stock_summary() {
    printf("--------------------------------------------\n");
    printf("Stock Market Summary\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < MAX_STOCK_NUM; i++) {
        printf("%s: $\%.2f, Change: %.2f%% \n", stocks[i].name, stocks[i].current_price, stocks[i].change_percentage);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    // Initialize the stock data
    for (int i = 0; i < MAX_STOCK_NUM; i++) {
        strcpy(stocks[i].name, "Stock #" + i);
        stocks[i].current_price = rand() % 1000;
        stocks[i].previous_price = stocks[i].current_price;
        stocks[i].change_percentage = 0;
    }

    // Update the stock prices
    update_stock_prices();

    // Print the stock summary
    print_stock_summary();

    return 0;
}