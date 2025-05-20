//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: safe
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
} Stock;

Stock stocks[MAX_STOCKS];
int num_stocks;

void read_stocks_from_file(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char* name = strtok(line, ",");
        char* symbol = strtok(NULL, ",");
        double price = strtod(strtok(NULL, ","), NULL);

        if (num_stocks >= MAX_STOCKS) {
            printf("Maximum number of stocks reached\n");
            break;
        }

        strcpy(stocks[num_stocks].name, name);
        strcpy(stocks[num_stocks].symbol, symbol);
        stocks[num_stocks].price = price;

        num_stocks++;
    }

    fclose(fp);
}

void print_stock_table() {
    printf("+----+----------------+--------+\n");
    printf("| Rank | Name           | Symbol |\n");
    printf("+----+----------------+--------+\n");

    for (int i = 0; i < num_stocks; i++) {
        printf("| %3d | %-20s | %-10s |\n", i+1, stocks[i].name, stocks[i].symbol);
    }

    printf("+----+----------------+--------+\n");
}

int compare_stocks_by_price(const void* a, const void* b) {
    const Stock* stock_a = (const Stock*)a;
    const Stock* stock_b = (const Stock*)b;

    if (stock_a->price > stock_b->price) {
        return -1;
    } else if (stock_a->price < stock_b->price) {
        return 1;
    } else {
        return 0;
    }
}

void sort_stocks_by_price() {
    qsort(stocks, num_stocks, sizeof(Stock), compare_stocks_by_price);
}

int main() {
    read_stocks_from_file("stocks.csv");
    sort_stocks_by_price();
    print_stock_table();

    return 0;
}