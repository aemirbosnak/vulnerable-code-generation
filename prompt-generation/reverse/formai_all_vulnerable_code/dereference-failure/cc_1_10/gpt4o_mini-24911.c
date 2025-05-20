//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <unistd.h>

#define MAX_SITES 10
#define BUFFER_SIZE 2048
#define LOG_FILE "site_status.log"

// Struct to hold a website and its status
typedef struct {
    char url[BUFFER_SIZE];
    int status;
} Website;

// Function to write logs to a file
void log_status(const char *message) {
    FILE *logfile = fopen(LOG_FILE, "a");
    if (logfile == NULL) {
        perror("Failed to open log file");
        return;
    }

    time_t now = time(NULL);
    fprintf(logfile, "[%s] %s\n", ctime(&now), message);
    fclose(logfile);
}

// Function to check the status of a website
int check_website(const char *url) {
    CURL *curl;
    CURLcode res;
    long response_code;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We don't need the body
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return -1;
        }

        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        curl_easy_cleanup(curl);
        return response_code;
    }
    return -1;
}

// Function to monitor websites
void monitor_websites(Website *websites, int count, int interval) {
    for (int i = 0; i < count; i++) {
        int status = check_website(websites[i].url);
        websites[i].status = status;
        if (status >= 200 && status < 400) {
            char message[BUFFER_SIZE];
            sprintf(message, "Website %s is UP with status code %ld.", websites[i].url, status);
            log_status(message);
        } else {
            char message[BUFFER_SIZE];
            sprintf(message, "Website %s is DOWN with status code %ld.", websites[i].url, status);
            log_status(message);
        }
    }
    sleep(interval);
}

int main(int argc, char *argv[]) {
    Website websites[MAX_SITES];
    int website_count = 0;
    int interval = 10; // Default interval (in seconds)

    // Check for command line arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <interval in seconds> <url1> [<url2> ... <urlN>]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse the interval from the command line
    interval = atoi(argv[1]);
    if (interval <= 0) {
        fprintf(stderr, "Interval must be greater than 0.\n");
        return EXIT_FAILURE;
    }

    // Store the URLs provided as arguments
    for (int i = 2; i < argc && website_count < MAX_SITES; i++) {
        strncpy(websites[website_count++].url, argv[i], BUFFER_SIZE);
    }

    if (website_count == 0) {
        fprintf(stderr, "No websites provided to monitor.\n");
        return EXIT_FAILURE;
    }

    // Begin monitoring in an infinite loop
    while (1) {
        monitor_websites(websites, website_count, interval);
    }

    return EXIT_SUCCESS;
}