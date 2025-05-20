//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int quantity;
} Stock;

void init_stock(Stock *s) {
    strcpy(s->name, "");
    strcpy(s->symbol, "");
    s->price = 0;
    s->quantity = 0;
}

int main() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    printf("Welcome to the Stock Market Tracker!\n");
    printf("Today's date is: %d-%02d-%02d\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);

    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    while (num_stocks < MAX_STOCKS) {
        printf("\nEnter stock information (leave blank to finish):\n");
        printf("Name: ");
        scanf("%s", stocks[num_stocks].name);

        if (strcmp(stocks[num_stocks].name, "") == 0) {
            break;
        }

        printf("Symbol: ");
        scanf("%s", stocks[num_stocks].symbol);

        printf("Price: ");
        scanf("%lf", &stocks[num_stocks].price);

        printf("Quantity: ");
        scanf("%d", &stocks[num_stocks].quantity);

        num_stocks++;
    }

    printf("\nYour portfolio:\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%s (%s) - %.2f - %d shares\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }

    return 0;
}