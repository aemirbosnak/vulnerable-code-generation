//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random stock values
double generateStockValue() {
    return (double)rand() / (double)RAND_MAX * 100.0;
}

// Function to simulate the stock market
void simulateStockMarket(double* stockValues, int numDays) {
    for (int i = 1; i < numDays; i++) {
        // Get the previous day's stock value
        double previousValue = stockValues[i - 1];
        
        // Generate a random fluctuation percentage
        double fluctuationPercentage = ((double)rand() / (double)RAND_MAX * 2.0) - 1.0;

        // Calculate the new stock value
        stockValues[i] = previousValue * (1.0 + fluctuationPercentage);
    }
}

// Function to print the stock values
void printStockValues(double* stockValues, int numDays) {
    printf("Day\tStock Value\n");
    for (int i = 0; i < numDays; i++) {
        printf("%d\t%.2f\n", i + 1, stockValues[i]);
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Get the number of days to simulate
    int numDays;
    printf("Enter the number of days to simulate: ");
    scanf("%d", &numDays);
    
    // Create an array to store the stock values
    double* stockValues = (double*)malloc(numDays * sizeof(double));
    
    // Generate the initial stock value
    stockValues[0] = generateStockValue();
    
    // Simulate the stock market
    simulateStockMarket(stockValues, numDays);
    
    // Print the stock values
    printStockValues(stockValues, numDays);
    
    // Free the allocated memory
    free(stockValues);
    
    return 0;
}