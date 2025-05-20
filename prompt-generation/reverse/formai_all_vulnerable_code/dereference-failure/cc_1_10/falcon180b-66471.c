//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

#define MAX_URL_LENGTH 1024
#define MAX_RESPONSE_LENGTH 1024*1024

struct url_data {
    char url[MAX_URL_LENGTH];
    int response_code;
    char response[MAX_RESPONSE_LENGTH];
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    struct url_data *data = (struct url_data*)userp;
    strncat(data->response, (char*)contents, size*nmemb);
    return size*nmemb;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        struct url_data data;
        strcpy(data.url, argv[1]);
        data.response_code = 0;
        data.response[0] = '\0';

        curl_easy_setopt(curl, CURLOPT_URL, data.url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);

        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            printf("Response code: %d\n", data.response_code);
            printf("Response:\n%s\n", data.response);
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}