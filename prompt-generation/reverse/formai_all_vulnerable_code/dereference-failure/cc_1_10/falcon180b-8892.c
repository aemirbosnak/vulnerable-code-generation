//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    double price;
    int quantity;
} Stock;

void init_stock(Stock *stock, char *name, double price, int quantity) {
    strncpy(stock->name, name, MAX_NAME_LEN);
    stock->price = price;
    stock->quantity = quantity;
}

void print_stock(Stock stock) {
    printf("Name: %s\n", stock.name);
    printf("Price: $%.2f\n", stock.price);
    printf("Quantity: %d\n", stock.quantity);
    printf("\n");
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    while (num_stocks < MAX_STOCKS) {
        printf("Enter stock information (name price quantity):\n");
        char input[100];
        fgets(input, sizeof(input), stdin);

        char *name = strtok(input, " ");
        double price = strtod(strtok(NULL, " "), NULL);
        int quantity = atoi(strtok(NULL, " "));

        if (num_stocks >= MAX_STOCKS) {
            printf("Error: Maximum number of stocks reached.\n");
        } else {
            init_stock(&stocks[num_stocks], name, price, quantity);
            num_stocks++;
        }
    }

    printf("Stock Portfolio:\n");
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }

    return 0;
}