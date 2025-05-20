//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    float price;
    int volume;
} Stock;

int main() {
    int numStocks = 5;
    Stock *stocks = malloc(numStocks * sizeof(Stock));

    for (int i = 0; i < numStocks; i++) {
        stocks[i].name = malloc(20 * sizeof(char));
        stocks[i].price = 0;
        stocks[i].volume = 0;
    }

    // Initialize stocks
    stocks[0].name = "AAPL";
    stocks[0].price = 150.2;
    stocks[0].volume = 500000;

    stocks[1].name = "GOOG";
    stocks[1].price = 1000.5;
    stocks[1].volume = 200000;

    stocks[2].name = "MSFT";
    stocks[2].price = 200.1;
    stocks[2].volume = 300000;

    stocks[3].name = "AMZN";
    stocks[3].price = 3000.2;
    stocks[3].volume = 400000;

    stocks[4].name = "FB";
    stocks[4].price = 250.2;
    stocks[4].volume = 500000;

    // Print initial stock data
    printf("Initial Stock Data:\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%s - $%.2f - %d shares\n", stocks[i].name, stocks[i].price, stocks[i].volume);
    }

    // Simulate stock market activity
    for (int i = 0; i < 10; i++) {
        float change = (float)rand() / RAND_MAX;
        int index = rand() % numStocks;

        if (change > 0) {
            stocks[index].price += change * stocks[index].price;
        } else {
            stocks[index].price -= change * stocks[index].price;
        }

        int volumeChange = rand() % 1000 - 500;
        stocks[index].volume += volumeChange;

        // Print updated stock data
        printf("\nUpdated Stock Data (%d):\n", i+1);
        for (int j = 0; j < numStocks; j++) {
            printf("%s - $%.2f - %d shares\n", stocks[j].name, stocks[j].price, stocks[j].volume);
        }
    }

    return 0;
}