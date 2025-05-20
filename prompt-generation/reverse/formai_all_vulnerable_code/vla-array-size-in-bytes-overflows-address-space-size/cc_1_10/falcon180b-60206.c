//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 100
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
} Stock;

int main() {
    int numStocks;
    printf("Enter the number of stocks to track: ");
    scanf("%d", &numStocks);

    if (numStocks > MAX_STOCKS) {
        printf("Error: Cannot track more than %d stocks.\n", MAX_STOCKS);
        return 1;
    }

    Stock stocks[numStocks];

    for (int i = 0; i < numStocks; i++) {
        printf("Enter stock %d information:\n", i+1);
        printf("Name: ");
        scanf("%s", stocks[i].name);
        printf("Symbol: ");
        scanf("%s", stocks[i].symbol);
        printf("Price: ");
        scanf("%lf", &stocks[i].price);
    }

    while (1) {
        system("clear");
        printf("Stock Market Tracker\n");

        for (int i = 0; i < numStocks; i++) {
            printf("%d. %s (%s) - $%.2f\n", i+1, stocks[i].name, stocks[i].symbol, stocks[i].price);
        }

        printf("\nPress any key to refresh...\n");
        getchar();
    }

    return 0;
}