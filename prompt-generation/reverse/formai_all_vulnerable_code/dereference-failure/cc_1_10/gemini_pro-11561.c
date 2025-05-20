//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
// #define NDEBUG
#include <assert.h>

#define MAX_STOCKS 100

typedef struct {
    char *name;
    char *symbol;
    double price;
} Stock;

Stock *stocks[MAX_STOCKS];
int num_stocks = 0;

void add_stock(char *name, char *symbol, double price) {
    assert(num_stocks < MAX_STOCKS);
    stocks[num_stocks] = malloc(sizeof(Stock));
    stocks[num_stocks]->name = strdup(name);
    stocks[num_stocks]->symbol = strdup(symbol);
    stocks[num_stocks]->price = price;
    num_stocks++;
}

void print_stock(Stock *stock) {
    printf("%s (%s): $%.2f\n", stock->name, stock->symbol, stock->price);
}

void print_all_stocks() {
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }
}

void get_stock_prices() {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.iextrading.com/1.0/stock/market/list/mostactive");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
}

int main() {
    add_stock("Apple Inc.", "AAPL", 123.45);
    add_stock("Microsoft Corporation", "MSFT", 98.76);
    add_stock("Amazon.com, Inc.", "AMZN", 112.34);

    print_all_stocks();

    get_stock_prices();

    print_all_stocks();

    return 0;
}