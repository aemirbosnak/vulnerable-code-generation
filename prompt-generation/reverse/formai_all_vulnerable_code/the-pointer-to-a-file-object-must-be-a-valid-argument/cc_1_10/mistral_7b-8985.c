//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COMPANIES 100
#define LINE_LENGTH 100

typedef struct {
    char name[LINE_LENGTH];
    float current_price;
    float previous_close;
    float change_percent;
} Stock;

void read_csv(const char *filename, Stock stocks[MAX_COMPANIES]) {
    FILE *file = fopen(filename, "r");
    char line[LINE_LENGTH];
    int i = 0;

    while (fgets(line, LINE_LENGTH, file) != NULL) {
        if (i >= MAX_COMPANIES) {
            printf("Error: Too many companies in CSV file.\n");
            exit(1);
        }

        sscanf(line, "%[^,],%f,%f,%f", stocks[i].name, &stocks[i].previous_close, &stocks[i].current_price);
        stocks[i].change_percent = ((stocks[i].current_price - stocks[i].previous_close) / stocks[i].previous_close) * 100.0;
        i++;
    }

    fclose(file);
}

void print_stocks(Stock stocks[MAX_COMPANIES]) {
    int i;

    for (i = 0; i < MAX_COMPANIES && stocks[i].name[0] != '\0'; i++) {
        printf("%s | %.2f | %.2f | %.2f%%\n", stocks[i].name, stocks[i].current_price, stocks[i].previous_close, stocks[i].change_percent);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <path_to_csv_file>\n", argv[0]);
        return 1;
    }

    Stock stocks[MAX_COMPANIES];
    read_csv(argv[1], stocks);
    print_stocks(stocks);

    return 0;
}