//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>
#include <unistd.h>

#define MAX_URLS 10
#define CHECK_INTERVAL 5

typedef struct {
    char *url;
    int status;
} UrlStatus;

UrlStatus urlStatusList[MAX_URLS];
int urlCount = 0;

size_t dummy_callback(void *ptr, size_t size, size_t nmemb) {
    return size * nmemb; // Ignore response data
}

void check_url(const char *url, int index) {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, dummy_callback);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        
        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            urlStatusList[index].status = response_code;
        } else {
            urlStatusList[index].status = -1; // Indicate error
        }

        curl_easy_cleanup(curl);
    }
}

void log_status(void) {
    FILE *log_file = fopen("uptime_log.txt", "a");
    if (!log_file) {
        perror("Failed to open log file");
        return;
    }

    time_t now;
    time(&now);
    fprintf(log_file, "Log Time: %s", ctime(&now));
    
    for (int i = 0; i < urlCount; i++) {
        if (urlStatusList[i].status != -1) {
            fprintf(log_file, "URL: %s - Status: %ld\n", urlStatusList[i].url, urlStatusList[i].status);
        } else {
            fprintf(log_file, "URL: %s - Status: ERROR\n", urlStatusList[i].url);
        }
    }

    fprintf(log_file, "\n");
    fclose(log_file);
}

void add_url(const char *url) {
    if (urlCount < MAX_URLS) {
        urlStatusList[urlCount].url = strdup(url);
        urlStatusList[urlCount].status = 0;
        urlCount++;
    } else {
        printf("Max URL limit reached.\n");
    }
}

void free_memory(void) {
    for (int i = 0; i < urlCount; i++) {
        free(urlStatusList[i].url);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <url1> <url2> ... <urlN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        add_url(argv[i]);
    }

    while (1) {
        printf("Checking URLs...\n");
        for (int i = 0; i < urlCount; i++) {
            check_url(urlStatusList[i].url, i);
        }
        log_status();
        sleep(CHECK_INTERVAL);
    }

    free_memory();
    return EXIT_SUCCESS;
}