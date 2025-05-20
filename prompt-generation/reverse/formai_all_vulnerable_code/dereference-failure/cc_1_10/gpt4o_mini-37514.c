//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <curl/curl.h>

#define MAX_URLS 10
#define BUFFER_SIZE 256

// Function to check a single URL
int check_url(const char *url) {
    CURL *curl;
    CURLcode res;
    long response_code;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We don't need body
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return 0; // URL is down
        }
        
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        curl_easy_cleanup(curl);
        
        return (response_code >= 200 && response_code < 400) ? 1 : 0;
    }
    return 0; // Could not initialize CURL
}

// Function to log the status of the URLs
void log_status(const char *url, int status) {
    const char *status_message = status ? "UP" : "DOWN";
    FILE *log_file = fopen("uptime_log.txt", "a");
    if (log_file) {
        time_t now;
        time(&now);
        fprintf(log_file, "%s - %s: %s\n", ctime(&now), url, status_message);
        fclose(log_file);
    } else {
        fprintf(stderr, "Could not open log file!\n");
    }
}

// Function to read URLs from a file
int read_urls(const char *filename, char urls[MAX_URLS][BUFFER_SIZE]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open URL file: %s\n", filename);
        return -1;
    }
    int count = 0;
    while (count < MAX_URLS && fgets(urls[count], BUFFER_SIZE, file)) {
        // Remove newline character;
        urls[count][strcspn(urls[count], "\n")] = 0;
        count++;
    } 
    fclose(file);
    return count;
}

// Function to monitor URLs
void monitor_urls(const char urls[MAX_URLS][BUFFER_SIZE], int count, int interval) {
    while (1) {
        for (int i = 0; i < count; i++) {
            int status = check_url(urls[i]);
            log_status(urls[i], status);
        }
        printf("Checked all URLs. Sleeping for %d seconds...\n", interval);
        sleep(interval);
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <url_file> <interval_in_seconds>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *url_file = argv[1];
    int interval = atoi(argv[2]);
    if (interval <= 0) {
        fprintf(stderr, "Interval must be a positive integer.\n");
        return EXIT_FAILURE;
    }
    
    char urls[MAX_URLS][BUFFER_SIZE];
    int count = read_urls(url_file, urls);
    if (count < 0) {
        return EXIT_FAILURE;
    }

    printf("Monitoring %d URLs every %d seconds...\n", count, interval);
    monitor_urls(urls, count, interval);

    return EXIT_SUCCESS;
}