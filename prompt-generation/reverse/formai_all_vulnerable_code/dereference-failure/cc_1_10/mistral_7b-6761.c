//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <time.h>
#include <math.h>

#define MAX_LINES 10000
#define BUF_SIZE 1024

typedef struct {
    char symbol[10];
    double price;
    double change_pct;
} StockData;

void read_csv(char *filename, StockData stocks[MAX_LINES]) {
    FILE *fp;
    char buffer[BUF_SIZE];
    char *token;
    int line_num = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while (fgets(buffer, BUF_SIZE, fp) != NULL && line_num < MAX_LINES) {
        token = strtok(buffer, ",");
        strcpy(stocks[line_num].symbol, token);

        token = strtok(NULL, ",");
        stocks[line_num].price = atof(token);

        token = strtok(NULL, ",");
        stocks[line_num].change_pct = atof(token);

        line_num++;
    }

    fclose(fp);
}

void print_stocks(StockData stocks[MAX_LINES], int num_stocks) {
    int i;

    printf("\n%-10s %-15s %-10s %-10s\n", "Symbol", "Price", "Change %%", "Change");

    for (i = 0; i < num_stocks; i++) {
        printf("%-10s $%.2f %-10.2f %-10.2f\n", stocks[i].symbol, stocks[i].price,
               stocks[i].change_pct, stocks[i].price * (1 + stocks[i].change_pct));
    }
}

int main(int argc, char *argv[]) {
    StockData stocks[MAX_LINES];
    char filename[128];
    int num_stocks;

    if (argc < 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        exit(1);
    }

    strcpy(filename, argv[1]);
    read_csv(filename, stocks);
    num_stocks = argc < 3 ? MAX_LINES : atoi(argv[2]);

    print_stocks(stocks, num_stocks);

    return 0;
}