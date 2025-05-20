//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

#define URL_LEN 256
#define MAX_RETRIES 5
#define RETRY_DELAY 60

typedef struct {
    char url[URL_LEN];
    int status_code;
    time_t last_checked;
} website_t;

// Function to check the status code of a website
int check_website(website_t *website) {
    CURL *curl;
    CURLcode res;

    // Initialize the curl session
    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Error: Unable to initialize curl session.\n");
        return -1;
    }

    // Set the URL to be checked
    curl_easy_setopt(curl, CURLOPT_URL, website->url);

    // Follow redirects
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    // Set the timeout
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);

    // Execute the request
    res = curl_easy_perform(curl);

    // Get the status code
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &website->status_code);

    // Cleanup the curl session
    curl_easy_cleanup(curl);

    // Update the last checked time
    website->last_checked = time(NULL);

    return res;
}

// Function to monitor a website
void monitor_website(website_t *website) {
    int retries = 0;

    while (1) {
        // Check the status code of the website
        int res = check_website(website);

        // If the website is not responding, retry
        if (res != CURLE_OK) {
            if (retries < MAX_RETRIES) {
                retries++;
                sleep(RETRY_DELAY);
            } else {
                fprintf(stderr, "Error: Website %s is not responding.\n", website->url);
                break;
            }
        } else {
            // If the website is responding, print the status code
            printf("Website %s is responding with status code %d.\n", website->url, website->status_code);
        }

        // Sleep for 5 seconds before checking the website again
        sleep(5);
    }
}

int main(int argc, char **argv) {
    // Check if the user has provided a URL
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        return 1;
    }

    // Initialize the website struct
    website_t website;
    strcpy(website.url, argv[1]);
    website.status_code = 0;
    website.last_checked = time(NULL);

    // Monitor the website
    monitor_website(&website);

    return 0;
}