//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 50
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10

struct stock {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char price[MAX_PRICE_LEN];
    float value;
};

int main() {
    int num_stocks;
    struct stock stocks[MAX_STOCKS];
    char input[100];
    float total_value = 0;
    float avg_value = 0;
    int i;

    printf("Enter the number of stocks to track: ");
    scanf("%d", &num_stocks);

    for (i = 0; i < num_stocks; i++) {
        printf("Enter the name of stock %d: ", i+1);
        scanf("%s", stocks[i].name);
        strcpy(stocks[i].symbol, toupper(stocks[i].name[0]));
        strcat(stocks[i].symbol, &stocks[i].name[1]);
        printf("Enter the current price of %s: ", stocks[i].symbol);
        scanf("%s", stocks[i].price);
        stocks[i].value = atof(stocks[i].price);
        total_value += stocks[i].value;
    }

    avg_value = total_value / num_stocks;

    printf("\nStock Market Tracker\n");
    printf("====================\n");
    printf("Number of stocks: %d\n", num_stocks);
    printf("Total value: $%.2f\n", total_value);
    printf("Average value: $%.2f\n", avg_value);

    printf("\nStock\tSymbol\tPrice\tValue\n");
    for (i = 0; i < num_stocks; i++) {
        printf("%s\t%s\t$%.2f\t$%.2f\n", stocks[i].name, stocks[i].symbol, atof(stocks[i].price), stocks[i].value);
    }

    return 0;
}