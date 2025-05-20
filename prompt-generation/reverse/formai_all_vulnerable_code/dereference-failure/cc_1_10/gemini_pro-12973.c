//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define URL_MAX_LEN 256

// Function to check the status of a URL
int check_url_status(char *url) {
    CURL *curl;
    CURLcode res;

    // Initialize cURL
    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Error: Failed to initialize cURL\n");
        return -1;
    }

    // Set the URL to check
    curl_easy_setopt(curl, CURLOPT_URL, url);

    // Set the timeout for the request
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

    // Send the request and get the response code
    res = curl_easy_perform(curl);

    // Get the status code
    long status_code;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status_code);

    // Cleanup cURL resources
    curl_easy_cleanup(curl);

    return status_code;
}

// Function to monitor a website
int monitor_website(char *url, int interval) {
    int status_code;

    // Check the status of the URL
    status_code = check_url_status(url);

    // If the status code is not 200, send an alert
    if (status_code != 200) {
        fprintf(stderr, "Error: Website %s is down (status code: %d)\n", url, status_code);
        return -1;
    }

    // Wait for the specified interval
    sleep(interval);

    // Recursively call the function to monitor the website again
    return monitor_website(url, interval);
}

int main(int argc, char **argv) {
    // Check if the user has provided a URL
    if (argc < 2) {
        fprintf(stderr, "Error: Please provide a URL to monitor\n");
        return -1;
    }

    // Get the URL from the command line
    char *url = argv[1];

    // Check if the URL is valid
    if (strlen(url) > URL_MAX_LEN) {
        fprintf(stderr, "Error: URL is too long\n");
        return -1;
    }

    // Get the monitoring interval from the command line (if provided)
    int interval = 60;
    if (argc >= 3) {
        interval = atoi(argv[2]);
    }

    // Monitor the website
    return monitor_website(url, interval);
}