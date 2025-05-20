//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <locale.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int volume;
    time_t timestamp;
} Stock;

void print_header(void) {
    printf("Name\tSymbol\tPrice\tVolume\tTimestamp\n");
}

void print_stock(const Stock *stock) {
    printf("%-20s\t%-10s\t%.2f\t%d\t%s\n", stock->name, stock->symbol, stock->price, stock->volume, ctime(&stock->timestamp));
}

int main(void) {
    setlocale(LC_ALL, "");
    char input[MAX_NAME_LEN + MAX_SYMBOL_LEN + 10];
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    print_header();

    while (num_stocks < MAX_STOCKS) {
        printf("Enter a stock (name symbol price volume): ");
        fgets(input, sizeof(input), stdin);

        char *name = strtok(input, " ");
        char *symbol = strtok(NULL, " ");
        double price = strtod(strtok(NULL, " "), NULL);
        int volume = strtol(strtok(NULL, " "), NULL, 10);

        if (name && symbol && price > 0 && volume > 0) {
            stocks[num_stocks] = (Stock) {
               .name = strdup(name),
               .symbol = strdup(symbol),
               .price = price,
               .volume = volume,
               .timestamp = time(NULL)
            };

            num_stocks++;
        } else {
            printf("Invalid input\n");
        }
    }

    for (int i = 0; i < num_stocks; i++) {
        print_stock(&stocks[i]);
    }

    return 0;
}