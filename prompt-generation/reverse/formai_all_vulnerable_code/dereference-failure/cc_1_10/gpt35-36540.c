//FormAI DATASET v1.0 Category: Stock market tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

#define BASE_URL "https://api.iextrading.com/1.0/stock/"
#define STOCK_SYMBOL "AAPL"
#define REFRESH_INTERVAL 5 // in seconds

typedef struct {
    double current_price;
    double change_percent;
    double day_low;
    double day_high;
} stock_info;

static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    return size * nmemb;
}

static void get_stock_info(char *url, stock_info *info) {
    CURL *curl = curl_easy_init();
    CURLcode res;
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        char error_buffer[CURL_ERROR_SIZE];
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, error_buffer);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            printf("Error: %s\n", error_buffer);
            curl_easy_cleanup(curl);
            return;
        }

        char *resp = NULL;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &resp);

        if (resp && strcmp(resp, "200")) {
            printf("Error: couldn't fetch data, stock symbol may not exist.\n");
            curl_easy_cleanup(curl);
            return;
        }

        double current_price, change, day_low, day_high;

        curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &resp);
        if (strstr(resp, "text/html") == NULL) { // check if the response is not HTML
            curl_easy_getinfo(curl, CURLINFO_PRIVATE, &current_price);
            curl_easy_getinfo(curl, CURLINFO_PRIVATE + 1, &change);
            curl_easy_getinfo(curl, CURLINFO_PRIVATE + 2, &day_low);
            curl_easy_getinfo(curl, CURLINFO_PRIVATE + 3, &day_high);
        }

        info->current_price = current_price;
        info->change_percent = change;
        info->day_low = day_low;
        info->day_high = day_high;

        curl_easy_cleanup(curl);
    }
}

static void display_stock_info(stock_info *info) {
    printf("Current Price: %.2f\n", info->current_price);
    printf("Percent Change: %.2f%%\n", info->change_percent);
    printf("Day Low: %.2f\n", info->day_low);
    printf("Day High: %.2f\n", info->day_high);
}

int main() {
    char url[128];
    snprintf(url, sizeof url, "%s%s/quote?displayPercent=true", BASE_URL, STOCK_SYMBOL);

    stock_info info;
    get_stock_info(url, &info);
    display_stock_info(&info);

    while (1) {
        get_stock_info(url, &info);
        display_stock_info(&info);
        sleep(REFRESH_INTERVAL);
    }

    return 0;
}