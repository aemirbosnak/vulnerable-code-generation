//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

#define TARGET_URL "https://www.example.com"
#define MAX_RETRIES 3

// Callback function to write received data
size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp) {
    return size * nmemb;
}

// Helper function to retrieve current time as string
char *get_current_time() {
    time_t now = time(NULL);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0';
    return time_str;
}

int main() {
    CURL *curl_handle;
    CURLcode res;

    // Initialize CURL
    curl_global_init(CURL_GLOBAL_DEFAULT);

    // Create CURL handle
    curl_handle = curl_easy_init();

    if (curl_handle) {
        int retries = 0;
        int success = 0;

        while (retries < MAX_RETRIES && !success) {
            // Set URL to check
            curl_easy_setopt(curl_handle, CURLOPT_URL, TARGET_URL);

            // Set write_callback function to discard received data
            curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);

            // Perform the request
            res = curl_easy_perform(curl_handle);

            if (res == CURLE_OK) {
                printf("%s: Website %s is up!\n", get_current_time(), TARGET_URL);
                success = 1;
            } else {
                printf("%s: Website %s is down! Error: %s\n", get_current_time(), TARGET_URL, curl_easy_strerror(res));
            }

            retries++;
        }

        // Clean up CURL handle
        curl_easy_cleanup(curl_handle);
    } else {
        printf("Error: Could not initialize CURL handle.\n");
    }

    // Clean up CURL
    curl_global_cleanup();

    return 0;
}