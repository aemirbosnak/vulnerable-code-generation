//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URLS 100
#define TIME_INTERVAL 10
#define USER_AGENT "Mozilla/5.0 (compatible; UptimeMonitor/1.0; +https://www.example.com)"

typedef struct {
    char *url;
    int status;
    time_t last_checked;
} Monitor;

void init_monitor(Monitor *monitor, const char *url) {
    monitor->url = strdup(url);
    monitor->status = -1; // -1 means not checked yet
    monitor->last_checked = time(NULL);
}

void cleanup_monitor(Monitor *monitor) {
    free(monitor->url);
}

size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    return size * nmemb; // We ignore the response body
}

int check_url(Monitor *monitor) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, monitor->url);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, USER_AGENT);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        
        res = curl_easy_perform(curl);
        
        // Get HTTP response code
        long http_code = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
        monitor->status = (int)http_code;

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    
    monitor->last_checked = time(NULL);
    return monitor->status;
}

void print_status(Monitor *monitor) {
    // Print the status of the monitor
    if (monitor->status == 200) {
        printf("[UP] %s is reachable (Last checked: %s)", monitor->url, ctime(&monitor->last_checked));
    } else {
        printf("[DOWN] %s is not reachable (Status code: %d, Last checked: %s)", monitor->url, monitor->status, ctime(&monitor->last_checked));
    }
}

int main(int argc, char *argv[]) {
    Monitor monitors[MAX_URLS];
    int monitor_count = 0;
    
    if(argc < 2) {
        fprintf(stderr, "Usage: %s <url1> <url2> ... <urlN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    for(int i = 1; i < argc && monitor_count < MAX_URLS; i++) {
        init_monitor(&monitors[monitor_count], argv[i]);
        monitor_count++;
    }

    while(1) {
        for(int i = 0; i < monitor_count; i++) {
            int status = check_url(&monitors[i]);
            print_status(&monitors[i]);
        }
        printf("Sleeping for %d seconds...\n", TIME_INTERVAL);
        sleep(TIME_INTERVAL);
    }

    for(int i = 0; i < monitor_count; i++) {
        cleanup_monitor(&monitors[i]);
    }

    return EXIT_SUCCESS;
}