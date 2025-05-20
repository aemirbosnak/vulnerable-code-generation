//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 100
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
    int num_stocks = 0;
    FILE *fp;
    char line[1024];
    char *token;

    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    char date_str[80];
    strftime(date_str, sizeof(date_str), "%Y-%m-%d", tm_now);

    fp = fopen("stock_prices.csv", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ",");
        strcpy(stocks[num_stocks].symbol, token);
        token = strtok(NULL, ",");
        strcpy(stocks[num_stocks].name, token);
        token = strtok(NULL, ",");
        stocks[num_stocks].price = atof(token);
        token = strtok(NULL, ",");
        stocks[num_stocks].volume = atoi(token);
        num_stocks++;
    }

    fclose(fp);

    printf("Stock Market Tracker for %s\n", date_str);
    printf("-----------------------------------------------------\n");
    printf("Symbol\tName\tPrice\tVolume\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%-10s\t%-20s\t%10.2f\t%10d\n", stocks[i].symbol, stocks[i].name, stocks[i].price, stocks[i].volume);
    }

    return 0;
}