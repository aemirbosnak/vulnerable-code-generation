//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Elementary, my dear Watson!
typedef struct {
    char *symbol;
    float price;
    int volume;
} Stock;

// The game is afoot!
int main(int argc, char *argv[]) {
    // Watson, fetch me the stock data!
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Elementary, my dear Watson! The file could not be opened.\n");
        return EXIT_FAILURE;
    }

    // I have a keen eye for detail!
    char line[1024];
    Stock stocks[100];
    int num_stocks = 0;
    while (fgets(line, sizeof(line), fp)) {
        // Watson, parse the stock data!
        char *symbol = strtok(line, ",");
        float price = atof(strtok(NULL, ","));
        int volume = atoi(strtok(NULL, ","));

        // Elementary, my dear Watson!
        stocks[num_stocks].symbol = malloc(strlen(symbol) + 1);
        strcpy(stocks[num_stocks].symbol, symbol);
        stocks[num_stocks].price = price;
        stocks[num_stocks].volume = volume;
        num_stocks++;
    }

    // Watson, now show me the stocks I should invest in!
    printf("The game is afoot! The following stocks are worth investigating:\n");
    for (int i = 0; i < num_stocks; i++) {
        // Elementary, my dear Watson!
        if (stocks[i].price > 100 && stocks[i].volume > 100000) {
            printf("\t%s\n", stocks[i].symbol);
        }
    }

    // Watson, close the file!
    fclose(fp);

    // The case is closed!
    return EXIT_SUCCESS;
}