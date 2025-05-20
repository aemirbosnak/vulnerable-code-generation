//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <unistd.h>
#include <time.h>

#define URL_MAX_LENGTH 256
#define STATUS_OK "UP"
#define STATUS_DOWN "DOWN"

typedef struct {
    char url[URL_MAX_LENGTH];
    char status[10];
    time_t last_checked;
} Monitor;

void log_status(Monitor *monitor, const char *file_name) {
    FILE *log_file = fopen(file_name, "a");
    if (log_file != NULL) {
        fprintf(log_file, "URL: %s | Status: %s | Last Checked: %s",
                monitor->url, monitor->status, ctime(&(monitor->last_checked)));
        fclose(log_file);
    } else {
        perror("Error opening log file");
    }
}

size_t write_callback(void *ptr, size_t size, size_t nmemb, void *data) {
    // Just discard the response data
    return size * nmemb;
}

void check_url(Monitor *monitor) {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, monitor->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L); // Timeout after 5 seconds

        res = curl_easy_perform(curl);
        monitor->last_checked = time(NULL);

        if(res != CURLE_OK) {
            strcpy(monitor->status, STATUS_DOWN);
        } else {
            long http_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
            if (http_code == 200) {
                strcpy(monitor->status, STATUS_OK);
            } else {
                strcpy(monitor->status, STATUS_DOWN);
            }
        }
        curl_easy_cleanup(curl);
    }
}

void display_status(Monitor *monitor) {
    printf("Monitoring URL: %s\n", monitor->url);
    printf("Current Status: %s\n", monitor->status);
    printf("Last Checked: %s\n", ctime(&(monitor->last_checked)));
}

void setup_monitor(Monitor *monitor, const char *url) {
    strncpy(monitor->url, url, URL_MAX_LENGTH);
    strcpy(monitor->status, STATUS_DOWN);
    monitor->last_checked = time(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <url> [interval]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *url = argv[1];
    int interval = (argc >= 3) ? atoi(argv[2]) : 5; // Default to 5 seconds

    Monitor monitor;
    setup_monitor(&monitor, url);

    printf("Starting uptime monitor for %s with a check interval of %d seconds...\n", monitor.url, interval);

    while (1) {
        check_url(&monitor);
        display_status(&monitor);
        log_status(&monitor, "uptime_log.txt");
        sleep(interval);
    }

    return 0;
}