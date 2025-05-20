//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URLS 100
#define TIME_INTERVAL 60 // Check every minute
#define LOG_FILE "uptime_log.txt"

void log_status(const char* url, int status) {
    FILE* file = fopen(LOG_FILE, "a");
    if (file != NULL) {
        time_t now = time(NULL);
        char* time_str = ctime(&now);
        time_str[strlen(time_str) - 1] = '\0'; // Remove the newline character

        if (status == 1) {
            fprintf(file, "[%s] %s is UP\n", time_str, url);
        } else {
            fprintf(file, "[%s] %s is DOWN\n", time_str, url);
        }
        fclose(file);
    }
}

size_t write_callback(void* contents, size_t size, size_t nmemb, void* userp) {
    return size * nmemb;
}

int check_url(const char* url) {
    CURL *curl;
    CURLcode res;
    long response_code;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            curl_global_cleanup();
            return -1;
        }

        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        curl_easy_cleanup(curl);
        curl_global_cleanup();

        return (response_code >= 200 && response_code < 400) ? 1 : 0;
    }
    return -1;
}

void monitor_urls(char* urls[], int url_count) {
    while (1) {
        for (int i = 0; i < url_count; i++) {
            printf("Checking %s...\n", urls[i]);
            int status = check_url(urls[i]);
            if (status != -1) {
                log_status(urls[i], status);
            }
            sleep(1); // To avoid overwhelming the server
        }
        printf("Waiting for %d seconds before the next check...\n", TIME_INTERVAL);
        sleep(TIME_INTERVAL);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <url1> <url2> ... <urlN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* urls[MAX_URLS];
    int url_count = argc - 1;

    if (url_count > MAX_URLS) {
        fprintf(stderr, "Error: A maximum of %d URLs can be monitored at once.\n", MAX_URLS);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < url_count; i++) {
        urls[i] = argv[i + 1];
    }

    printf("Starting uptime monitor for %d URLs...\n", url_count);
    monitor_urls(urls, url_count);

    return EXIT_SUCCESS;
}