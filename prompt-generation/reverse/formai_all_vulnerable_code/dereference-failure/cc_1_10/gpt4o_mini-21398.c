//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URLS 10
#define URL_LENGTH 256
#define LOG_FILE "uptime_log.txt"
#define TIME_INTERVAL 10 // Check sites every 10 seconds

typedef struct {
    char url[URL_LENGTH];
    int status; // 0 - down, 1 - up
} Website;

void log_status(const char *url, int status) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file) {
        time_t now = time(NULL);
        char *time_str = ctime(&now);
        time_str[strcspn(time_str, "\n")] = 0; // Remove newline from time string
        fprintf(file, "[%s] %s is %s\n", time_str, url, status == 1 ? "UP" : "DOWN");
        fclose(file);
    } else {
        perror("Error opening log file");
    }    
}

void check_website(Website *site) {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, site->url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We only need the response code
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L); // Set a timeout for the request
        
        res = curl_easy_perform(curl);
        
        if (res == CURLE_OK) {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            site->status = (response_code == 200) ? 1 : 0;
        } else {
            site->status = 0; // Assume down if we can't connect
        }
        curl_easy_cleanup(curl);
    }
}

void display_results(Website *websites, int count) {
    printf("\nCurrent Website Status:\n");
    printf("========================\n");
    
    for (int i = 0; i < count; i++) {
        printf("%s is %s\n", websites[i].url, websites[i].status == 1 ? "UP" : "DOWN");
    }
    printf("========================\n");
}

int main() {
    Website websites[MAX_URLS] = {
        {"http://example.com", 0},
        {"http://google.com", 0},
        {"http://nonexistentwebsite.xyz", 0},
        {"http://github.com", 0},
        // Add more URLs to check if needed
    };
    
    int count = 4; // Total number of websites to check

    printf("Website Uptime Monitor\n");
    printf("========================\n");

    while (1) {
        for (int i = 0; i < count; i++) {
            check_website(&websites[i]);
            log_status(websites[i].url, websites[i].status);
        }
        display_results(websites, count);
        sleep(TIME_INTERVAL); // Wait for the defined interval before the next check
    }

    return 0;
}