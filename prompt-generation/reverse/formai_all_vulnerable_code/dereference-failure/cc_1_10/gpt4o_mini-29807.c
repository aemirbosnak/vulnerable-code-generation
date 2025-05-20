//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>
#include <string.h>

#define URL "http://example.com" // Change this to the website you want to monitor
#define LOG_FILE "uptime_log.txt"
#define CHECK_INTERVAL 60 // in seconds

void write_log(const char *status) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Error opening log file");
        return;
    }
    
    time_t now = time(NULL);
    char *time_string = ctime(&now);
    // Remove the newline character from the end of the timestamp
    time_string[strcspn(time_string, "\n")] = 0;

    fprintf(file, "%s - %s\n", time_string, status);
    fclose(file);
}

int check_website(const char *url) {
    CURL *curl;
    CURLcode res;
    int http_code = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        res = curl_easy_perform(curl);
        
        if(res == CURLE_OK) {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
        } else {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            http_code = 0; // assume 0 for not reachable
        }
        
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return http_code;
}

void check_and_log() {
    int http_code = check_website(URL);
    if (http_code >= 200 && http_code < 400) {
        write_log("Website is UP");
    } else {
        write_log("Website is DOWN");
    }
}

int main() {
    printf("Starting uptime monitor for %s...\n", URL);
    while(1) {
        check_and_log();
        printf("Checked at %s. Sleeping for %d seconds...\n", ctime(&(time_t){time(NULL)}), CHECK_INTERVAL);
        sleep(CHECK_INTERVAL);
    }
    
    return 0;
}