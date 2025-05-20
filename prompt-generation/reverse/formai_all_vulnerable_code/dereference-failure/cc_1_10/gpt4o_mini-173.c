//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URLS 10
#define OUTPUT_LOG "uptime_log.txt"

void check_website(const char *url) {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);

        // Make the request and log the outcome
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            printf("Error checking %s: %s\n", url, curl_easy_strerror(res));
        } else {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            if(response_code == 200) {
                printf("Surprisingly, %s is UP!\n", url);
            } else {
                printf("Alas! %s is DOWN! Response code: %ld\n", url, response_code);
            }
        }

        // Cleanup
        curl_easy_cleanup(curl);
    }
}

void log_result(const char *url, int is_up) {
    FILE *log_file = fopen(OUTPUT_LOG, "a");
    if (log_file == NULL) {
        fprintf(stderr, "Could not open log file for writing.\n");
        return; // Don't proceed if log file can't be opened
    }

    time_t now;
    time(&now);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0'; // Remove newline character

    if(is_up) {
        fprintf(log_file, "[%s] %s is UP!\n", time_str, url);
    } else {
        fprintf(log_file, "[%s] %s is DOWN!\n", time_str, url);
    }
    fclose(log_file);
}

int main() {
    char *urls[MAX_URLS];
    int num_urls = 0;

    printf("Welcome to the Website Uptime Monitor!\n");
    printf("Enter up to %d website URLs to monitor (enter 'done' to finish):\n", MAX_URLS);
    
    while (num_urls < MAX_URLS) {
        char buffer[256];
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character

        if (strcmp(buffer, "done") == 0) {
            break; // Exit loop on 'done'
        }

        urls[num_urls] = strdup(buffer); // Duplicate the string
        num_urls++;
    }

    printf("Monitoring the following websites:\n");
    for (int i = 0; i < num_urls; i++) {
        printf("- %s\n", urls[i]);
    }

    // Monitor websites indefinitely
    while (1) {
        for (int i = 0; i < num_urls; i++) {
            check_website(urls[i]);
            log_result(urls[i], 1); // Assume true for now, adjust later per needs
        }
        printf("Waiting for the next check...\n");
        sleep(60); // Wait for 60 seconds before the next check
    }

    // Free allocated memory
    for (int i = 0; i < num_urls; i++) {
        free(urls[i]);
    }

    return 0;
}