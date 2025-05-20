//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define URL "http://example.com" // Change to the desired URL
#define LOG_FILE "uptime_log.txt"
#define CHECK_INTERVAL 30 // Check every 30 seconds
#define MAX_LOG_SIZE 1024 // Maximum log entry size

void log_status(const char *status) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        perror("Failed to open log file");
        exit(EXIT_FAILURE);
    }

    time_t now = time(NULL);
    char *formatted_time = ctime(&now);
    formatted_time[strlen(formatted_time) - 1] = '\0'; // Remove newline

    fprintf(log_file, "[%s] %s: %s\n", formatted_time, URL, status);
    fclose(log_file);
}

int check_website(const char *url) {
    CURL *curl;
    CURLcode res;

    // Initialize libcurl
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1); // We don't need the body
        res = curl_easy_perform(curl);
        
        // Check response code
        long response_code;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        curl_easy_cleanup(curl);
        
        if (res != CURLE_OK || response_code != 200) {
            log_status("Website is DOWN");
            return 0; // Down
        }
        
        log_status("Website is UP");
        return 1; // Up
    }

    curl_global_cleanup();
    return 0; // Could not initialize CURL
}

int main() {
    printf("Starting Website Uptime Monitor for: %s\n", URL);
    printf("Logging to: %s\n", LOG_FILE);
    
    while (1) {
        check_website(URL);
        sleep(CHECK_INTERVAL); // Wait for the next check
    }

    return 0; // This will never be reached
}