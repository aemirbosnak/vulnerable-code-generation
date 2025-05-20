//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <unistd.h>

#define CHECK_INTERVAL 60 // Check interval in seconds
#define MAX_URL_LENGTH 256 // Maximum URL length
#define MAX_FAILURES 5 // Maximum number of consecutive failures before sending notification

// Global variables
int failures = 0; // Consecutive failures counter

// Function declarations
void check_website(char *);

// Main function
int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char url[MAX_URL_LENGTH];
    strncpy(url, argv[1], MAX_URL_LENGTH-1);
    
    while(1) {
        check_website(url);
        sleep(CHECK_INTERVAL);
    }
    
    exit(EXIT_SUCCESS);
}

// Function to check website
void check_website(char *url) {
    CURL *curl;
    CURLcode res;
    long http_code;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            failures++;
        } else {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);

            if(http_code != 200) {
                fprintf(stderr, "HTTP error code: %ld\n", http_code);
                failures++;
            } else {
                printf("Website is up!\n");
                failures = 0;
            }
        }

        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Failed to initialize curl\n");
        failures++;
    }

    if(failures >= MAX_FAILURES) {
        printf("Website is down! Sending notification...\n");

        // Insert code to send notification here

        failures = 0;
    }

    curl_global_cleanup();
}