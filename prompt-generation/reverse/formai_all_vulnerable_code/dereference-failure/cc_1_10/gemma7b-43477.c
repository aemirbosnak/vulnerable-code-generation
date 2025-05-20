//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Stock Market Tracker structure
typedef struct StockMarketTracker {
    char companyName[50];
    double currentPrice;
    double previousPrice;
    double changeInPrice;
    int numShares;
} StockMarketTracker;

// Function to calculate the change in price
double calculateChangeInPrice(double currentPrice, double previousPrice) {
    double changeInPrice = (currentPrice - previousPrice) / previousPrice * 100;
    return changeInPrice;
}

// Function to print the stock market tracker information
void printStockMarketTracker(StockMarketTracker* tracker) {
    printf("Company Name: %s\n", tracker->companyName);
    printf("Current Price: %.2lf\n", tracker->currentPrice);
    printf("Previous Price: %.2lf\n", tracker->previousPrice);
    printf("Change in Price: %.2lf%%\n", tracker->changeInPrice);
    printf("Number of Shares: %d\n", tracker->numShares);
    printf("\n");
}

int main() {
    // Create a stock market tracker
    StockMarketTracker* tracker = malloc(sizeof(StockMarketTracker));

    // Initialize the stock market tracker
    tracker->companyName[0] = 'A';
    tracker->companyName[1] = 'B';
    tracker->currentPrice = 100.00;
    tracker->previousPrice = 95.00;
    tracker->changeInPrice = 5.00;
    tracker->numShares = 1000;

    // Print the stock market tracker information
    printStockMarketTracker(tracker);

    // Calculate the change in price
    double changeInPrice = calculateChangeInPrice(tracker->currentPrice, tracker->previousPrice);

    // Print the change in price
    printf("Change in Price: %.2lf%%\n", changeInPrice);

    // Free the memory allocated for the stock market tracker
    free(tracker);

    return 0;
}