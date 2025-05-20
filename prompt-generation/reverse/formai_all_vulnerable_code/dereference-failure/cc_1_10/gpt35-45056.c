//FormAI DATASET v1.0 Category: Stock market tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store stock market information
struct stock {
    char name[20];
    float price;
};

// Function to display stock market data
void displayData(struct stock *s, int n) {
    printf("\n---------- STOCK MARKET TRACKER ----------\n\n");
    printf("NAME\t\tPRICE\n");

    for(int i = 0; i < n; i++) {
        printf("%s\t\t$%.2f\n", s[i].name, s[i].price);
    }

    printf("-----------------------------------------\n");
}

int main() {
    // Initializing variables
    int n;
    char option[2];
    struct stock *market;

    // User input for number of stocks to be tracked
    printf("Enter the number of stocks to track: ");
    scanf("%d", &n);

    // Allocating memory dynamically for market variable
    market = (struct stock*) malloc(n * sizeof(struct stock));

    // User input for stock market data
    for(int i = 0; i < n; i++) {
        printf("\nEnter the name of stock %d: ", i+1);
        getchar();
        fgets((market+i)->name, 20, stdin);

        printf("Enter the price of stock %d: $", i+1);
        scanf("%f", &(market+i)->price);
    }

    // Displaying initial stock data
    displayData(market, n);

    // Loop for real-time tracking of stock data
    while(1) {
        printf("\nDo you want to update stock prices? (y/n): ");
        getchar();
        fgets(option, 2, stdin); // Use fgets to avoid buffer overflow

        if(option[0] == 'y' || option[0] == 'Y') {
            // User input to update the stock data
            char stockName[20];
            float newPrice;
            printf("\nEnter the name of the stock to update: ");
            fgets(stockName, 20, stdin);

            for(int i = 0; i < n; i++) {
                if(strcmp((market+i)->name, stockName) == 0) {
                    printf("Enter the new price for %s: $", (market+i)->name);
                    scanf("%f", &newPrice);
                    (market+i)->price = newPrice;
                    break;
                }
            }

            // Displaying updated stock data
            displayData(market, n);

        } else if (option[0] == 'n' || option[0] == 'N') {
            printf("\nExiting stock market tracker!\n");
            break;
        } else {
            printf("\nInvalid input. Please try again!\n");
        }
    }

    // Freeing dynamically allocated memory
    free(market);

    return 0;
}