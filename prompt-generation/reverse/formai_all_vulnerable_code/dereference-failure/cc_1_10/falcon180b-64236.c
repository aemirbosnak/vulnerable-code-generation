//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LEN 1024
#define MAX_RESPONSE_LEN 1024

int is_url_up(const char* url);
size_t write_data(void* buffer, size_t size, size_t nmemb, void* userp);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char url[MAX_URL_LEN];
    strcpy(url, argv[1]);

    if (is_url_up(url)) {
        printf("%s is up.\n", url);
    } else {
        printf("%s is down.\n", url);
    }

    return 0;
}

int is_url_up(const char* url) {
    CURL* curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Failed to initialize curl.\n");
        return 0;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &res);

    res = curl_easy_perform(curl);
    if (res!= CURLE_OK) {
        fprintf(stderr, "Failed to perform curl request: %s\n",
                curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        return 0;
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return res == CURLE_OK? 1 : 0;
}

size_t write_data(void* buffer, size_t size, size_t nmemb, void* userp) {
    char* response = (char*)malloc(MAX_RESPONSE_LEN);
    memset(response, 0, MAX_RESPONSE_LEN);

    strncat(response, (char*)buffer, size * nmemb);

    printf("%s", response);

    free(response);

    return size * nmemb;
}