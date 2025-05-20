//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <curl/curl.h>
#include <sys/time.h>
#include <unistd.h>

// Custom data struct to store website URL and its status
typedef struct website {
    char *url;
    bool is_up;
    time_t last_checked;
} website_t;

// Global variables
website_t *websites;
int num_websites = 0;

// Function to initialize the website list
void init_websites() {
    // Add your custom list of websites to monitor here
    num_websites = 2;
    websites = malloc(sizeof(website_t) * num_websites);
    websites[0] = (website_t) {.url = "https://www.google.com", .is_up = false, .last_checked = 0};
    websites[1] = (website_t) {.url = "https://www.facebook.com", .is_up = false, .last_checked = 0};
}

// Function to check if a website is up
bool is_website_up(website_t *website) {
    CURL *curl;
    CURLcode res;
    long response_code;

    // Initialize curl
    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Error initializing curl.\n");
        return false;
    }

    // Set the URL to check
    curl_easy_setopt(curl, CURLOPT_URL, website->url);

    // Set the timeout
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5);

    // Perform the request
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "Error performing curl request: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        return false;
    }

    // Get the response code
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

    // Check if the response code is 200 (OK)
    if (response_code == 200) {
        website->is_up = true;
    } else {
        website->is_up = false;
    }

    // Cleanup curl
    curl_easy_cleanup(curl);

    return website->is_up;
}

// Function to print the website monitoring results
void print_results() {
    int i;

    for (i = 0; i < num_websites; i++) {
        printf("Website: %s\n", websites[i].url);
        printf("Status: %s\n", websites[i].is_up ? "Up" : "Down");
        printf("Last checked: %s\n", ctime(&websites[i].last_checked));
        printf("\n");
    }
}

// Main function
int main() {
    time_t current_time;
    int i;

    // Initialize the website list
    init_websites();

    // Main loop
    while (true) {
        // Get the current time
        current_time = time(NULL);

        // Check if it's time to check the website statuses
        for (i = 0; i < num_websites; i++) {
            if (difftime(current_time, websites[i].last_checked) >= 60) {
                // Check if the website is up
                is_website_up(&websites[i]);

                // Update the last checked time
                websites[i].last_checked = current_time;
            }
        }

        // Print the website monitoring results
        print_results();

        // Sleep for 1 minute
        sleep(60);
    }

    return 0;
}