//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

// Macros for the cyberpunk aesthetic
#define CYBERPUNK_GREEN "\033[0;32m"
#define CYBERPUNK_RED "\033[0;31m"
#define RESET "\033[0m"

// Structure to hold the website data
typedef struct {
    char url[256];
    int timeout;
    int alertThreshold;
} Site;

// Function to perform the HTTP GET request
void check_website(Site site) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, site.url);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, site.timeout);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We only need the header for status
        
        // Perform the request, res will get the return code 
        res = curl_easy_perform(curl);

        // Check HTTP response
        if (res != CURLE_OK) {
            printf(CYBERPUNK_RED "ERROR: Failed to connect to %s: %s\n" RESET, 
                    site.url, curl_easy_strerror(res));
        } else {
            long http_code = 0;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
            if (http_code == 200) {
                printf(CYBERPUNK_GREEN "SUCCESS: %s is UP! Status Code: %ld\n" RESET, site.url, http_code);
            } else {
                printf(CYBERPUNK_RED "ALERT: %s is DOWN! Status Code: %ld\n" RESET, site.url, http_code);
                // Consider logging, alerting, or other actions based on this
            }
        }
     
        // Cleanup
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

// Current time for logging
void log_time() {
    time_t now;
    time(&now);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0'; // Remove newline
    printf("[%s] ", time_str);
}

// Main function
int main() {
    // Initialize the cyberpunk array of websites
    Site websites[] = {
        {"http://localhost:8000", 5, 3},
        {"http://example.com", 5, 3},
        {"http://nonexistent.website", 5, 3}
    };
    int number_of_sites = sizeof(websites) / sizeof(websites[0]);
    
    // Infinite monitoring loop
    while (1) {
        // Monitor each site
        for (int i = 0; i < number_of_sites; i++) {
            log_time();
            check_website(websites[i]);
        }
        // Wait before next check
        sleep(10); // Wait for 10 seconds
    }
    
    return 0;
}