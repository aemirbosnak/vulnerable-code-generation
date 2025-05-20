//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX_URL_LEN 512
#define MAX_RESPONSE_LEN 1024

struct url_data {
    char url[MAX_URL_LEN];
    char response[MAX_RESPONSE_LEN];
    int status_code;
};

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    struct url_data* data = (struct url_data*)userp;
    size_t realsize = size * nmemb;
    strncat(data->response, (char*)contents, realsize);
    return realsize;
}

int main(int argc, char** argv) {
    if(argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return -1;
    }

    struct url_data data;
    strcpy(data.url, argv[1]);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    CURL* curl = curl_easy_init();

    if(!curl) {
        printf("Error initializing curl\n");
        return -1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, data.url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);

    CURLcode res = curl_easy_perform(curl);

    if(res!= CURLE_OK) {
        printf("Error performing request: %s\n", curl_easy_strerror(res));
        return -1;
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    printf("URL: %s\n", data.url);
    printf("Response: %s\n", data.response);
    printf("Status Code: %d\n", data.status_code);

    return 0;
}