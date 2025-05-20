//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: inquisitive
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

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int volume;
} Stock;

int main() {
    Stock stocks[MAX_STOCKS];
    int numStocks = 0;
    char input[100];

    printf("Welcome to the Stock Market Tracker!\n");

    while (1) {
        printf("Enter a stock name (or type 'quit' to exit): ");
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        char* token = strtok(input, " ");
        strcpy(stocks[numStocks].name, token);

        token = strtok(NULL, " ");
        strcpy(stocks[numStocks].symbol, token);

        token = strtok(NULL, " ");
        stocks[numStocks].price = atof(token);

        token = strtok(NULL, " ");
        stocks[numStocks].volume = atoi(token);

        numStocks++;
    }

    printf("\nStock Market Tracker\n");
    printf("=====================\n");

    for (int i = 0; i < numStocks; i++) {
        printf("%-20s %-10s $%.2f %10d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].volume);
    }

    return 0;
}