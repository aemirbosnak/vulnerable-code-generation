//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

// Function to check the uptime of a website
int check_uptime(char *url) {
    CURL *curl;
    CURLcode res;

    // Initialize CURL
    curl = curl_easy_init();
    if (curl == NULL) {
        return -1;
    }

    // Set the URL to check
    curl_easy_setopt(curl, CURLOPT_URL, url);

    // Set the timeout to 5 seconds
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5);

    // Perform the request
    res = curl_easy_perform(curl);

    // Check the result
    if (res != CURLE_OK) {
        return -1;
    }

    // Get the response code
    long response_code;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

    // Check if the website is up
    if (response_code == 200) {
        return 0;
    } else {
        return -1;
    }

    // Cleanup CURL
    curl_easy_cleanup(curl);
}

// Function to monitor the uptime of a website
void monitor_uptime(char *url, int interval) {
    while (1) {
        // Check the uptime of the website
        int uptime = check_uptime(url);

        // Print the result
        if (uptime == 0) {
            printf("Website is up\n");
        } else {
            printf("Website is down\n");
        }

        // Sleep for the specified interval
        sleep(interval);
    }
}

int main(int argc, char *argv[]) {
    // Check the arguments
    if (argc < 3) {
        printf("Usage: %s <url> <interval>\n", argv[0]);
        return 1;
    }

    // Get the URL and interval from the arguments
    char *url = argv[1];
    int interval = atoi(argv[2]);

    // Monitor the uptime of the website
    monitor_uptime(url, interval);

    return 0;
}