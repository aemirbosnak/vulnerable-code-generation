//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BULL 1
#define BEAR 0

int main() {
    char **market_data = NULL;
    int market_data_size = 0;
    char symbol[20];
    int i, j;

    market_data = allocate_market_data();
    market_data_size = initialize_market_data(market_data);

    printf("Enter symbol:");
    scanf("%s", symbol);

    for (i = 0; i < market_data_size; i++) {
        for (j = 0; j < 5; j++) {
            if (strcmp(symbol, market_data[i][j]) == 0) {
                printf("Price: $%f\n", market_data[i][j + 1]);
                break;
            }
        }
    }

    free(market_data);

    return 0;
}

int allocate_market_data() {
    int size = 10;
    char **data = malloc(size * sizeof(char *));

    for (int i = 0; i < size; i++) {
        data[i] = malloc(50 * sizeof(char));
    }

    return data;
}

int initialize_market_data(char **data) {
    int size = 0;

    for (int i = 0; data[i] != NULL; i++) {
        size++;
    }

    return size;
}