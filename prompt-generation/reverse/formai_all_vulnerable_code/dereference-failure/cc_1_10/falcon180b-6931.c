//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URL_LENGTH 1000
#define MAX_RESPONSE_LENGTH 100000

struct url_data {
    char url[MAX_URL_LENGTH];
    char response[MAX_RESPONSE_LENGTH];
    time_t last_check;
};

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
    struct url_data *url_data = (struct url_data *) stream;
    if (url_data->last_check == 0) {
        url_data->last_check = time(NULL);
    }
    strncat(url_data->response, (char *) ptr, size * nmemb);
    return size * nmemb;
}

int main(int argc, char *argv[]) {
    CURL *curl;
    FILE *file;
    char buffer[MAX_URL_LENGTH];
    struct url_data url_data;

    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    strcpy(url_data.url, argv[1]);
    strcpy(url_data.response, "");
    url_data.last_check = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url_data.url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &url_data);

        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    file = fopen("urls.txt", "a");
    fprintf(file, "%s\n", url_data.url);
    fclose(file);

    return 0;
}