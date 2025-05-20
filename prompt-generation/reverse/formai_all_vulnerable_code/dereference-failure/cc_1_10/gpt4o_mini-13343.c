//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define LOG_FILE "uptime_log.txt"

// Function prototypes
void log_status(const char *url, int status);
int check_website(const char *url);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <URL> <INTERVAL>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *url = argv[1];
    int interval = atoi(argv[2]);
    
    if (interval <= 0) {
        fprintf(stderr, "Error: INTERVAL must be a positive number.\n");
        return EXIT_FAILURE;
    }

    printf("Starting website uptime monitor for %s at interval of %d seconds.\n", url, interval);

    while (1) {
        int status = check_website(url);
        log_status(url, status);
        sleep(interval);
    }

    return EXIT_SUCCESS;
}

int check_website(const char *url) {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(!curl) {
        fprintf(stderr, "Error: Could not initialize curl.\n");
        return -1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);  // Don't fetch the body of the response
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L); // Set timeout

    res = curl_easy_perform(curl);
    long response_code = 0;

    if (res != CURLE_OK) {
        fprintf(stderr, "Error: curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        return 0;  // Consider it down
    }

    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
    curl_easy_cleanup(curl);
    
    return response_code == 200 ? 1 : 0;  // 1 for up, 0 for down
}

void log_status(const char *url, int status) {
    FILE *log = fopen(LOG_FILE, "a");
    if (!log) {
        fprintf(stderr, "Error: Could not open log file.\n");
        return;
    }

    time_t now;
    time(&now);
    char *timestamp = ctime(&now);
    timestamp[strcspn(timestamp, "\n")] = 0; // Remove newline from ctime output

    if (status) {
        fprintf(log, "[%s] %s is UP\n", timestamp, url);
        printf("[%s] %s is UP\n", timestamp, url);
    } else {
        fprintf(log, "[%s] %s is DOWN\n", timestamp, url);
        printf("[%s] %s is DOWN\n", timestamp, url);
    }

    fclose(log);
}