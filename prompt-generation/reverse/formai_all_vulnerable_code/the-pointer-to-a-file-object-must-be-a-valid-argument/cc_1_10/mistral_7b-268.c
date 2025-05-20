//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <math.h>

typedef struct {
    char symbol[5];
    float current_price;
    float previous_closing_price;
    float change_percent;
} Stock;

void get_stock_data(Stock* stock, char* file_path) {
    int fd = open(file_path, O_RDONLY);
    char line[256];
    int line_number = 0;

    if (fd < 0) {
        perror("Error opening file");
        exit(1);
    }

    while (fgets(line, sizeof(line), fd) != NULL) {
        line_number++;

        if (line_number < 5) continue;

        if (sscanf(line, "%s %f %f", stock->symbol, &stock->previous_closing_price, &stock->current_price) != 3) {
            perror("Error parsing line");
            exit(1);
        }

        break;
    }

    close(fd);
}

void print_stock_data(Stock stock) {
    printf("%s Current Price: %.2f Previous Closing Price: %.2f Change Percentage: %.2f%%\n", stock.symbol, stock.current_price, stock.previous_closing_price, stock.change_percent);
}

void calculate_change_percent(Stock* stock) {
    stock->change_percent = ((stock->current_price - stock->previous_closing_price) / stock->previous_closing_price) * 100;
}

int main() {
    Stock stocks[10];
    char file_paths[10][128];

    for (int i = 0; i < 10; i++) {
        snprintf(file_paths[i], sizeof(file_paths[i]), "/home/user/stocks/%s.txt", "AAPL");
        get_stock_data(&stocks[i], file_paths[i]);
        calculate_change_percent(&stocks[i]);
        print_stock_data(stocks[i]);
    }

    return 0;
}