//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define URL_SIZE 256
#define STATUS_OK 200

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    return size * nmemb;
}

int main(int argc, char* argv[])
{
    CURL *curl_handle;
    CURLcode res;
    char url[URL_SIZE];
    long http_code;

    if(argc < 2 || argc > 3) {
        fprintf(stderr, "Usage: %s <url> [interval in seconds]\n", argv[0]);
        return EXIT_FAILURE;
    }

    strncpy(url, argv[1], URL_SIZE);
    url[URL_SIZE-1] = '\0';

    curl_global_init(CURL_GLOBAL_ALL);

    curl_handle = curl_easy_init();
    curl_easy_setopt(curl_handle, CURLOPT_URL, url);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);

    do {
        if((res = curl_easy_perform(curl_handle)) != CURLE_OK) {
            fprintf(stderr, "Could not reach url %s: %s", url, curl_easy_strerror(res));
        } else {
            res = curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &http_code);
            if(res != CURLE_OK) {
                fprintf(stderr, "Could not get response code for url %s: %s", url, curl_easy_strerror(res));
            } else if(http_code != STATUS_OK) {
                fprintf(stderr, "Http code for url %s: %ld", url, http_code);
            } else {
                printf("Url %s is up and running...\n", url);
            }
        }
        if(argc == 3) {
            int interval = atoi(argv[2]);
            if(interval > 0) {
                sleep(interval);
            }
        }
    } while(argc == 3); // exit loop if no interval arg provided

    curl_easy_cleanup(curl_handle);
    curl_global_cleanup();
    return EXIT_SUCCESS;
}