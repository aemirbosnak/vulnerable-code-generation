//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>

#define NUM_THREADS 4

// The data structure to store the stock information
typedef struct {
    char *symbol;
    double price;
    double change;
} Stock;

// The list of stocks to track
Stock stocks[] = {
    {"AAPL", 0.0, 0.0},
    {"GOOG", 0.0, 0.0},
    {"AMZN", 0.0, 0.0},
    {"TSLA", 0.0, 0.0},
    {"NFLX", 0.0, 0.0}
};

// The number of stocks to track
#define NUM_STOCKS (sizeof(stocks) / sizeof(Stock))

// Function to get the stock price from the Yahoo Finance API
static double get_stock_price(const char *symbol) {
    // The URL of the Yahoo Finance API endpoint
    char url[256];
    snprintf(url, sizeof(url), "https://query1.finance.yahoo.com/v7/finance/quote?symbols=%s", symbol);

    // The buffer to store the response from the API
    char buffer[1024];

    // The curl object to make the request
    CURL *curl = curl_easy_init();

    // Set the URL of the request
    curl_easy_setopt(curl, CURLOPT_URL, url);

    // Set the buffer to store the response
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

    // Make the request
    CURLcode res = curl_easy_perform(curl);

    // Check for errors
    if (res != CURLE_OK) {
        fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
        return -1.0;
    }

    // Parse the response to get the stock price
    double price = 0.0;
    char *start = strstr(buffer, "\"regularMarketPrice\":");
    if (start != NULL) {
        start += strlen("\"regularMarketPrice\":");
        char *end = strchr(start, ',');
        if (end != NULL) {
            *end = '\0';
            price = atof(start);
        }
    }

    // Cleanup
    curl_easy_cleanup(curl);

    // Return the stock price
    return price;
}

// Thread function to track a stock
void *track_stock(void *arg) {
    // Get the stock symbol
    const char *symbol = (const char *)arg;

    // Get the current stock price
    double price = get_stock_price(symbol);

    // Update the stock information
    for (int i = 0; i < NUM_STOCKS; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            stocks[i].price = price;
            stocks[i].change = price - stocks[i].price;
            break;
        }
    }

    return NULL;
}

int main() {
    // Create the threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_STOCKS; i++) {
        pthread_create(&threads[i], NULL, track_stock, (void *)stocks[i].symbol);
    }

    // Join the threads
    for (int i = 0; i < NUM_STOCKS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the stock information
    for (int i = 0; i < NUM_STOCKS; i++) {
        printf("%s: %.2f (%.2f%%)\n", stocks[i].symbol, stocks[i].price, stocks[i].change);
    }

    return 0;
}