//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <pthread.h>

typedef struct {
    char *url;
    int interval;
    int timeout;
    int max_retries;
    int retries;
    time_t last_check;
    time_t next_check;
    int is_up;
} website_t;

typedef struct {
    website_t *website;
    pthread_t thread;
} thread_data_t;

void *monitor_website(void *data);
int is_website_up(const char *url);

int main(int argc, char *argv[]) {
    if (argc!= 6) {
        printf("Usage: %s <url> <interval> <timeout> <max_retries> <retries>\n", argv[0]);
        return 1;
    }

    website_t website = {
       .url = argv[1],
       .interval = atoi(argv[2]),
       .timeout = atoi(argv[3]),
       .max_retries = atoi(argv[4]),
       .retries = 0,
       .last_check = 0,
       .next_check = 0,
       .is_up = 0
    };

    thread_data_t thread_data = {
       .website = &website,
       .thread = 0
    };

    pthread_create(&thread_data.thread, NULL, monitor_website, &thread_data);

    while (1) {
        sleep(1);
    }

    return 0;
}

void *monitor_website(void *data) {
    thread_data_t *thread_data = data;
    website_t *website = thread_data->website;

    while (1) {
        time_t now = time(NULL);

        if (now >= website->next_check) {
            website->is_up = is_website_up(website->url);

            if (website->is_up) {
                website->retries = 0;
            } else {
                website->retries++;

                if (website->retries >= website->max_retries) {
                    printf("Website %s is down\n", website->url);
                }
            }

            website->last_check = now;
            website->next_check = now + website->interval;
        }

        sleep(1);
    }
}

int is_website_up(const char *url) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5);

        res = curl_easy_perform(curl);

        if (res == CURLE_OK) {
            return 1;
        }
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}