//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <curl/curl.h>

#define MAX_URLS 10
#define BUFFER_SIZE 256
#define TIMEOUT 5
#define LOG_FILE "uptime_log.txt"

typedef struct {
    char *url;
    int status; // 0 for down, 1 for up
} Monitor;

// Function Declarations
void log_status(const char *url, int status);
size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata);
int check_url(const char *url);

int main() {
    Monitor monitors[MAX_URLS];
    char *urls[MAX_URLS] = {
        "http://example.com",
        "http://openai.com",
        "http://github.com",
        "http://nonexistentwebsite.xyz",
        "http://stackoverflow.com",
        NULL
    };

    for(int i = 0; urls[i] != NULL && i < MAX_URLS; i++) {
        monitors[i].url = urls[i];
        monitors[i].status = -1; // Unknown initial status
    }

    while (1) {
        for (int i = 0; urls[i] != NULL && i < MAX_URLS; i++) {
            int current_status = check_url(monitors[i].url);
            if (current_status != monitors[i].status) {
                monitors[i].status = current_status;
                log_status(monitors[i].url, current_status);
            }
            sleep(TIMEOUT);
        }
    }
    
    return 0;
}

int check_url(const char *url) {
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        res = curl_easy_perform(curl);
        long response_code;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        
        curl_easy_cleanup(curl);
        
        if (res != CURLE_OK) {
            return 0; // URL is down
        }
        return (response_code == 200) ? 1 : 0; // URL is up or down
    }
    return 0; // CURL failed, URL presumed down
}

size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata) {
    // Not used but required for functionality
    return size * nmemb;
}

void log_status(const char *url, int status) {
    FILE *fp = fopen(LOG_FILE, "a");
    if (fp == NULL) {
        perror("Failed to open log file");
        return;
    }
    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0'; // Remove newline

    if (status == 1) {
        fprintf(fp, "[%s] %s is UP\n", timestamp, url);
    } else {
        fprintf(fp, "[%s] %s is DOWN\n", timestamp, url);
    }
    fclose(fp);
}