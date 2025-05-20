//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10
#define MAX_VOLUME_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char price[MAX_PRICE_LEN];
    char volume[MAX_VOLUME_LEN];
} Stock;

int main() {
    FILE *fp = fopen("stock_data.txt", "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    int num_stocks = 0;
    Stock stocks[MAX_STOCKS];

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (num_stocks >= MAX_STOCKS) {
            printf("Error: Maximum number of stocks reached.\n");
            break;
        }

        char *token = strtok(line, ",");
        strcpy(stocks[num_stocks].name, token);
        token = strtok(NULL, ",");
        strcpy(stocks[num_stocks].symbol, token);
        token = strtok(NULL, ",");
        strcpy(stocks[num_stocks].price, token);
        token = strtok(NULL, ",");
        strcpy(stocks[num_stocks].volume, token);

        num_stocks++;
    }

    fclose(fp);

    printf("Stock Data:\n");
    printf("---------------------------------------------------------\n");
    printf("Name             Symbol            Price            Volume\n");
    printf("---------------------------------------------------------\n");

    for (int i = 0; i < num_stocks; i++) {
        printf("%-20s ", stocks[i].name);
        printf("%-10s ", stocks[i].symbol);
        printf("%-10s ", stocks[i].price);
        printf("%-10s\n", stocks[i].volume);
    }

    return 0;
}