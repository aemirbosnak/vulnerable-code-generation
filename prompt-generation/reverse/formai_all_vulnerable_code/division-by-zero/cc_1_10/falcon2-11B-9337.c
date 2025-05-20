//Falcon2-11B DATASET v1.0 Category: Stock market tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get the current stock price
float getStockPrice(int symbol) {
    // Simulate fetching stock price from an API
    if (symbol == 1) {
        return 100.5;
    } else if (symbol == 2) {
        return 120.3;
    } else if (symbol == 3) {
        return 90.7;
    } else {
        printf("Invalid symbol\n");
        return -1;
    }
}

// Function to track the stock price over time
void trackStockPrice(int symbol, int numDays, int updateInterval) {
    printf("Tracking stock price for symbol %d\n", symbol);

    // Simulate tracking the stock price over time
    for (int i = 0; i < numDays; i++) {
        printf("Day %d: Stock price is %.2f\n", i + 1, getStockPrice(symbol));

        // Update the stock price every updateInterval days
        if (i % updateInterval == 0) {
            printf("Updating stock price...\n");
            getStockPrice(symbol);
        }
    }
}

// Function to handle user input
void getUserInput() {
    int symbol;
    int numDays;
    int updateInterval;

    printf("Enter symbol: ");
    scanf("%d", &symbol);

    printf("Enter number of days to track: ");
    scanf("%d", &numDays);

    printf("Enter update interval (in days): ");
    scanf("%d", &updateInterval);

    printf("Enter 1 to start tracking, 2 to exit:\n");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        trackStockPrice(symbol, numDays, updateInterval);
    } else if (choice == 2) {
        printf("Exiting...\n");
    } else {
        printf("Invalid choice\n");
    }
}

int main() {
    srand(time(NULL));
    getUserInput();
    return 0;
}