//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_SIZE 1024
#define MAX_RESPONSE_SIZE 1024 * 10

typedef struct {
    char *url;
    char *response;
    int status_code;
} website_status;

size_t write_response(void *ptr, size_t size, size_t nmemb, void *stream) {
    website_status *status = (website_status *) stream;
    size_t new_size = size * nmemb;

    if (status->response == NULL) {
        status->response = malloc(new_size + 1);
        if (status->response == NULL) {
            return 0;
        }
        status->response[0] = '\0';
    } else {
        status->response = realloc(status->response, new_size + 1);
        if (status->response == NULL) {
            return 0;
        }
    }

    memcpy(status->response + strlen(status->response), ptr, new_size);
    status->response[strlen(status->response) + new_size] = '\0';

    return new_size;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <website_url>\n", argv[0]);
        return 1;
    }

    char url[MAX_URL_SIZE];
    strcpy(url, argv[1]);

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        website_status status = { 0 };
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_response);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &status);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            printf("Error: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            curl_global_cleanup();
            return 1;
        }

        printf("URL: %s\n", status.url);
        printf("Response: %s\n", status.response);
        printf("Status Code: %d\n", status.status_code);

        free(status.response);
        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}