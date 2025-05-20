//FormAI DATASET v1.0 Category: Stock market tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <math.h>

#define API_KEY "YOUR_API_KEY"
#define STOCK_TICKER "AAPL"
#define QUERY_SIZE 100

typedef struct {
    char *data;
    size_t size;
} MemoryStruct;

// function to write response data to memory
static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    MemoryStruct *mem = (MemoryStruct *)userp;
    mem->data = realloc(mem->data, mem->size + realsize + 1);
    if (mem->data == NULL) {
        printf("Error: Not enough memory (realloc returned NULL)\n");
        return 0;
    }
    memcpy(&(mem->data[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->data[mem->size] = 0;
    return realsize;
}

// function to get stock data using API
int GetStockData(char *query, char *json_output, MemoryStruct *memory_struct) {
    CURL *curl_handle;
    CURLcode res;
    char url[512] = { 0 };
    sprintf(url, "https://www.alphavantage.co/query?function=%s&symbol=%s&apikey=%s", query, STOCK_TICKER, API_KEY);
    curl_global_init(CURL_GLOBAL_ALL);
    curl_handle = curl_easy_init();
    curl_easy_setopt(curl_handle, CURLOPT_URL, url);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)memory_struct);
    res = curl_easy_perform(curl_handle);
    if (res != CURLE_OK) {
        printf("Error: %s\n", curl_easy_strerror(res));
        return -1;
    }
    memcpy(json_output, memory_struct->data, memory_struct->size + 1);
    curl_easy_cleanup(curl_handle);
    curl_global_cleanup();
    return 0;
}

// function to parse JSON string and get stock price
double ParseJSON(char *json) {
    char stock_price[50];
    char *start, *end;
    start = strstr(json, "\"4. close\":");
    if (start != NULL) {
        start += strlen("\"4. close\":");
        end = strchr(start, ',');
        if (end != NULL) {
            strncpy(stock_price, start, end - start);
            return atof(stock_price);
        }
    }
    return 0;
}

// function to display stock price
void DisplayStockPrice(char *query) {
    char json_output[100000];
    MemoryStruct memory_struct = { 0 };
    double stock_price;
    if (GetStockData(query, json_output, &memory_struct) == 0) {
        stock_price = ParseJSON(json_output);
        if (stock_price != 0) {
            printf("Stock price: $%.2f\n", stock_price);
        }
        else {
            printf("Error: Unable to parse JSON\n");
        }
    }
    else {
        printf("Error: Unable to retrieve stock data\n");
    }
}

int main() {
    char query[QUERY_SIZE];
    printf("Welcome to the stock market tracker\n");
    while (1) {
        printf("\nEnter 'quit' to exit or 'help' for available commands:\n");
        fgets(query, QUERY_SIZE, stdin);
        query[strcspn(query, "\n")] = 0;  // remove trailing newline character
        if (strcmp(query, "quit") == 0) {
            break;
        }
        else if (strcmp(query, "help") == 0) {
            printf("\nCommands:\n");
            printf("  price - get current stock price\n");
            printf("  help - display available commands\n");
            printf("  quit - exit program\n");
        }
        else if (strcmp(query, "price") == 0) {
            DisplayStockPrice("TIME_SERIES_DAILY");
        }
        else {
            printf("Error: Invalid command\n");
        }
    }
    return 0;
}