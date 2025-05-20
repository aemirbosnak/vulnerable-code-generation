//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

#define URL_MAX 256
#define LOG_FILE "uptime_log.txt"
#define INTERVAL 10 // seconds

void log_status(const char *url, long response_code) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Unable to open log file");
        return;
    }
    fprintf(file, "URL: %s | Status Code: %ld | Time: %s", 
            url, response_code, ctime(&(time_t){time(NULL)}));
    fclose(file);
}

long check_website(const char *url) {
    CURL *curl;
    CURLcode res;
    long response_code = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We only want the status code
        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            fprintf(stderr, "Failed to fetch %s: %s\n", url, curl_easy_strerror(res));
        } else {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return response_code;
}

void display_usage() {
    printf("Usage: uptime_monitor <url>\n");
    printf("Example: uptime_monitor http://example.com\n");
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        display_usage();
        return EXIT_FAILURE;
    }

    const char *url = argv[1];
    char valid_url[URL_MAX];

    // Simple validation of URL length
    if (strlen(url) >= URL_MAX) {
        fprintf(stderr, "URL is too long (max %d characters).\n", URL_MAX - 1);
        return EXIT_FAILURE;
    }
    strncpy(valid_url, url, URL_MAX);

    while(1) {
        long status_code = check_website(valid_url);
        log_status(valid_url, status_code);

        if(status_code == 200) {
            printf("%s is UP\n", valid_url);
        } else {
            printf("%s is DOWN (status code: %ld)\n", valid_url, status_code);
        }

        sleep(INTERVAL);
    }

    return EXIT_SUCCESS;
}