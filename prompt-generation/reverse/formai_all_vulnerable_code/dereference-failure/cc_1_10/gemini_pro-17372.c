//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

// Constants
#define URL_LENGTH 1024
#define RESPONSE_BUFFER_SIZE 1024

// Function to check website uptime
int check_uptime(char *url) {
    // Initialize curl
    CURL *curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Error: Unable to initialize curl\n");
        return 1;
    }

    // Set the URL to check
    curl_easy_setopt(curl, CURLOPT_URL, url);

    // Set the response buffer
    char response_buffer[RESPONSE_BUFFER_SIZE];
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, response_buffer);

    // Perform the request
    CURLcode result = curl_easy_perform(curl);

    // Get the response code
    long response_code;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

    // Cleanup curl
    curl_easy_cleanup(curl);

    // Check if the website is up
    if (response_code == 200) {
        return 1;
    } else {
        return 0;
    }
}

// Function to monitor website uptime
void monitor_uptime(char *url, int interval) {
    // Infinite loop to continuously monitor the website
    while (1) {
        // Check the website uptime
        int uptime = check_uptime(url);

        // Print the uptime status
        printf("Website %s is %s\n", url, uptime ? "up" : "down");

        // Sleep for the specified interval
        sleep(interval);
    }
}

// Main function
int main(int argc, char **argv) {
    // Check if the user has provided the URL
    if (argc < 2) {
        fprintf(stderr, "Error: You must provide the URL to monitor\n");
        return 1;
    }

    // Check if the user has provided the interval
    if (argc < 3) {
        fprintf(stderr, "Error: You must provide the monitoring interval in seconds\n");
        return 1;
    }

    // Get the URL
    char *url = argv[1];

    // Get the interval
    int interval = atoi(argv[2]);

    // Start monitoring the website
    monitor_uptime(url, interval);

    return 0;
}