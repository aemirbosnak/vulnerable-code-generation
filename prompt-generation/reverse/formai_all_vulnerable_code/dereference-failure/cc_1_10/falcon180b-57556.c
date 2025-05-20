//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char price[MAX_PRICE_LEN];
} Stock;

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open stocks.txt\n");
        return 1;
    }

    char line[MAX_PRICE_LEN];
    while (fgets(line, MAX_PRICE_LEN, fp)!= NULL) {
        if (num_stocks == MAX_STOCKS) {
            printf("Error: Maximum number of stocks reached\n");
            break;
        }

        char *token = strtok(line, ",");
        strcpy(stocks[num_stocks].name, token);
        strcpy(stocks[num_stocks].symbol, strtok(NULL, ","));
        strcpy(stocks[num_stocks].price, strtok(NULL, ","));
        num_stocks++;
    }

    fclose(fp);

    printf("Stock Tracker\n");
    printf("===========\n");

    while (1) {
        printf("Enter a stock symbol to track: ");
        char symbol[MAX_SYMBOL_LEN];
        scanf("%s", symbol);

        int i;
        for (i = 0; i < num_stocks; i++) {
            if (strcmp(stocks[i].symbol, symbol) == 0) {
                printf("Stock %s: $%.2f\n", stocks[i].name, atof(stocks[i].price));
                break;
            }
        }

        if (i == num_stocks) {
            printf("Stock not found\n");
        }
    }

    return 0;
}