//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    float price;
    int volume;
} stock_t;

stock_t *create_stock(char *name, float price, int volume) {
    stock_t *stock = malloc(sizeof(stock_t));
    stock->name = malloc(strlen(name) + 1);
    strcpy(stock->name, name);
    stock->price = price;
    stock->volume = volume;
    return stock;
}

void destroy_stock(stock_t *stock) {
    free(stock->name);
    free(stock);
}

int main() {
    // Create a stock market tracker.
    stock_t *stocks[10];
    stocks[0] = create_stock("Apple", 100.00, 1000);
    stocks[1] = create_stock("Google", 800.00, 500);
    stocks[2] = create_stock("Microsoft", 500.00, 2000);
    stocks[3] = create_stock("Amazon", 1200.00, 1500);
    stocks[4] = create_stock("Tesla", 700.00, 1800);
    stocks[5] = create_stock("NVIDIA", 400.00, 1300);
    stocks[6] = create_stock("AMD", 150.00, 1400);
    stocks[7] = create_stock("Intel", 200.00, 1600);
    stocks[8] = create_stock("Qualcomm", 130.00, 1700);
    stocks[9] = create_stock("Broadcom", 300.00, 1900);

    // Print the stock market tracker.
    printf("Stock Market Tracker\n");
    printf("====================\n");
    printf("%-15s %-10s %-10s\n", "Name", "Price", "Volume");
    for (int i = 0; i < 10; i++) {
        printf("%-15s $%-9.2f %d\n", stocks[i]->name, stocks[i]->price, stocks[i]->volume);
    }

    // Destroy the stock market tracker.
    for (int i = 0; i < 10; i++) {
        destroy_stock(stocks[i]);
    }

    return 0;
}