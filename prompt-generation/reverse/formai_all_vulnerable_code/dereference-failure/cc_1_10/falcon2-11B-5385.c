//Falcon2-11B DATASET v1.0 Category: Stock market tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Read stock data from file
void read_data(char *file_name, int *stock_data, int n) {
    FILE *f = fopen(file_name, "r");
    if (f == NULL) {
        printf("Error opening file %s.\n", file_name);
        exit(1);
    }

    char line[100];
    while (fgets(line, sizeof(line), f)!= NULL) {
        char *token = strtok(line, ",");
        int price = atoi(token);
        int id = atoi(strtok(NULL, ","));

        if (id >= 0 && id <= n) {
            stock_data[id] = price;
        }
    }

    fclose(f);
}

// Output the top 5 highest-priced stocks
void top_5(int *stock_data, int n) {
    int i, max = 0, max_id = 0;

    for (i = 0; i < n; i++) {
        if (stock_data[i] > max) {
            max = stock_data[i];
            max_id = i;
        }
    }

    printf("Top 5 highest-priced stocks:\n");
    for (i = 0; i < 5; i++) {
        if (i == max_id) {
            printf("Stock %d: %d\n", i + 1, max);
        }
    }
}

int main() {
    char file_name[] = "stock_data.txt";
    int stock_data[100];
    int n = 0;

    read_data(file_name, stock_data, n);
    top_5(stock_data, n);

    return 0;
}