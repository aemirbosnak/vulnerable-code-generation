//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URL_LENGTH 256
#define LOG_FILE "uptime_log.txt"

void log_event(const char *url, const char *status) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        perror("Unable to open log file");
        return;
    }
    
    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    
    // Remove newline character from ctime
    timestamp[strlen(timestamp) - 1] = '\0';
    
    fprintf(log_file, "[%s] %s is %s\n", timestamp, url, status);
    fclose(log_file);
}

int check_website(const char *url) {
    CURL *curl;
    CURLcode res;
    long response_code;

    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "curl_easy_init() failed\n");
        return 0;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We're only interested in the header
    curl_easy_setopt(curl, CURLOPT_HEADER, 1L); // We want just the headers
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L); // Set timeout to 5 seconds

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        return 0;
    }

    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
    curl_easy_cleanup(curl);

    return (response_code == 200) ? 1 : 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        return 1;
    }

    const char *url = argv[1];
    int is_up;

    while (1) {
        is_up = check_website(url);
        if (is_up) {
            printf("%s is up.\n", url);
            log_event(url, "UP");
        } else {
            printf("%s is down.\n", url);
            log_event(url, "DOWN");
        }
        sleep(10); // Pause for 10 seconds before next check
    }

    return 0;
}