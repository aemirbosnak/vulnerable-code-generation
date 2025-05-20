//FormAI DATASET v1.0 Category: Stock market tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random number between 50 and 500 for price fluctuation
int generateRandomPrice() {
    int price = (rand() % 451) + 50;
    return price;
}

// Function to generate a random time between 9:30am and 4:00pm for stock updates
void generateRandomTime(char *timeStr) {
    // Generate a random hour between 9 and 15 (9am to 3pm)
    int hour = (rand() % 7) + 9;
    // Generate a random minute between 0 and 59
    int minute = rand() % 60;
    // Convert hour and minute to string format
    char hourStr[3], minuteStr[3];
    sprintf(hourStr, "%02d", hour);
    sprintf(minuteStr, "%02d", minute);
    // Concatenate hour and minute strings with a colon separator
    strcpy(timeStr, hourStr);
    strcat(timeStr, ":");
    strcat(timeStr, minuteStr);
}

int main() {
    // Define an array of stock symbols to track
    char *stockSymbols[] = {"AAPL", "GOOGL", "AMZN", "FB", "TSLA"};
    int numStocks = sizeof(stockSymbols) / sizeof(stockSymbols[0]);
    // Initialize an array of current prices and set them randomly between 100 and 500
    int currentPrices[numStocks];
    for (int i = 0; i < numStocks; i++) {
        currentPrices[i] = generateRandomPrice();
    }
    // Initialize an array of time strings for stock updates
    char updateTimes[numStocks][6];
    for (int i = 0; i < numStocks; i++) {
        generateRandomTime(updateTimes[i]);
    }
    // Loop to simulate stock updates every minute for 6.5 hours (9:30am to 4:00pm)
    int totalTime = 6 * 60 + 30;
    for (int i = 0; i < totalTime; i++) {
        // Print the time of the stock update
        char timeStr[6];
        generateRandomTime(timeStr);
        printf("Stock updates for %s are as follows at %s:\n", stockSymbols[i%numStocks], timeStr);
        // Calculate the new price for the stock and print the percentage change from the previous price
        int oldPrice = currentPrices[i%numStocks];
        int newPrice = generateRandomPrice();
        currentPrices[i%numStocks] = newPrice;
        double percentChange = ((double)(newPrice - oldPrice) / oldPrice) * 100;
        printf("Price changed by %.2f%% from $%d to $%d\n", percentChange, oldPrice, newPrice);
        // Wait for 1 second before printing updates for the next stock
        printf("---------------------------------------------------------\n");
        sleep(1);
    }
    return 0;
}