//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <curl/curl.h>

#define URL_MAX_LENGTH 256
#define LOG_FILE "uptime_log.txt"
#define CHECK_INTERVAL 60 // seconds
#define TIMEOUT 5 // seconds

// Function to get the current timestamp as a string
char* current_timestamp() {
    time_t now = time(NULL);
    char *timestamp = malloc(20);
    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
    return timestamp;
}

// Function to log the status of the website
void log_status(const char *url, int status_code) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Error opening log file");
        return;
    }
    char *timestamp = current_timestamp();
    fprintf(file, "%s - %s - Status Code: %d\n", timestamp, url, status_code);
    free(timestamp);
    fclose(file);
}

// Function to check website uptime using cURL
int check_website(const char *url) {
    CURL *curl;
    CURLcode res;
    long response_code;
    
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We only need the header
        res = curl_easy_perform(curl);
        
        if(res == CURLE_OK) {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            curl_easy_cleanup(curl);
            curl_global_cleanup();
            return (int)response_code;
        } else {
            fprintf(stderr, "cURL error: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            curl_global_cleanup();
            return 0;
        }
    }
    return -1; // cURL initialization failed
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char url[URL_MAX_LENGTH];
    strncpy(url, argv[1], URL_MAX_LENGTH);  // Copy URL to our local variable

    while (1) {
        int status_code = check_website(url);
        if (status_code != -1) {
            log_status(url, status_code);
            if (status_code >= 200 && status_code < 400) {
                printf("[%s] Website %s is UP! Status Code: %d\n", current_timestamp(), url, status_code);
            } else {
                printf("[%s] Website %s is DOWN! Status Code: %d\n", current_timestamp(), url, status_code);
            }
        } else {
            printf("[%s] Failed to check the website %s\n", current_timestamp(), url);
        }
        sleep(CHECK_INTERVAL);
    }

    return EXIT_SUCCESS;
}