//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCK_SYMBOLS 100
#define MAX_STOCK_NAME_LENGTH 20
#define MAX_STOCK_PRICE_LENGTH 10

typedef struct {
    char symbol[MAX_STOCK_SYMBOLS];
    char name[MAX_STOCK_NAME_LENGTH];
    char price[MAX_STOCK_PRICE_LENGTH];
} Stock;

int main() {
    int num_stocks = 0;
    Stock stocks[MAX_STOCK_SYMBOLS];

    // Read in stock data from a file
    FILE *file = fopen("stock_data.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, 100, file)!= NULL) {
        if (num_stocks >= MAX_STOCK_SYMBOLS) {
            printf("Error: Too many stocks.\n");
            exit(1);
        }

        char *token = strtok(line, ",");
        strcpy(stocks[num_stocks].symbol, token);

        token = strtok(NULL, ",");
        strcpy(stocks[num_stocks].name, token);

        token = strtok(NULL, ",");
        strcpy(stocks[num_stocks].price, token);

        num_stocks++;
    }

    fclose(file);

    // Print out the stock data
    printf("Stock Data:\n");
    printf("--------------------\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%-20s %-20s %s\n", stocks[i].symbol, stocks[i].name, stocks[i].price);
    }

    return 0;
}