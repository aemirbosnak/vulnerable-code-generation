//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 10
#define MAX_PRICE_LENGTH 10
#define MAX_VOLUME_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    char price[MAX_PRICE_LENGTH];
    int volume;
} Stock;

int main() {
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (num_stocks >= MAX_STOCKS) {
            printf("Error: too many stocks.\n");
            exit(1);
        }

        char *name = line;
        char *symbol = strstr(line, ",");
        if (symbol == NULL) {
            printf("Error: invalid line format.\n");
            exit(1);
        }
        *symbol = '\0';
        symbol++;

        char *price = strstr(symbol, ",");
        if (price == NULL) {
            printf("Error: invalid line format.\n");
            exit(1);
        }
        *price = '\0';
        price++;

        char *volume_str = strstr(price, ",");
        if (volume_str == NULL) {
            printf("Error: invalid line format.\n");
            exit(1);
        }
        *volume_str = '\0';
        volume_str++;

        strcpy(stocks[num_stocks].name, name);
        strcpy(stocks[num_stocks].symbol, symbol);
        strcpy(stocks[num_stocks].price, price);
        stocks[num_stocks].volume = atoi(volume_str);

        num_stocks++;
    }

    fclose(fp);

    printf("Number of stocks: %d\n", num_stocks);

    for (int i = 0; i < num_stocks; i++) {
        printf("%s (%s) - Price: $%s - Volume: %d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].volume);
    }

    return 0;
}