//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URLS 10
#define MAX_LENGTH 256
#define TIME_INTERVAL 5

typedef struct {
    char url[MAX_LENGTH];
    int status_code;
    time_t last_checked;
} UrlMonitor;

void check_url(UrlMonitor *monitor) {
    CURL *curl;
    CURLcode res;
    long response_code;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, monitor->url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); /* We're only interested in headers */
        res = curl_easy_perform(curl);
        
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            monitor->status_code = -1;  // Indicate connection failure
        } else {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            monitor->status_code = response_code;
        }
        
        monitor->last_checked = time(NULL);
        curl_easy_cleanup(curl);
    }
}

void print_report(const UrlMonitor *monitor) {
    char time_buf[26];
    struct tm* tm_info;

    tm_info = localtime(&monitor->last_checked);
    strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S", tm_info);

    if (monitor->status_code == -1) {
        printf("URL '%s' could not be reached. Last checked at: %s\n", monitor->url, time_buf);
    } else {
        printf("URL '%s' responded with code %d. Last checked at: %s\n", monitor->url, monitor->status_code, time_buf);
    }
}

int main(int argc, char *argv[]) {
    UrlMonitor monitors[MAX_URLS];
    int monitor_count = 0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <url1> <url2> ... <urlN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc && i <= MAX_URLS; i++) {
        strncpy(monitors[monitor_count].url, argv[i], MAX_LENGTH);
        monitors[monitor_count].status_code = 0;
        monitors[monitor_count].last_checked = 0;
        monitor_count++;
    }

    printf("Starting the URL uptime monitor...\n");

    while (1) {
        for (int i = 0; i < monitor_count; i++) {
            check_url(&monitors[i]);
            print_report(&monitors[i]);
        }
        sleep(TIME_INTERVAL);
    }

    return EXIT_SUCCESS;
}