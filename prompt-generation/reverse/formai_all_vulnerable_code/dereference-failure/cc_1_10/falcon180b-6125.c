//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} Stock;

void readStocks(Stock stocks[]) {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("stocks.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= MAX_STOCKS) {
            printf("Error: Maximum number of stocks exceeded.\n");
            exit(1);
        }

        strcpy(stocks[i].name, strtok(line, ","));
        stocks[i].price = atof(strtok(NULL, ","));

        i++;
    }

    fclose(fp);
}

void displayStocks(Stock stocks[]) {
    int i;

    for (i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].name[0]!= '\0') {
            printf("%s: $%.2f\n", stocks[i].name, stocks[i].price);
        }
    }
}

void updateStockPrices(Stock stocks[]) {
    int i;

    for (i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].name[0]!= '\0') {
            stocks[i].price += 0.1;
        }
    }
}

int main() {
    Stock stocks[MAX_STOCKS];

    readStocks(stocks);
    displayStocks(stocks);
    updateStockPrices(stocks);
    displayStocks(stocks);

    return 0;
}