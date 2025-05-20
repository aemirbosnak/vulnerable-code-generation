//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10
#define MAX_VOLUME_LEN 10
#define MAX_CHANGE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int volume;
    double change;
} Stock;

int main() {
    FILE *fp;
    char line[1000];
    int numStocks = 0;
    Stock stocks[MAX_STOCKS];

    fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (numStocks == MAX_STOCKS) {
            printf("Maximum number of stocks reached.\n");
            break;
        }
        char *token = strtok(line, ",");
        strcpy(stocks[numStocks].name, token);
        token = strtok(NULL, ",");
        strcpy(stocks[numStocks].symbol, token);
        stocks[numStocks].price = atof(strtok(NULL, ","));
        stocks[numStocks].volume = atoi(strtok(NULL, ","));
        stocks[numStocks].change = atof(strtok(NULL, ","));
        numStocks++;
    }

    fclose(fp);

    printf("Stock Name\tSymbol\tPrice\tVolume\tChange\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%-20s\t%-10s\t%10.2f\t%10d\t%10.2f\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].volume, stocks[i].change);
    }

    return 0;
}