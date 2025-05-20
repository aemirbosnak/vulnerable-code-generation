//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_LINES 1000
#define LENGTH 100
#define FILENAME "stock_data.txt"

typedef struct {
    char symbol[LENGTH];
    float price;
    time_t timestamp;
} StockData;

void readFile(FILE *file) {
    StockData stock[MAX_LINES];
    int i = 0;

    while (fscanf(file, "%s %f %ld", stock[i].symbol, &stock[i].price, &stock[i].timestamp) != EOF) {
        i++;
    }

    rewind(file);
}

void printHeader() {
    printf("%-10s %-15s %-20s\n", "Index", "Symbol", "Price");
}

void printData(StockData data) {
    float index = sqrt(pow(data.price, 2) + pow(data.price * 0.01, 2));

    printf("%-10d %-15s %-12.2f %-10.2f\n", (int) (data.timestamp / 60 / 60 / 24), data.symbol, data.price, index);
}

void printAllData(StockData *data, int size) {
    printHeader();

    for (int i = 0; i < size; i++) {
        printData(data[i]);
    }
}

int main() {
    FILE *file = fopen(FILENAME, "r");
    StockData *stockData = malloc(MAX_LINES * sizeof(StockData));

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    readFile(file);
    fclose(file);

    int size = 0;

    for (int i = 0; i < MAX_LINES; i++) {
        if (stockData[i].price > 0) {
            size++;
            stockData[size - 1].price *= 1.02; // simulate stock price increase by 2%
        }
    }

    printAllData(stockData, size);

    free(stockData);

    return 0;
}