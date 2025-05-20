//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URLS 100
#define URL_LENGTH 256

typedef struct {
    char url[URL_LENGTH];
    int status_code;
    time_t last_checked;
} UptimeMonitor;

// Function to initialize uptime monitor
void initialize_monitor(UptimeMonitor *monitor, const char *url) {
    strncpy(monitor->url, url, URL_LENGTH);
    monitor->status_code = 0;
    monitor->last_checked = 0;
}

// Function to perform an HTTP request and check uptime
int check_uptime(const char *url) {
    CURL *curl;
    CURLcode res;
    long response_code;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1);  // HEAD request
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            curl_easy_cleanup(curl);
            return -1; // Error occurred
        }
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        curl_easy_cleanup(curl);
        return (int)response_code;
    }
    return -1; // curl initialization failed
}

// Function to print the status of a URL
void print_status(UptimeMonitor *monitor) {
    printf("URL: %s, Status code: %d, Last checked: %s", 
           monitor->url, 
           monitor->status_code, 
           ctime(&(monitor->last_checked)));
}

// Function to monitor the websites
void monitor_websites(UptimeMonitor *monitors, int count, int interval) {
    while (1) {
        for (int i = 0; i < count; i++) {
            monitors[i].status_code = check_uptime(monitors[i].url);
            monitors[i].last_checked = time(NULL);
            print_status(&monitors[i]);
        }
        sleep(interval);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <interval_seconds> <url1> <url2> ... <urlN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int interval = atoi(argv[1]);
    if (interval <= 0) {
        fprintf(stderr, "Interval must be a positive integer.\n");
        return EXIT_FAILURE;
    }

    UptimeMonitor monitors[MAX_URLS];
    int url_count = argc - 2;

    // Initialize monitors with URLs from command line arguments
    for (int i = 0; i < url_count && i < MAX_URLS; i++) {
        initialize_monitor(&monitors[i], argv[i + 2]);
    }

    // Start monitoring websites
    monitor_websites(monitors, url_count, interval);

    return EXIT_SUCCESS;
}