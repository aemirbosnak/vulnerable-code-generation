//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <unistd.h>
#include <time.h>

#define MAX_URL_LEN 256
#define CHECK_INTERVAL 5 // Interval in seconds
#define MAX_CHECKS 10 // Maximum number of checks to perform

typedef struct {
    char url[MAX_URL_LEN];
    int total_checks;
    int downtime;
    int uptime;
} UptimeMonitor;

size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata) {
    return size * nmemb;  // Ignore the response data
}

// Function to check if the website is up
int is_website_up(const char *url) {
    CURL *curl;
    CURLcode res;
    int up = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L); // Set timeout for connection
        res = curl_easy_perform(curl);

        // Check if the request was successful (HTTP response code 200-299)
        if(res == CURLE_OK) {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            if(response_code >= 200 && response_code < 300) {
                up = 1; // website is up
            }
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

    return up;
}

// Function to log the uptime statistics
void log_statistics(UptimeMonitor *monitor) {
    printf("URL: %s\n", monitor->url);
    printf("Total checks: %d\n", monitor->total_checks);
    printf("Uptime: %d (%d%%)\n", monitor->uptime, (monitor->uptime * 100) / monitor->total_checks);
    printf("Downtime: %d\n", monitor->downtime);
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }

    UptimeMonitor monitor;
    strncpy(monitor.url, argv[1], MAX_URL_LEN);
    monitor.total_checks = 0;
    monitor.downtime = 0;
    monitor.uptime = 0;

    printf("Starting uptime monitor for %s\n", monitor.url);
    for(int i = 0; i < MAX_CHECKS; i++) {
        int result = is_website_up(monitor.url);
        monitor.total_checks++;

        if(result) {
            printf("Check %d: %s is UP\n", monitor.total_checks, monitor.url);
            monitor.uptime++;
        } else {
            printf("Check %d: %s is DOWN\n", monitor.total_checks, monitor.url);
            monitor.downtime++;
        }

        sleep(CHECK_INTERVAL);
    }

    log_statistics(&monitor);
    return EXIT_SUCCESS;
}