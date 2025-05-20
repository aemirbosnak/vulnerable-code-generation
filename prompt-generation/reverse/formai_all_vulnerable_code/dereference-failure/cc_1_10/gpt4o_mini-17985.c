//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <unistd.h>
#include <time.h>

#define URL "http://example.com"
#define LOG_FILE "uptime_log.txt"
#define CHECK_INTERVAL 10  // Check every 10 seconds

void log_status(const char *url, int status_code) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        fprintf(stderr, "Could not open log file for writing.\n");
        return;
    }
    time_t now = time(NULL);
    char *datetime = ctime(&now);
    datetime[strlen(datetime) - 1] = '\0'; // Remove newline

    if (status_code == 200) {
        fprintf(log_file, "[%s] %s is UP (Status code: %d)\n", datetime, url, status_code);
    } else {
        fprintf(log_file, "[%s] %s is DOWN (Status code: %d)\n", datetime, url, status_code);
    }
    fclose(log_file);
}

int check_website(const char *url) {
    CURL *curl;
    CURLcode res;
    long response_code = 0;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We only want the response code
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            response_code = -1;
        } else {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        }
        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Failed to initialize CURL.\n");
        response_code = -1;
    }
    return (int)response_code;
}

int main() {
    while (1) {
        int status_code = check_website(URL);
        if (status_code != -1) {
            log_status(URL, status_code);
        } else {
            log_status(URL, -1);
        }
        sleep(CHECK_INTERVAL);
    }
    return 0;
}