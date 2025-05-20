//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINES 1000
#define MAX_COLS 10
#define DELIM ",\n"

typedef struct {
    char symbol[5];
    float price;
    float ma[5];
    int ma_index;
} Stock;

void init_ma(Stock *stock, float ma[]) {
    int i;
    for (i = 0; i < 5; i++) {
        ma[i] = 0;
    }
    stock->ma_index = 0;
}

void update_ma(Stock *stock, float new_price) {
    int i;
    float sum = 0;

    for (i = stock->ma_index; i > 0; i--) {
        sum += stock->ma[i];
    }

    sum += new_price;
    stock->ma[stock->ma_index] = sum / (stock->ma_index + 1);

    if (stock->ma_index >= 4) {
        sum -= stock->ma[stock->ma_index - 5];
    }

    stock->ma[stock->ma_index] = sum / 5;
    stock->ma_index++;
}

int main() {
    FILE *file;
    char line[MAX_LINES][MAX_COLS];
    Stock stocks[10];
    int i, j;
    int num_stocks = 0;

    file = fopen("stocks.csv", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line[num_stocks], MAX_COLS, file) != NULL) {
        char symbol[5];
        float price;
        sscanf(line, "%s %f", symbol, &price);

        for (i = 0; i < 10; i++) {
            if (strcmp(stocks[i].symbol, symbol) == 0) {
                stocks[i].price = price;
                update_ma(&stocks[i], price);
                break;
            }
        }

        if (i == 10) {
            for (j = 0; j < 10; j++) {
                if (stocks[j].ma_index == 0) {
                    strcpy(stocks[j].symbol, symbol);
                    init_ma(&stocks[j], stocks[j].ma);
                    stocks[j].price = price;
                    update_ma(&stocks[j], price);
                    num_stocks++;
                    break;
                }
            }
        }
    }

    fclose(file);

    for (i = 0; i < num_stocks; i++) {
        printf("Symbol: %s, Price: %.2f, MA: %.2f\n", stocks[i].symbol, stocks[i].price, stocks[i].ma[0]);
    }

    return 0;
}