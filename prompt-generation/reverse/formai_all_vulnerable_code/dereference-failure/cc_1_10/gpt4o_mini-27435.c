//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 256
#define LOG_FILE "uptime_log.txt"
#define CHECK_INTERVAL 5 // in seconds

void log_results(const char *url, int status) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file) {
        fprintf(log_file, "URL: %s - Status: %s\n", url, status == 0 ? "UP" : "DOWN");
        fclose(log_file);
    } else {
        fprintf(stderr, "Error opening log file\n");
    }
}

int check_website(const char *url) {
    CURL *curl;
    CURLcode res;
    long response_code;

    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Could not initialize curl\n");
        return -1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We don't need the body
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L); // 10 second timeout

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        return -1;
    }

    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
    curl_easy_cleanup(curl);

    return (response_code == 200) ? 0 : 1; // 0 for UP, 1 for DOWN
}

void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <URL>\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE; 
    }

    char url[MAX_URL_LENGTH];
    strncpy(url, argv[1], MAX_URL_LENGTH - 1);
    url[MAX_URL_LENGTH - 1] = '\0'; // Ensure null-termination

    printf("Monitoring uptime for: %s\n", url);
    while (1) {
        int status = check_website(url);
        log_results(url, status);
        sleep(CHECK_INTERVAL);
    }

    return 0;
}