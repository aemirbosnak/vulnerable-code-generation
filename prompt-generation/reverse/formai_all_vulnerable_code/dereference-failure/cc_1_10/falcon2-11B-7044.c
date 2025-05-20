//Falcon2-11B DATASET v1.0 Category: Stock market tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
int num_stocks = 0;
char *stocks[100];

// Function to add a stock to the tracker
void add_stock(const char *stock) {
    if (num_stocks < 100) {
        stocks[num_stocks] = (char*)malloc(strlen(stock) + 1);
        strcpy(stocks[num_stocks], stock);
        num_stocks++;
    } else {
        printf("Maximum number of stocks reached.\n");
    }
}

// Function to remove a stock from the tracker
void remove_stock(int index) {
    if (index >= 0 && index < num_stocks) {
        free(stocks[index]);
        stocks[index] = NULL;
        num_stocks--;
    } else {
        printf("Invalid index.\n");
    }
}

// Function to display all stocks in the tracker
void display_stocks() {
    if (num_stocks > 0) {
        printf("Current stocks:\n");
        for (int i = 0; i < num_stocks; i++) {
            if (stocks[i]!= NULL) {
                printf("%s\n", stocks[i]);
            }
        }
    } else {
        printf("No stocks in the tracker.\n");
    }
}

int main() {
    printf("Welcome to the Stock Market Tracker!\n");

    // Add some stocks to the tracker
    add_stock("Apple");
    add_stock("Microsoft");
    add_stock("Tesla");
    add_stock("Amazon");

    // Display the stocks
    display_stocks();

    // Remove a stock from the tracker
    remove_stock(2);

    // Display the updated stocks
    display_stocks();

    return 0;
}