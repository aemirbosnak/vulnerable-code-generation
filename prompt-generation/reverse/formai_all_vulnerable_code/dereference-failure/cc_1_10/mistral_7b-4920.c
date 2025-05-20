//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINES 1000
#define WINDOW_SIZE 20

struct Stock {
    char symbol[10];
    float price;
};

void read_csv(FILE *file, struct Stock stocks[MAX_LINES]) {
    int i = 0;
    char line[100];
    char *token;

    while (fgets(line, sizeof(line), file)) {
        if (i > 0) {
            strcpy(stocks[i - 1].symbol, strtok(line, ","));
            stocks[i - 1].price = atof(strtok(NULL, ","));
        }
        i++;
    }
}

float moving_average(float prices[], int window_size, int start_index) {
    float sum = 0;
    int i;

    for (i = start_index; i < start_index + window_size; i++) {
        sum += prices[i];
    }

    return sum / window_size;
}

int main() {
    FILE *file;
    struct Stock stocks[MAX_LINES];
    float prices[WINDOW_SIZE];
    int i, j;

    file = fopen("stocks.csv", "r");

    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    read_csv(file, stocks);
    fclose(file);

    for (i = 0; i < MAX_LINES - WINDOW_SIZE; i++) {
        prices[0] = stocks[i].price;
        for (j = 1; j < WINDOW_SIZE; j++) {
            prices[j] = stocks[i + j].price;
        }

        printf("%s Day %d: %0.2f%%\n", stocks[i].symbol, i + 1,
               (moving_average(prices, WINDOW_SIZE, 0) - stocks[i].price) / stocks[i].price * 100);
    }

    return 0;
}