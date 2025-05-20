//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 1024
#define TIMEOUT_SECONDS 30

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    char *data = (char*)malloc(realsize + 1);
    if (data == NULL) {
        printf("Error: Failed to allocate memory.\n");
        return 0;
    }
    memcpy(data, contents, realsize);
    data[realsize] = '\0';
    printf("%s", data);
    free(data);
    return realsize;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char url[MAX_URL_LENGTH];
    strncpy(url, argv[1], MAX_URL_LENGTH);

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT_SECONDS);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            printf("Error: %s\n", curl_easy_strerror(res));
        } else {
            printf("Success\n");
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}