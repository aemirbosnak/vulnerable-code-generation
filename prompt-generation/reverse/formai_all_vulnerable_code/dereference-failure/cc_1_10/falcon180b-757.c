//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

// Define the structure of a stock
typedef struct {
    char symbol[10];
    double price;
    int volume;
    time_t timestamp;
} Stock;

// Function to compare two stocks based on their prices
int compare(const void *a, const void *b) {
    const Stock *stockA = (const Stock *)a;
    const Stock *stockB = (const Stock *)b;

    if (stockA->price > stockB->price) {
        return 1;
    } else if (stockA->price < stockB->price) {
        return -1;
    } else {
        return 0;
    }
}

// Function to print the details of a stock
void printStock(const Stock *stock) {
    printf("Symbol: %s\n", stock->symbol);
    printf("Price: $%.2f\n", stock->price);
    printf("Volume: %d\n", stock->volume);
    printf("Timestamp: %s\n\n", ctime(&stock->timestamp));
}

// Function to read the stock data from a file
void readStocks(Stock stocks[], int maxStocks, FILE *file) {
    int numStocks = 0;

    while (fscanf(file, "%s $%lf %d %ld\n", stocks[numStocks].symbol, &stocks[numStocks].price, &stocks[numStocks].volume, &stocks[numStocks].timestamp) == 4) {
        numStocks++;

        if (numStocks == maxStocks) {
            break;
        }
    }

    qsort(stocks, numStocks, sizeof(Stock), compare);
}

// Function to write the top 10 stocks to a file
void writeTopStocks(const Stock stocks[], int numStocks, FILE *file) {
    printf("Top 10 Stocks:\n");

    for (int i = 0; i < numStocks && i < 10; i++) {
        printStock(&stocks[i]);
        fprintf(file, "%s $%.2f %d %ld\n", stocks[i].symbol, stocks[i].price, stocks[i].volume, stocks[i].timestamp);
    }
}

int main() {
    Stock stocks[100];
    int numStocks = 0;
    FILE *inputFile = fopen("stock_data.txt", "r");
    FILE *outputFile = fopen("top_stocks.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    readStocks(stocks, 100, inputFile);
    writeTopStocks(stocks, numStocks, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}