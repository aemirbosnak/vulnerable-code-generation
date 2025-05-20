//Falcon2-11B DATASET v1.0 Category: Stock market tracker ; Style: interoperable
#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *data)
{
    size_t written = fwrite(ptr, size, nmemb, data);
    if (written!= size * nmemb) {
        fprintf(stderr, "Error writing data\n");
        return -1;
    }
    return written;
}

static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userdata)
{
    size_t written = write_data(contents, size, nmemb, userdata);
    return written;
}

int main(int argc, char *argv[])
{
    CURL *curl;
    CURLcode res;
    FILE *fp;
    char buffer[1024];
    char *stock_symbol = "AAPL";
    char *url = "http://ichart.finance.yahoo.com/table.csv?s=%s&a=00&b=1&c=2012&d=09&e=30&f=2012&g=d&ignore=.csv";

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <stock_symbol>\n", argv[0]);
        return 1;
    }

    stock_symbol = argv[1];

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, (const char *)url);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            return 1;
        }
        fclose(stdout);
        curl_easy_cleanup(curl);
        return 0;
    }

    fprintf(stderr, "Failed to initialize libcurl\n");
    return 1;
}