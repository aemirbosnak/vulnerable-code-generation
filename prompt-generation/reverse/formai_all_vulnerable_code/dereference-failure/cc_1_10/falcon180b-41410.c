//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_URL_LEN 1024
#define MAX_RESPONSE_LEN 8192

int is_url_up(const char* url);
size_t write_data(void* buffer, size_t size, size_t nmemb, void* userp);

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char url[MAX_URL_LEN];
    strncpy(url, argv[1], MAX_URL_LEN);

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

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);

        res = curl_easy_perform(curl);

        if (res == CURLE_OK) {
            return 1;
        } else {
            return 0;
        }
    }

    return 0;
}

size_t write_data(void* buffer, size_t size, size_t nmemb, void* userp) {
    return size * nmemb;
}