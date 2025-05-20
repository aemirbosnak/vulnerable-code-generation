//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 1024
#define MAX_RESPONSE_LENGTH 1024 * 10

struct url_data {
    char *url;
    int interval;
    time_t last_check;
    time_t next_check;
    char response[MAX_RESPONSE_LENGTH];
    int response_length;
};

void init_curl() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
}

void cleanup_curl() {
    curl_global_cleanup();
}

size_t write_data(void *ptr, size_t size, size_t nmemb, void *userp) {
    struct url_data *data = (struct url_data *)userp;
    size_t new_length = data->response_length + size * nmemb;
    if (new_length >= MAX_RESPONSE_LENGTH) {
        return 0;
    }
    memcpy(&data->response[data->response_length], ptr, size * nmemb);
    data->response_length += size * nmemb;
    return size * nmemb;
}

int check_url(struct url_data *data) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, data->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, data);
        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }

    return res == CURLE_OK? 0 : 1;
}

void print_status(struct url_data *data) {
    time_t now = time(NULL);
    time_t elapsed = now - data->last_check;

    if (elapsed >= data->interval) {
        int result = check_url(data);
        if (result) {
            fprintf(stderr, "Failed to check URL '%s'\n", data->url);
        } else {
            fprintf(stdout, "Checked URL '%s' - response length: %d\n",
                    data->url, data->response_length);
        }
        data->last_check = now;
    } else {
        fprintf(stdout, "Skipping check of URL '%s' (next check in %ld seconds)\n",
                data->url, data->interval - elapsed);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <URL> <interval_in_seconds>\n", argv[0]);
        return 1;
    }

    struct url_data data;
    data.url = strdup(argv[1]);
    data.interval = atoi(argv[2]);
    data.last_check = 0;
    data.next_check = time(NULL) + data.interval;
    data.response_length = 0;

    while (1) {
        sleep(1);
        print_status(&data);
    }

    return 0;
}