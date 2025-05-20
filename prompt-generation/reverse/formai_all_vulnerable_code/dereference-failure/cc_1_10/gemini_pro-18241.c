//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_STOCK_NAME_LEN 32
#define MAX_DATA_LEN 256

typedef struct {
    char name[MAX_STOCK_NAME_LEN];
    float price;
    float change;
    float volume;
} Stock;

Stock stocks[MAX_STOCKS];
int num_stocks;

void print_stock(Stock stock) {
    printf("%s: $%.2f (%.2f%%) Vol: %.2f\n", stock.name, stock.price, stock.change, stock.volume);
}

void print_stocks() {
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }
}

void load_stocks() {
    FILE *fp = fopen("stocks.csv", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    char line[MAX_DATA_LEN];
    while (fgets(line, MAX_DATA_LEN, fp) != NULL) {
        char *name = strtok(line, ",");
        char *price = strtok(NULL, ",");
        char *change = strtok(NULL, ",");
        char *volume = strtok(NULL, ",");

        if (name == NULL || price == NULL || change == NULL || volume == NULL) {
            printf("Invalid data in file\n");
            exit(EXIT_FAILURE);
        }

        Stock stock;
        strcpy(stock.name, name);
        stock.price = atof(price);
        stock.change = atof(change);
        stock.volume = atof(volume);

        stocks[num_stocks++] = stock;
    }

    fclose(fp);
}

void sort_stocks() {
    for (int i = 0; i < num_stocks - 1; i++) {
        for (int j = i + 1; j < num_stocks; j++) {
            if (strcmp(stocks[i].name, stocks[j].name) > 0) {
                Stock temp = stocks[i];
                stocks[i] = stocks[j];
                stocks[j] = temp;
            }
        }
    }
}

void search_stocks() {
    char search_term[MAX_STOCK_NAME_LEN];
    printf("Enter search term: ");
    scanf("%s", search_term);

    for (int i = 0; i < num_stocks; i++) {
        if (strstr(stocks[i].name, search_term) != NULL) {
            print_stock(stocks[i]);
        }
    }
}

int main() {
    load_stocks();
    sort_stocks();

    printf("Stock Market Tracker\n");
    printf("--------------------\n");
    print_stocks();

    search_stocks();

    return 0;
}