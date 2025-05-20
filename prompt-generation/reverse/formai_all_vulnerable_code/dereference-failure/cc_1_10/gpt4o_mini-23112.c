//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <unistd.h>

#define MAX_URL_LENGTH 256
#define CHECK_INTERVAL 5 // seconds
#define RESPONSE_OK 200

void check_website(const char* url) {
    CURL *curl;
    CURLcode res;
    long response_code;

    // Initialize libcurl
    curl = curl_easy_init();
    if(curl) {
        // Set the URL for the request
        curl_easy_setopt(curl, CURLOPT_URL, url);

        // Perform the request, res will get the return code
        res = curl_easy_perform(curl);

        // Check for errors
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        else {
            // Get the HTTP response code
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            if(response_code == RESPONSE_OK) {
                printf("🎉 The website %s is UP! (HTTP %ld)\n", url, response_code);
            } else {
                printf("😢 The website %s is DOWN! (HTTP %ld)\n", url, response_code);
            }
        }

        // Always cleanup
        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Failed to initialize curl!\n");
    }
}

int main(int argc, char *argv[]) {
    char url[MAX_URL_LENGTH];

    if(argc < 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Copy the URL from command line arguments
    strncpy(url, argv[1], MAX_URL_LENGTH - 1);
    url[MAX_URL_LENGTH - 1] = '\0'; // Ensure null termination

    printf("🌟 Starting uptime monitor for: %s 🌟\n", url);

    // Infinite loop to check the website at regular intervals
    while(1) {
        check_website(url);
        sleep(CHECK_INTERVAL);
    }

    return EXIT_SUCCESS;
}