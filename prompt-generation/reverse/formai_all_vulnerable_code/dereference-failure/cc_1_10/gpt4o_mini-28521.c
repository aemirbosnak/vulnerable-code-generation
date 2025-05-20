//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>
#include <pthread.h>

#define MAX_URLS 100
#define TIMEOUT 5
#define CHECK_INTERVAL 10

typedef struct {
    char url[256];
    int status; // 0: down, 1: up
} Website;

typedef struct {
    Website websites[MAX_URLS];
    int count;
    pthread_mutex_t lock;
} Monitor;

void* check_website(void* arg) {
    Monitor *monitor = (Monitor*)arg;
    CURL *curl;
    CURLcode res;

    for (int i = 0; i < monitor->count; i++) {
        pthread_mutex_lock(&monitor->lock);
        Website *website = &monitor->websites[i];
        pthread_mutex_unlock(&monitor->lock);

        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, website->url);
            curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
            curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
            res = curl_easy_perform(curl);
            if (res == CURLE_OK) {
                website->status = 1; // website is up
            } else {
                website->status = 0; // website is down
            }
            curl_easy_cleanup(curl);
        }
    }
    return NULL;
}

void print_status(Monitor *monitor) {
    while (1) {
        sleep(CHECK_INTERVAL);
        pthread_mutex_lock(&monitor->lock);
        for (int i = 0; i < monitor->count; i++) {
            Website *website = &monitor->websites[i];
            printf("Website: %s - Status: %s\n", website->url, website->status ? "UP" : "DOWN");
        }
        pthread_mutex_unlock(&monitor->lock);
        printf("---------------------------------------\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <url1> <url2> ... <urlN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Monitor monitor;
    monitor.count = argc - 1;
    pthread_mutex_init(&monitor.lock, NULL);

    for (int i = 0; i < monitor.count; i++) {
        strncpy(monitor.websites[i].url, argv[i + 1], sizeof(monitor.websites[i].url));
        monitor.websites[i].status = -1; // Initialize status as unknown
    }

    pthread_t check_thread;
    pthread_create(&check_thread, NULL, check_website, &monitor);
    
    print_status(&monitor);

    pthread_join(check_thread, NULL);
    pthread_mutex_destroy(&monitor.lock);
    return EXIT_SUCCESS;
}