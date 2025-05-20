//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/timeb.h>
#include <time.h>

#define MAX_URL_LEN 1024
#define MAX_RESPONSE_LEN 10240
#define DEFAULT_TIMEOUT 10

struct url_data {
    char url[MAX_URL_LEN];
    char response[MAX_RESPONSE_LEN];
    time_t last_check;
    time_t next_check;
};

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    struct url_data* data = (struct url_data*)userp;
    size_t realsize = size * nmemb;
    if (data->next_check <= time(NULL)) {
        fprintf(stdout, "URL '%s' is down.\n", data->url);
    } else {
        fprintf(stdout, "URL '%s' is up.\n", data->url);
    }
    return realsize;
}

void CheckUrl(struct url_data* data) {
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, data->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, data);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, DEFAULT_TIMEOUT);

        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            fprintf(stderr, "Failed to check URL '%s': %s\n", data->url, curl_easy_strerror(res));
        } else {
            data->last_check = time(NULL);
            data->next_check = data->last_check + 60; // Check every minute
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s URL [timeout]\n", argv[0]);
        return 1;
    }

    struct url_data data;
    strcpy(data.url, argv[1]);
    data.last_check = 0;
    data.next_check = 0;

    if (argc > 2) {
        data.next_check = time(NULL) + atoi(argv[2]);
    } else {
        data.next_check = time(NULL) + DEFAULT_TIMEOUT;
    }

    while (1) {
        sleep(1);
        CheckUrl(&data);
    }

    return 0;
}