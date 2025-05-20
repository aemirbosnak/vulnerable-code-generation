//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>

#define MAX_URL_LEN 512
#define TIMEOUT 5
#define CHECK_INTERVAL 60

struct url_data {
    char url[MAX_URL_LEN];
    int is_up;
};

void *check_url(void *arg) {
    struct url_data *data = (struct url_data *) arg;
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, data->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);

        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            printf("Failed to check URL '%s': %s\n", data->url, curl_easy_strerror(res));
        } else {
            data->is_up = 1;
        }

        curl_easy_cleanup(curl);
    }

    return NULL;
}

int main() {
    int num_urls;
    struct url_data *urls;
    pthread_t threads[MAX_URL_LEN];

    printf("Enter the number of URLs to monitor: ");
    scanf("%d", &num_urls);

    urls = (struct url_data *) malloc(num_urls * sizeof(struct url_data));

    for (int i = 0; i < num_urls; i++) {
        printf("Enter URL %d: ", i+1);
        scanf("%s", urls[i].url);
        urls[i].is_up = 0;
    }

    for (int i = 0; i < num_urls; i++) {
        pthread_create(&threads[i], NULL, check_url, (void *) &urls[i]);
    }

    for (int i = 0; i < num_urls; i++) {
        pthread_join(threads[i], NULL);
    }

    while (1) {
        sleep(CHECK_INTERVAL);

        for (int i = 0; i < num_urls; i++) {
            if (!urls[i].is_up) {
                printf("URL '%s' is down\n", urls[i].url);
            }
        }
    }

    return 0;
}