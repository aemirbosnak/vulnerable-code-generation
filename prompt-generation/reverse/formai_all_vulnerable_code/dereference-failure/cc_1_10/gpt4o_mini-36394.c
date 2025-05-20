//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define URL "http://example.com"
#define LOGFILE "uptime_log.txt"
#define CHECK_INTERVAL 60   // Check every 60 seconds

void log_status(const char *url, int status_code) {
    FILE *log_file = fopen(LOGFILE, "a");
    if (log_file) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        fprintf(log_file, "[%04d-%02d-%02d %02d:%02d:%02d] %s returned: %d\n",
                t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
                t->tm_hour, t->tm_min, t->tm_sec, url, status_code);
        fclose(log_file);
    } else {
        fprintf(stderr, "Could not open log file.\n");
    }
}

int check_website(const char *url) {
    CURL *curl;
    CURLcode res;
    long response_code;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        res = curl_easy_perform(curl);
        
        if (res == CURLE_OK) {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        } else {
            response_code = 0;
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return response_code;
}

int main() {
    int status;
    
    printf("Starting website uptime monitor for %s...\n", URL);
    while (1) {
        status = check_website(URL);
        printf("Status of %s: %d\n", URL, status);
        log_status(URL, status);
        sleep(CHECK_INTERVAL);
    }
    return 0;
}