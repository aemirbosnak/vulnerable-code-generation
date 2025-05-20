//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_SIZE 1024
#define MAX_ERROR_SIZE 2048

struct url_data {
    char *url;
    char *error;
    int status_code;
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    char *buffer = (char*)malloc(size * nmemb);
    memcpy(buffer, contents, size * nmemb);
    strcat((char*)userp, buffer);
    free(buffer);
    return size * nmemb;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s URL\n", argv[0]);
        exit(1);
    }

    CURL *curl;
    CURLcode res;
    char *response = NULL;
    struct url_data url_data;

    url_data.url = argv[1];
    url_data.error = (char*)malloc(MAX_ERROR_SIZE);
    url_data.error[0] = '\0';

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url_data.url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &url_data.error);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            url_data.status_code = 0;
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &url_data.status_code);
        }

        curl_easy_cleanup(curl);
    } else {
        url_data.status_code = 0;
        fprintf(stderr, "curl_easy_init() failed\n");
    }

    printf("URL: %s\n", url_data.url);
    printf("Status code: %d\n", url_data.status_code);
    printf("Error: %s\n", url_data.error);

    free(url_data.error);
    curl_global_cleanup();

    return 0;
}