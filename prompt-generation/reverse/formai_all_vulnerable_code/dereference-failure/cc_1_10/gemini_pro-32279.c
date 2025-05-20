//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: introspective
// C Program to Monitor Website Uptime

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <curl/curl.h>

// Store the monitoring data
typedef struct website_uptime {
    char *url;                 // URL of the website
    time_t last_check;        // Last time the website was checked
    time_t last_status_code;  // Last status code received
    bool is_up;
} website_uptime;

// Allocate and initialize a new website uptime monitor
website_uptime *create_website_uptime_monitor(char *url) {
    website_uptime *monitor = malloc(sizeof(website_uptime));
    if (monitor == NULL) {
        return NULL;
    }

    monitor->url = strdup(url);
    monitor->last_check = time(NULL);
    monitor->last_status_code = 0;
    monitor->is_up = false;

    return monitor;
}

// Destroy the website uptime monitor
void destroy_website_uptime_monitor(website_uptime *monitor) {
    if (monitor == NULL) {
        return;
    }

    free(monitor->url);
    free(monitor);
}

// Perform a single check on the website
bool check_website_uptime(website_uptime *monitor) {
    CURL *curl;
    CURLcode res;
    long status_code;

    // Initialize curl
    curl = curl_easy_init();
    if (curl == NULL) {
        return false;
    }

    // Set curl options
    curl_easy_setopt(curl, CURLOPT_URL, monitor->url);
    curl_easy_setopt(curl, CURLOPT_NOBODY, true);
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 10);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

    // Perform the request
    res = curl_easy_perform(curl);
    if (res == CURLE_OK) {
        // Get the status code
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status_code);

        // Check if the website is up
        if (status_code == 200) {
            monitor->is_up = true;
        } else {
            monitor->is_up = false;
        }
    } else {
        monitor->is_up = false;
    }

    // Cleanup curl
    curl_easy_cleanup(curl);

    return monitor->is_up;
}

// Main function
int main() {
    // Create a website uptime monitor
    website_uptime *monitor = create_website_uptime_monitor("https://www.example.com");

    // Check the website uptime regularly
    while (true) {
        // Check the website uptime
        bool is_up = check_website_uptime(monitor);

        // Print the website uptime status
        printf("Website %s is %s\n", monitor->url, (is_up) ? "up" : "down");

        // Sleep for a while
        sleep(5);
    }

    // Destroy the website uptime monitor
    destroy_website_uptime_monitor(monitor);

    return 0;
}