//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char price[MAX_PRICE_LEN];
} Stock;

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    char input[100];
    while(1) {
        printf("Enter stock information (name symbol price): ");
        fgets(input, sizeof(input), stdin);

        if(num_stocks >= MAX_STOCKS) {
            printf("Max stocks reached.\n");
            break;
        }

        char *token = strtok(input, " ");
        strcpy(stocks[num_stocks].name, token);

        token = strtok(NULL, " ");
        strcpy(stocks[num_stocks].symbol, token);

        token = strtok(NULL, " ");
        strcpy(stocks[num_stocks].price, token);

        num_stocks++;
    }

    printf("Stock Tracker\n");
    printf("=============\n");

    for(int i=0; i<num_stocks; i++) {
        printf("%-20s %-10s %-10s\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
    }

    return 0;
}