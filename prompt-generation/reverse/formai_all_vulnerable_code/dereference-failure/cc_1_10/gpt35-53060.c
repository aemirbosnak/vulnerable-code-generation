//FormAI DATASET v1.0 Category: Stock market tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char stock_name[20];
    float current_price;
    float open_price;
    float high_price;
    float low_price;
    float previous_close;
} Stock;

Stock *create_stock(char stock_name[], float current_price, float open_price, float high_price, float low_price, float previous_close) {
    Stock *stock = (Stock *) malloc(sizeof(Stock));
    strcpy(stock->stock_name, stock_name);
    stock->current_price = current_price;
    stock->open_price = open_price;
    stock->high_price = high_price;
    stock->low_price = low_price;
    stock->previous_close = previous_close;
    return stock;
}

void update_price(Stock *stock, float new_price) {
    stock->previous_close = stock->current_price;
    stock->current_price = new_price;
    if (new_price > stock->high_price) {
        stock->high_price = new_price;
    }
    if (new_price < stock->low_price) {
        stock->low_price = new_price;
    }
}

void print_stock(Stock *stock) {
    printf("%s:\nCurrent Price: %.2f\nOpen Price: %.2f\nHigh Price: %.2f\nLow Price: %.2f\nPrevious Close: %.2f\n",
           stock->stock_name, stock->current_price, stock->open_price, stock->high_price, stock->low_price, stock->previous_close);
}

int main() {
    Stock *aapl = create_stock("AAPL", 128.32, 127.01, 129.96, 126.11, 127.35);
    Stock *goog = create_stock("GOOG", 2127.10, 2125.00, 2128.30, 2105.23, 2123.88);
    Stock *msft = create_stock("MSFT", 243.08, 242.68, 244.91, 242.10, 243.50);

    printf("Initial Stock Prices:\n");
    print_stock(aapl);
    print_stock(goog);
    print_stock(msft);

    printf("\nUpdating AAPL's Price:\n");
    update_price(aapl, 129.00);
    print_stock(aapl);

    printf("\nUpdating GOOG's Price:\n");
    update_price(goog, 2129.50);
    print_stock(goog);

    printf("\nUpdating MSFT's Price:\n");
    update_price(msft, 243.75);
    print_stock(msft);

    return 0;
}