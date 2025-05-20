//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_STOCKS 10
#define STOCK_NAME_LEN 32

typedef struct {
    char name[STOCK_NAME_LEN];
    float price;
    float change;
} stock;

stock stocks[NUM_STOCKS];

void generate_stocks() {
    for (int i = 0; i < NUM_STOCKS; i++) {
        strcpy(stocks[i].name, "Stock ");
        char num[4];
        sprintf(num, "%d", i + 1);
        strcat(stocks[i].name, num);

        stocks[i].price = (float)rand() / RAND_MAX * 100.0;

        stocks[i].change = (float)(rand() % 11) / 10.0 - 0.5;
    }
}

void print_stocks() {
    printf("%-20s %-10s %-10s\n", "Name", "Price", "Change");
    for (int i = 0; i < NUM_STOCKS; i++) {
        printf("%-20s $%.2f %.2f%%\n", stocks[i].name, stocks[i].price, stocks[i].change * 100.0);
    }
}

int main() {
    srand(time(NULL));

    generate_stocks();

    while (1) {
        print_stocks();

        printf("Enter a command (q to quit): ");
        char command;
        scanf(" %c", &command);

        if (command == 'q') {
            break;
        }
    }

    return 0;
}