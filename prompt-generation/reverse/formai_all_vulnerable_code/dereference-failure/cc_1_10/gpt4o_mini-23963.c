//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <curl/curl.h>

#define MAX_WEBSITES 10
#define MAX_URL_LENGTH 256
#define TIME_INTERVAL 5 // seconds between checks

typedef struct {
    char url[MAX_URL_LENGTH];
    int status;
} Website;

Website websites[MAX_WEBSITES];
int website_count = 0;

void* check_website(void* arg) {
    Website* site = (Website*)arg;
    CURL* curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, site->url);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We don't need body
        res = curl_easy_perform(curl);

        // Check the response code
        if(res == CURLE_OK) {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            site->status = (response_code >= 200 && response_code < 400) ? 1 : 0; // 1 for UP, 0 for DOWN
        } else {
            site->status = 0; // 0 for DOWN
        }
        curl_easy_cleanup(curl);
    }
    return NULL;
}

void display_status() {
    printf("\nUptime Status:\n");
    printf("---------------------------------------------------\n");
    printf("Website\t\t\tStatus\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < website_count; i++) {
        printf("%-24s\t%s\n", websites[i].url, websites[i].status ? "UP" : "DOWN");
    }
    printf("---------------------------------------------------\n");
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Usage: %s <url1> <url2> ... <urlN>\n", argv[0]);
        return 1;
    }

    // Collect website URLs
    for (int i = 1; i < argc && i <= MAX_WEBSITES; i++) {
        strncpy(websites[i - 1].url, argv[i], MAX_URL_LENGTH);
        websites[i - 1].status = -1; // Initial status unknown
        website_count++;
    }

    while (1) {
        pthread_t threads[MAX_WEBSITES];

        // Create threads to check each website
        for (int i = 0; i < website_count; i++) {
            pthread_create(&threads[i], NULL, check_website, (void*)&websites[i]);
        }

        // Wait for each thread to finish
        for (int i = 0; i < website_count; i++) {
            pthread_join(threads[i], NULL);
        }

        // Display the current status of all websites
        display_status();

        // Wait for the next interval
        sleep(TIME_INTERVAL);
    }

    return 0;
}