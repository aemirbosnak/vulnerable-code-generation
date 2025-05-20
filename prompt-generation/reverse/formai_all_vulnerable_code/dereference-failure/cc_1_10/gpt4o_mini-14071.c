//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_WEBSITES 10
#define TIME_INTERVAL 5  // Time interval between checks in seconds

typedef struct {
    char url[256];
    int status; // 1 for up, 0 for down
} Website;

Website websites[MAX_WEBSITES];
int website_count = 0;

void* monitor_website(void* arg) {
    Website* website = (Website*)arg;
    CURL* curl;
    CURLcode res;

    while (1) {
        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, website->url);
            curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // Don't fetch the body
            res = curl_easy_perform(curl);
            if (res == CURLE_OK) {
                website->status = 1; // Website is up
            } else {
                website->status = 0; // Website is down
            }
            curl_easy_cleanup(curl);
        }
        sleep(TIME_INTERVAL);
    }
    return NULL;
}

void print_status() {
    while (1) {
        printf("\033[H\033[J"); // Clear the terminal
        printf("Website Uptime Monitor\n");
        printf("========================\n");
        for (int i = 0; i < website_count; i++) {
            printf("%s is %s\n", websites[i].url, websites[i].status ? "UP" : "DOWN");
        }
        sleep(TIME_INTERVAL);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <website1> <website2> ...\n", argv[0]);
        return 1;
    }

    website_count = argc - 1;
    if (website_count > MAX_WEBSITES) {
        fprintf(stderr, "Error: Only a maximum of %d websites can be monitored.\n", MAX_WEBSITES);
        return 1;
    }

    for (int i = 0; i < website_count; i++) {
        strncpy(websites[i].url, argv[i + 1], sizeof(websites[i].url) - 1);
        websites[i].url[sizeof(websites[i].url) - 1] = '\0';
        websites[i].status = 0; // initial status is unknown
    }

    pthread_t threads[MAX_WEBSITES];

    // Create threads to monitor each website
    for (int i = 0; i < website_count; i++) {
        pthread_create(&threads[i], NULL, monitor_website, (void*)&websites[i]);
    }

    // Print status in the main thread
    print_status();

    // Join threads - this point won't be reached due to infinite loops
    for (int i = 0; i < website_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}