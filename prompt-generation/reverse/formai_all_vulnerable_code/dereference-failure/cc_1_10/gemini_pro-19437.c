//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STOCKS 10
#define NUM_DAYS 250

typedef struct {
    char* name;
    double price;
    double change;
} Stock;

Stock* createStock(char* name, double price, double change) {
    Stock* stock = malloc(sizeof(Stock));
    stock->name = name;
    stock->price = price;
    stock->change = change;
    return stock;
}

void freeStock(Stock* stock) {
    free(stock->name);
    free(stock);
}

int compareStocks(const void* a, const void* b) {
    Stock* stockA = (Stock*)a;
    Stock* stockB = (Stock*)b;
    return strcmp(stockA->name, stockB->name);
}

int main() {
    srand(time(NULL));

    // Create an array of stocks
    Stock* stocks[NUM_STOCKS];
    stocks[0] = createStock("Apple", 100.0, 1.0);
    stocks[1] = createStock("Google", 85.0, 0.5);
    stocks[2] = createStock("Microsoft", 60.0, 0.2);
    stocks[3] = createStock("Amazon", 120.0, 1.5);
    stocks[4] = createStock("Tesla", 80.0, 1.0);
    stocks[5] = createStock("Facebook", 75.0, 0.8);
    stocks[6] = createStock("Nvidia", 65.0, 1.2);
    stocks[7] = createStock("Intel", 50.0, 0.6);
    stocks[8] = createStock("AMD", 40.0, 1.0);
    stocks[9] = createStock("Qualcomm", 35.0, 0.8);

    // Sort the stocks by name
    qsort(stocks, NUM_STOCKS, sizeof(Stock*), compareStocks);

    // Print the stock prices
    printf("Current Stock Prices:\n");
    for (int i = 0; i < NUM_STOCKS; i++) {
        printf("%s: $%.2f\n", stocks[i]->name, stocks[i]->price);
    }

    // Simulate stock market fluctuations
    for (int i = 0; i < NUM_DAYS; i++) {
        for (int j = 0; j < NUM_STOCKS; j++) {
            // Randomly generate a change in price
            double change = ((double)rand() / RAND_MAX) * 0.1;
            if (rand() % 2 == 0) {
                stocks[j]->price += change;
            } else {
                stocks[j]->price -= change;
            }
        }
    }

    // Print the updated stock prices
    printf("\nUpdated Stock Prices:\n");
    for (int i = 0; i < NUM_STOCKS; i++) {
        printf("%s: $%.2f (%.2f%%)\n", stocks[i]->name, stocks[i]->price, stocks[i]->change);
    }

    // Free the stocks
    for (int i = 0; i < NUM_STOCKS; i++) {
        freeStock(stocks[i]);
    }

    return 0;
}