//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int quantity;
} Stock;

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;
    char input[100];
    char delimiter = ',';

    printf("Welcome to the Linus Torvalds Stock Market Tracker!\n");
    printf("Please enter stock information in the following format: name,symbol,price,quantity\n");
    printf("Example: Apple,AAPL,100.00,50\n");

    while (fgets(input, sizeof(input), stdin)!= NULL) {
        char *token = strtok(input, &delimiter);
        if (token == NULL) {
            continue;
        }

        if (num_stocks >= MAX_STOCKS) {
            printf("Maximum number of stocks reached. Exiting...\n");
            return 1;
        }

        strcpy(stocks[num_stocks].name, token);
        token = strtok(NULL, &delimiter);
        strcpy(stocks[num_stocks].symbol, token);
        token = strtok(NULL, &delimiter);
        stocks[num_stocks].price = atof(token);
        token = strtok(NULL, &delimiter);
        stocks[num_stocks].quantity = atoi(token);

        num_stocks++;
    }

    printf("\nStock Portfolio:\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("Name: %s\nSymbol: %s\nPrice: $%.2f\nQuantity: %d\n",
                stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }

    return 0;
}