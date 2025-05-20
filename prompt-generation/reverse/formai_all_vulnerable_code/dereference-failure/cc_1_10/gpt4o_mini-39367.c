//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <unistd.h>

#define MAX_URLS 100
#define LOG_FILE "uptime_log.txt"
#define INTERVAL 60 // seconds

void log_status(const char *url, int is_up) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (!log_file) {
        perror("Failed to open log file");
        return;
    }
    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0'; // Remove the newline
    fprintf(log_file, "[%s] %s is %s\n", timestamp, url, is_up ? "UP" : "DOWN");
    fclose(log_file);
}

int check_website(const char *url) {
    CURL *curl;
    CURLcode res;
    long response_code;
    
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We don't need body
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L); // 10 seconds timeout

        res = curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

        curl_easy_cleanup(curl);
        
        return (res == CURLE_OK && response_code >= 200 && response_code < 400);
    }
    return 0; // If curl failed to initialize
}

void monitor_websites(const char **urls, int url_count) {
    while (1) {
        for (int i = 0; i < url_count; i++) {
            int is_up = check_website(urls[i]);
            log_status(urls[i], is_up);
        }
        sleep(INTERVAL);
    }
}

int main() {
    const char *urls[MAX_URLS] = {
        "http://example.com",
        "http://nonexistentwebsite.xyz",
        "http://google.com",
        "http://github.com"
    };
    int url_count = 4;

    printf("Starting website uptime monitor...\n");
    monitor_websites(urls, url_count);

    return 0;
}