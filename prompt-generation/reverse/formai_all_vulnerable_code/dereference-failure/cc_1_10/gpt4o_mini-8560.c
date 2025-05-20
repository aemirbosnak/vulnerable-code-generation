//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URLS 10
#define TIME_INTERVAL 10 // in seconds
#define LOG_FILE "uptime_log.txt"

// Function to log the result to a file
void log_result(const char *url, int status) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        perror("Failed to open log file");
        return;
    }
    time_t now = time(NULL);
    fprintf(log_file, "%s - %s: %s\n", ctime(&now), url, status ? "UP" : "DOWN");
    fclose(log_file);
}

// Function to check the uptime of a given URL
int check_website(const char *url) {
    CURL *curl;
    CURLcode res;
    int status = 0;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We only want the HTTP response header
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L); // Set timeout to 5 seconds
        
        res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            status = (response_code == 200);
        } else {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        
        curl_easy_cleanup(curl);
    }
    return status;
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        fprintf(stderr, "Usage: %s <URL1> [URL2] [URL3] ...\n", argv[0]);
        return 1;
    }

    // Do not exceed maximum urls
    int url_count = argc - 1 > MAX_URLS ? MAX_URLS : argc - 1;
    const char **urls = (const char **)malloc(url_count * sizeof(char *));
    for(int i = 0; i < url_count; i++) {
        urls[i] = argv[i + 1];
    }

    printf("Starting website uptime monitor...\n");
    while (1) {
        for (int i = 0; i < url_count; i++) {
            int status = check_website(urls[i]);
            log_result(urls[i], status);
        }
        printf("Checked all URLs, waiting for %d seconds...\n", TIME_INTERVAL);
        sleep(TIME_INTERVAL);
    }

    free(urls);
    return 0;
}