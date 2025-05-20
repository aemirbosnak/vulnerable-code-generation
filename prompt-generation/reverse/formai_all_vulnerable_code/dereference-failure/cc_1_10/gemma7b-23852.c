//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a structure to store stock market data
typedef struct StockMarketData
{
    char name[50];
    double currentPrice;
    double previousPrice;
    double change;
    double percentageChange;
} StockMarketData;

// Function to calculate the percentage change in a stock
double calculatePercentageChange(double currentPrice, double previousPrice)
{
    double percentageChange = (currentPrice - previousPrice) / previousPrice * 100;
    return percentageChange;
}

// Function to display the stock market data
void displayStockMarketData(StockMarketData *stockMarketData)
{
    printf("Name: %s\n", stockMarketData->name);
    printf("Current Price: %.2lf\n", stockMarketData->currentPrice);
    printf("Previous Price: %.2lf\n", stockMarketData->previousPrice);
    printf("Change: %.2lf\n", stockMarketData->change);
    printf("Percentage Change: %.2lf%\n", stockMarketData->percentageChange);
    printf("\n");
}

int main()
{
    // Create an array of stock market data structures
    StockMarketData *stockMarketData = (StockMarketData *)malloc(sizeof(StockMarketData) * 10);

    // Populate the array with sample data
    strcpy(stockMarketData->name, "Apple");
    stockMarketData->currentPrice = 150.00;
    stockMarketData->previousPrice = 145.00;
    stockMarketData->change = 5.00;
    stockMarketData->percentageChange = 3.40;

    displayStockMarketData(stockMarketData);

    // Free the memory allocated for the array
    free(stockMarketData);

    return 0;
}