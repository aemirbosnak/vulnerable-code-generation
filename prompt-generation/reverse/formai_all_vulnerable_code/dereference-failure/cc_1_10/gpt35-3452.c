//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 100
#define MAX_NAME_LENGTH 50
#define MAX_NUM_MONITORS 10

typedef struct {
    char url[MAX_URL_LENGTH];
    char name[MAX_NAME_LENGTH];
    int interval;
} Monitor;

char* get_timestamp() {
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    char* timestamp = asctime(tm);
    timestamp[strlen(timestamp)-1] = '\0'; // Remove newline character
    return timestamp;
}

int is_url_up(const char* url) {
    CURL *curl;
    CURLcode res;
    int is_up = 0;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            long response_code;
            res = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            if((res == CURLE_OK) && (response_code == 200)) {
                is_up = 1;
            }
        }
        curl_easy_cleanup(curl);
    }
    return is_up;
}

void print_monitor_status(const char* name, int is_up, const char* timestamp) {
    printf("[%s] %s is %s\n", timestamp, name, (is_up ? "up" : "down"));
}

int main() {
    Monitor monitors[MAX_NUM_MONITORS] = {
        {.url = "https://example.com", .name = "Example Monitor", .interval = 60},
        // Add more monitors here
    };
    int num_monitors = sizeof(monitors) / sizeof(monitors[0]);

    CURLcode res = curl_global_init(CURL_GLOBAL_ALL);
    if(res != CURLE_OK) {
        fprintf(stderr, "Error initializing curl: %s\n", curl_easy_strerror(res));
        return 1;
    }

    while(1) {
        char* timestamp = get_timestamp();
        for(int i = 0; i < num_monitors; i++) {
            Monitor curr_monitor = monitors[i];
            if(is_url_up(curr_monitor.url)) {
                print_monitor_status(curr_monitor.name, 1, timestamp);
            } else {
                print_monitor_status(curr_monitor.name, 0, timestamp);
            }
        }
        free(timestamp);
        sleep(60); // Check monitors every minute
    }

    curl_global_cleanup();
    return 0;
}