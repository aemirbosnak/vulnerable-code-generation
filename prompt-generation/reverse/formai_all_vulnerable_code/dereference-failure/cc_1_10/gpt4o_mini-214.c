//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>

#define URL "http://example.com"
#define CHECK_INTERVAL 60 // seconds
#define MAX_RETRIES 3

typedef struct {
    int success_count;
    int failure_count;
} uptime_stats_t;

// Callback function to write data to a buffer (not used here)
size_t write_callback(void *ptr, size_t size, size_t nmemb, void *data) {
    return size * nmemb; // Simply consume the data
}

// Function to check the website uptime
int check_website(const char *url) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We don't need the body
        
        res = curl_easy_perform(curl);
        
        // Check if the operation was successful
        if(res == CURLE_OK) {
            long http_response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_response_code);
            curl_easy_cleanup(curl);
            curl_global_cleanup();
            return (http_response_code >= 200 && http_response_code < 400); // HTTP status code check
        }
        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }
    
    return 0; // Failed to perform check
}

// Function to display uptime statistics
void display_uptime_stats(uptime_stats_t *stats) {
    printf("Uptime Stats:\n");
    printf("  Successful checks: %d\n", stats->success_count);
    printf("  Failed checks: %d\n", stats->failure_count);
}

void log_status(const char *message) {
    time_t now;
    time(&now);
    char *time_str = ctime(&now); // Convert time to string
    time_str[strlen(time_str) - 1] = '\0'; // remove the newline character
    printf("[%s] %s\n", time_str, message);
}

int main() {
    uptime_stats_t stats = {0, 0};
    
    while(1) {
        log_status("Checking website status...");
        
        if (check_website(URL)) {
            stats.success_count++;
            log_status("Website is UP.");
        } else {
            stats.failure_count++;
            log_status("Website is DOWN.");
        }

        // Display the stats after each interval
        display_uptime_stats(&stats);

        // Sleep for the defined check interval
        sleep(CHECK_INTERVAL);
    }

    return 0;
}