//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 20
#define MAX_VOLUME_LEN 20
#define MAX_CHANGE_LEN 20
#define MAX_PERCENT_CHANGE_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char price[MAX_PRICE_LEN];
    char volume[MAX_VOLUME_LEN];
    char change[MAX_CHANGE_LEN];
    char percent_change[MAX_PERCENT_CHANGE_LEN];
} Stock;

int main() {
    int num_stocks = 0;
    Stock stocks[MAX_STOCKS];

    FILE *fp = fopen("stocks.csv", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (num_stocks >= MAX_STOCKS) {
            printf("Error: Maximum number of stocks exceeded.\n");
            fclose(fp);
            return 1;
        }

        char *token = strtok(line, ",");
        strcpy(stocks[num_stocks].name, token);

        token = strtok(NULL, ",");
        strcpy(stocks[num_stocks].symbol, token);

        token = strtok(NULL, ",");
        strcpy(stocks[num_stocks].price, token);

        token = strtok(NULL, ",");
        strcpy(stocks[num_stocks].volume, token);

        token = strtok(NULL, ",");
        strcpy(stocks[num_stocks].change, token);

        token = strtok(NULL, ",");
        strcpy(stocks[num_stocks].percent_change, token);

        num_stocks++;
    }

    fclose(fp);

    printf("Name\tSymbol\tPrice\tVolume\tChange\t% Change\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%-20s\t%-10s\t%-20s\t%-20s\t%-20s\t%-20s\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].volume, stocks[i].change, stocks[i].percent_change);
    }

    return 0;
}