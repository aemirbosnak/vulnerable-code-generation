//Falcon2-11B DATASET v1.0 Category: Stock market tracker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define some constants
#define MAX_STOCKS 100
#define MAX_TICKERS 10
#define MAX_PRICE 10000

typedef struct stock {
    char ticker[5];
    int price;
    int volume;
} stock;

typedef struct ticker {
    char ticker[5];
    int index;
} ticker;

typedef struct portfolio {
    int size;
    stock *stocks;
    ticker *tickers;
} portfolio;

portfolio create_portfolio(int size) {
    portfolio p;
    p.size = size;
    p.stocks = (stock *)malloc(size * sizeof(stock));
    p.tickers = (ticker *)malloc(size * sizeof(ticker));
    for (int i = 0; i < size; i++) {
        p.stocks[i].price = 0;
        p.stocks[i].volume = 0;
        p.tickers[i].index = -1;
    }
    return p;
}

void update_stock_price(stock *stock, int price) {
    stock->price = price;
}

void update_stock_volume(stock *stock, int volume) {
    stock->volume = volume;
}

void add_ticker(ticker *tickers, char *ticker) {
    if (tickers->index == -1) {
        tickers->index = 0;
    } else {
        tickers->index = tickers->index + 1;
    }
    strcpy(tickers->ticker, ticker);
}

void add_stock(portfolio *portfolio, char *ticker, int price, int volume) {
    if (portfolio->size == 0) {
        portfolio->stocks[0].ticker[0] = ticker[0];
        portfolio->stocks[0].ticker[1] = ticker[1];
        portfolio->stocks[0].ticker[2] = ticker[2];
        portfolio->stocks[0].ticker[3] = ticker[3];
        portfolio->stocks[0].ticker[4] = '\0';
        portfolio->stocks[0].price = price;
        portfolio->stocks[0].volume = volume;
        add_ticker(&portfolio->tickers[0], portfolio->stocks[0].ticker);
        return;
    }

    for (int i = 0; i < portfolio->size; i++) {
        if (strcmp(portfolio->stocks[i].ticker, ticker) == 0) {
            update_stock_price(&portfolio->stocks[i], price);
            update_stock_volume(&portfolio->stocks[i], volume);
            return;
        }
    }

    if (portfolio->size == (MAX_STOCKS - 1)) {
        printf("portfolio is full, cannot add more stocks\n");
        return;
    }

    if (portfolio->size == 0) {
        portfolio->stocks[0].ticker[0] = ticker[0];
        portfolio->stocks[0].ticker[1] = ticker[1];
        portfolio->stocks[0].ticker[2] = ticker[2];
        portfolio->stocks[0].ticker[3] = ticker[3];
        portfolio->stocks[0].ticker[4] = '\0';
        portfolio->stocks[0].price = price;
        portfolio->stocks[0].volume = volume;
        add_ticker(&portfolio->tickers[0], portfolio->stocks[0].ticker);
        return;
    }

    for (int i = 0; i < portfolio->size; i++) {
        if (strcmp(portfolio->stocks[i].ticker, portfolio->tickers[i].ticker) == 0) {
            add_stock(&portfolio->stocks[i], ticker, price, volume);
            return;
        }
    }

    printf("ticker not found, cannot add stock\n");
}

void print_portfolio(portfolio *portfolio) {
    for (int i = 0; i < portfolio->size; i++) {
        printf("ticker: %s, price: %d, volume: %d\n", portfolio->stocks[i].ticker, portfolio->stocks[i].price, portfolio->stocks[i].volume);
    }
}

int main() {
    srand(time(0));
    portfolio p = create_portfolio(5);

    for (int i = 0; i < 10; i++) {
        char ticker[5];
        int price = rand() % MAX_PRICE;
        int volume = rand() % 100;
        strcpy(ticker, "aaa");
        strcat(ticker, "bbb");
        strcat(ticker, "ccc");
        strcat(ticker, "ddd");
        strcat(ticker, "eee");
        strcat(ticker, "fff");
        add_stock(&p, ticker, price, volume);
    }

    print_portfolio(&p);

    return 0;
}