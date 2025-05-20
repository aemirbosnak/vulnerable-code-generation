//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

#define URL_LENGTH 256
#define LOG_FILE "uptime_log.txt"
#define MAX_URLS 10
#define TIMEOUT_SECONDS 5
#define INTERVAL_SECONDS 10

typedef struct {
    char urls[MAX_URLS][URL_LENGTH];
    int url_count;
} UptimeMonitor;

size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata) {
    // Write callback to discard the fetched data
    return size * nmemb;
}

void log_status(const char *url, int is_up) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file) {
        fprintf(log_file, "%s - %s\n", url, is_up ? "UP" : "DOWN");
        fclose(log_file);
    }
}

int check_website(const char *url) {
    CURL *curl;
    CURLcode res;
    int is_up = 0;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT_SECONDS);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        
        res = curl_easy_perform(curl);
        
        if (res == CURLE_OK) {
            is_up = 1;  // The website is reachable
        }
        curl_easy_cleanup(curl);
    }
    return is_up;
}

void init_uptime_monitor(UptimeMonitor *monitor) {
    monitor->url_count = 0;
}

void add_url(UptimeMonitor *monitor, const char *url) {
    if (monitor->url_count < MAX_URLS) {
        strncpy(monitor->urls[monitor->url_count], url, URL_LENGTH);
        monitor->url_count++;
    } else {
        fprintf(stderr, "Max URL limit reached!\n");
    }
}

void monitor_websites(const UptimeMonitor *monitor) {
    while (1) {
        for (int i = 0; i < monitor->url_count; i++) {
            int status = check_website(monitor->urls[i]);
            log_status(monitor->urls[i], status);
            printf("Checked %s - Status: %s\n", monitor->urls[i], status ? "UP" : "DOWN");
        }
        sleep(INTERVAL_SECONDS);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <url1> <url2> ... <urlN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    UptimeMonitor monitor;
    init_uptime_monitor(&monitor);

    for (int i = 1; i < argc && i <= MAX_URLS; i++) {
        add_url(&monitor, argv[i]);
    }

    printf("Starting Uptime Monitor for %d URLs...\n", monitor.url_count);
    monitor_websites(&monitor);
    
    return EXIT_SUCCESS;
}