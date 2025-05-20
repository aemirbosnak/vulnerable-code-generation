//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <curl/curl.h>

#define MAX_URLS 10
#define MAX_NAME_LENGTH 128
#define SLEEP_TIME 30

void log_status(const char *url, int response_code, const char *status) {
    time_t now = time(NULL);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0'; // Remove newline character

    printf("[%s] URL: %s - Response Code: %d - Status: %s\n", time_str, url, response_code, status);
}

int check_url(const char *url) {
    CURL *curl;
    CURLcode res;
    long response_code;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We don't need the body of the response
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L); // Set a timeout
        res = curl_easy_perform(curl);
        
        // Check for errors
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            curl_global_cleanup();
            return -1;
        }

        // Obtain response code
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        curl_easy_cleanup(curl);
        curl_global_cleanup();
        return response_code;
    }
    return -1; // return -1 if something goes wrong
}

void monitor_urls(const char *urls[], int url_count) {
    while(1) {
        for(int i = 0; i < url_count; i++) {
            int response_code = check_url(urls[i]);
            if (response_code >= 200 && response_code < 400) {
                log_status(urls[i], response_code, "UP");
            } else {
                log_status(urls[i], response_code, "DOWN");
            }
        }
        sleep(SLEEP_TIME); // Wait for some time before next check
    }
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        fprintf(stderr, "Usage: %s <url1> <url2> ... <urlN>\n", argv[0]);
        return 1;
    }

    const char *urls[MAX_URLS];
    int url_count = argc - 1;

    if(url_count > MAX_URLS) {
        fprintf(stderr, "You can only monitor a maximum of %d URLs.\n", MAX_URLS);
        return 1;
    }

    for(int i = 0; i < url_count; i++) {
        urls[i] = argv[i + 1];
    }

    printf("Starting URL monitoring...\n");
    monitor_urls(urls, url_count);

    return 0;
}