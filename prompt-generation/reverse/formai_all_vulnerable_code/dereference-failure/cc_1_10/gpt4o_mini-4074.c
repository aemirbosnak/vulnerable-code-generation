//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>

#define CHECK_INTERVAL 5 // seconds
#define MAX_ATTEMPTS 3

// Function to check the URL status
int check_url(const char* url) {
    CURL *curl;
    CURLcode res;
    long response_code;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);  // Only get the HTTP response status
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L); // Set a timeout for the request
        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return 0; // URL is down or unreachable
        }

        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        curl_easy_cleanup(curl);

        if(response_code >= 200 && response_code < 400) {
            printf("URL %s is reachable. Response code: %ld\n", url, response_code);
            return 1; // URL is up
        } else {
            printf("URL %s is not reachable. Response code: %ld\n", url, response_code);
            return 0; // URL is down or responds with error
        }
    }
    return 0; // Failed to initialize CURL
}

// Function to log the results into a file
void log_status(const char* url, int status) {
    FILE *log_file = fopen("uptime_log.txt", "a");
    if (!log_file) {
        fprintf(stderr, "Could not open log file for writing.\n");
        return;
    }

    time_t now;
    time(&now);
    char *time_str = ctime(&now);
    // Remove newline character from time string
    time_str[strlen(time_str) - 1] = '\0';

    if (status) {
        fprintf(log_file, "[%s] %s is UP\n", time_str, url);
    } else {
        fprintf(log_file, "[%s] %s is DOWN\n", time_str, url);
    }

    fclose(log_file);
}

// Main function to run the uptime monitor
int main(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    const char* url = argv[1];
    int attempts = 0;
    int status;

    while(attempts < MAX_ATTEMPTS) {
        printf("Checking %s...\n", url);
        status = check_url(url);
        log_status(url, status);

        if(status) {
            attempts = 0; // Reset attempts if URL is up
        } else {
            attempts++;
            if(attempts >= MAX_ATTEMPTS) {
                printf("Max attempts reached for %s. Giving up.\n", url);
                break;
            }
        }

        sleep(CHECK_INTERVAL); // Wait before next check
    }

    return 0; // Exit gracefully
}