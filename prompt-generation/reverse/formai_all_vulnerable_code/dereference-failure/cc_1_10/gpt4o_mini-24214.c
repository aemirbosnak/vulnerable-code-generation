//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URL_LENGTH 256
#define LOG_FILE "uptime_log.txt"
#define CHECK_INTERVAL 5

void log_result(const char *url, const char *status, const char *timestamp) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file) {
        fprintf(log_file, "[%s] %s: %s\n", timestamp, url, status);
        fclose(log_file);
    } else {
        perror("Failed to open log file");
    }
}

void check_website(const char *url) {
    CURL *curl;
    CURLcode res;
    char status[10];
    time_t now;
    char timestamp[20];

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // Only check for connection, no body needed

        res = curl_easy_perform(curl);
        
        now = time(NULL);
        strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));
        
        if (res == CURLE_OK) {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            if (response_code == 200) {
                snprintf(status, sizeof(status), "UP");
            } else {
                snprintf(status, sizeof(status), "DOWN");
            }
        } else {
            snprintf(status, sizeof(status), "ERROR");
        }

        log_result(url, status, timestamp);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char url[MAX_URL_LENGTH];
    strncpy(url, argv[1], MAX_URL_LENGTH);
    url[MAX_URL_LENGTH - 1] = '\0'; // Ensure null termination

    printf("Monitoring website: %s\n", url);
    printf("Logging results to: %s\n", LOG_FILE);

    while (1) {
        check_website(url);
        sleep(CHECK_INTERVAL);
    }

    return EXIT_SUCCESS;
}