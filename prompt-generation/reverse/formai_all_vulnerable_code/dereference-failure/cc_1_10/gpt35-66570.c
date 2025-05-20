//FormAI DATASET v1.0 Category: Stock market tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// Structure to store stock details
typedef struct {
    char symbol[10];
    float price;
} Stock;

// Function to return a random float for stock price between 1 and 100
float getRandPrice() {
    return ((float)rand()/(float)(RAND_MAX)) * 100.0 + 1.0;
}

// Function to update stock price
void updateStockPrice(Stock *stock) {
    float newPrice = getRandPrice();
    printf("Updating stock price for %s: %.2f -> %.2f\n", stock->symbol, stock->price, newPrice);
    stock->price = newPrice;
}

// Function to print the stock details
void printStockDetails(Stock stock) {
    printf("%s - %.2f\n", stock.symbol, stock.price);
}

int main(int argc, char *argv[]) {
    srand(time(NULL)); // Set the seed for random number generation
    int numStocks = argc-1; // Number of stocks to track
    Stock *stocks = malloc(numStocks * sizeof(Stock)); // Allocate memory for stocks
    int i;

    // Read stock symbols from command line arguments
    for(i=0; i<numStocks; i++) {
        strcpy(stocks[i].symbol, argv[i+1]);
        stocks[i].price = getRandPrice(); // Set initial price for each stock
        printStockDetails(stocks[i]);
    }

    while(1) {
        printf("\n"); // add empty line for clarity
        // Update stock prices every 5 seconds
        for(i=0; i<numStocks; i++) {
            updateStockPrice(&stocks[i]);
            printStockDetails(stocks[i]);
        }
        sleep(5);
    }

    free(stocks); // Free memory used for stocks
    return 0;
}