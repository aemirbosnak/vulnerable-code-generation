//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <pthread.h>

#define MAX_URL_SIZE 1024
#define MAX_RESPONSE_SIZE 1024 * 100

typedef struct {
    char url[MAX_URL_SIZE];
    char response[MAX_RESPONSE_SIZE];
    time_t last_response_time;
} website_t;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    website_t *website = (website_t *)userp;
    size_t realsize = size * nmemb;
    if (realsize > MAX_RESPONSE_SIZE - strlen(website->response)) {
        realsize = MAX_RESPONSE_SIZE - strlen(website->response);
    }
    memcpy(&website->response[strlen(website->response)], contents, realsize);
    website->response[strlen(website->response)] = '\0';
    return realsize;
}

int CheckWebsite(website_t *website) {
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (!curl) {
        printf("Failed to initialize curl\n");
        return -1;
    }
    curl_easy_setopt(curl, CURLOPT_URL, website->url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, website);
    res = curl_easy_perform(curl);
    if (res!= CURLE_OK) {
        printf("Failed to check website: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        return -1;
    }
    curl_easy_cleanup(curl);
    return 0;
}

void *MonitorThread(void *arg) {
    website_t *website = (website_t *)arg;
    while (1) {
        time_t current_time = time(NULL);
        if (difftime(current_time, website->last_response_time) > 60) {
            int result = CheckWebsite(website);
            if (result == 0) {
                website->last_response_time = current_time;
            } else {
                printf("Website %s is down\n", website->url);
            }
        }
        sleep(60);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <website_url>\n", argv[0]);
        return -1;
    }
    website_t website;
    strcpy(website.url, argv[1]);
    website.last_response_time = 0;
    pthread_t thread_id;
    int result = pthread_create(&thread_id, NULL, MonitorThread, &website);
    if (result!= 0) {
        printf("Failed to create thread: %d\n", result);
        return -1;
    }
    while (1) {
        sleep(60);
    }
    return 0;
}