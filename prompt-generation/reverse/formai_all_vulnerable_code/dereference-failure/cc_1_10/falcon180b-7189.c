//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10

// Define structure for stock information
typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int volume;
    time_t timestamp;
} Stock;

// Function to read stock data from file and store in array
void readStocks(Stock* stocks, FILE* file) {
    int count = 0;
    while (fscanf(file, "%s %s %.2f %d %ld\n", &stocks[count].name, &stocks[count].symbol, &stocks[count].price, &stocks[count].volume, &stocks[count].timestamp) == 5) {
        count++;
        if (count >= MAX_STOCKS) {
            break;
        }
    }
    stocks[count].timestamp = 0;
}

// Function to sort stocks by price
void sortStocks(Stock* stocks, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (stocks[j].price < stocks[i].price) {
                Stock temp = stocks[i];
                stocks[i] = stocks[j];
                stocks[j] = temp;
            }
        }
    }
}

// Function to display stock information
void displayStocks(Stock* stocks, int count) {
    printf("Name\tSymbol\tPrice\tVolume\tTimestamp\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10s %.2f %10d %s\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].volume, ctime(&stocks[i].timestamp));
    }
}

// Main function to read stock data from file, sort by price, and display top 10 stocks
int main() {
    FILE* file = fopen("stock_data.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    Stock stocks[MAX_STOCKS];
    int count = 0;
    readStocks(stocks, file);
    fclose(file);

    sortStocks(stocks, count);

    displayStocks(stocks, count);

    return 0;
}