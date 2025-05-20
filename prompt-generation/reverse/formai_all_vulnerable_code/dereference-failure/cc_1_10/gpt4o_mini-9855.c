//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>
#include <pthread.h>

#define MAX_URLS 100
#define MAX_LENGTH 256
#define CHECK_INTERVAL 10

typedef struct {
    char url[MAX_LENGTH];
    int status_code;
} URLMonitor;

URLMonitor monitors[MAX_URLS];
int monitor_count = 0;
pthread_mutex_t lock;

void* check_url(void* arg) {
    URLMonitor* monitor = (URLMonitor*)arg;
    CURL* curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, monitor->url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We don't need the body

        // Perform the request, res will get the return code
        res = curl_easy_perform(curl);

        // Check if any error occurred
        if(res != CURLE_OK) {
            printf("Failed to reach %s: %s\n", monitor->url, curl_easy_strerror(res));
        } else {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            pthread_mutex_lock(&lock);
            monitor->status_code = response_code;
            pthread_mutex_unlock(&lock);
            printf("Status of %s: %ld\n", monitor->url, response_code);
        }

        // Cleanup
        curl_easy_cleanup(curl);
    }
    return NULL;
}

void monitor_urls() {
    while (1) {
        pthread_t threads[MAX_URLS];

        for (int i = 0; i < monitor_count; i++) {
            if (pthread_create(&threads[i], NULL, check_url, &monitors[i])) {
                fprintf(stderr, "Error creating thread for %s\n", monitors[i].url);
            }
        }

        // Wait for all threads to finish
        for (int i = 0; i < monitor_count; i++) {
            pthread_join(threads[i], NULL);
        }

        printf("Checking again in %d seconds...\n", CHECK_INTERVAL);
        sleep(CHECK_INTERVAL);
    }
}

void add_url(const char* url) {
    if (monitor_count < MAX_URLS) {
        strncpy(monitors[monitor_count].url, url, MAX_LENGTH);
        monitors[monitor_count].status_code = -1; // Default
        monitor_count++;
    } else {
        printf("Maximum number of URLs reached.\n");
    }
}

int main(int argc, char* argv[]) {
    pthread_mutex_init(&lock, NULL);
    
    if (argc < 2) {
        printf("Usage: %s <url1> [<url2> ...]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        add_url(argv[i]);
    }

    monitor_urls();

    pthread_mutex_destroy(&lock);
    return 0;
}