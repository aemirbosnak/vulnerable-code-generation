//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <unistd.h>

#define MAX_URL_LENGTH 256
#define LOG_FILE "uptime_log.txt"
#define INTERVAL 10 // Check every 10 seconds

// Function for logging the uptime status
void log_status(const char *url, int status) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file != NULL) {
        time_t now = time(NULL);
        char *timestamp = ctime(&now);
        timestamp[strlen(timestamp) - 1] = '\0'; // Remove the newline character
        fprintf(log_file, "[%s] %s is %s\n", timestamp, url, status ? "UP" : "DOWN");
        fclose(log_file);
    } else {
        perror("Error opening log file");
    }
}

// Function to check if a website is reachable
int check_website(const char *url) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L); // Timeout after 5 seconds
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // Don't download body

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        curl_global_cleanup();

        // Check the result of the request
        if (res == CURLE_OK) {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            return (response_code >= 200 && response_code < 400) ? 1 : 0; // Consider it UP if status is 2xx or 3xx
        } else {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            return 0;
        }
    } else {
        fprintf(stderr, "Failed to initialize CURL.\n");
        return 0;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        return 1;
    }

    char url[MAX_URL_LENGTH];
    strncpy(url, argv[1], MAX_URL_LENGTH - 1);
    url[MAX_URL_LENGTH - 1] = '\0'; // Ensure null termination

    printf("Monitoring uptime for: %s\n", url);
    while (1) {
        int status = check_website(url);
        log_status(url, status);
        sleep(INTERVAL);
    }

    return 0;
}