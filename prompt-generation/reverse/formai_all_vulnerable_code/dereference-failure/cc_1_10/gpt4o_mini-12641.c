//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>

#define URL "http://example.com"
#define LOCK_PATH "/tmp/uptime_monitor.lock"
#define CHECK_INTERVAL 60

typedef struct {
    char *url;
    int status_code;
    char timestamp[20];
} Status;

void get_current_time(char *buffer, size_t size) {
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", tm_now);
}

int check_url(const char *url) {
    CURL *curl;
    CURLcode res;
    long response_code;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We don't need the body
        res = curl_easy_perform(curl);

        if(res == CURLE_OK) {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        } else {
            response_code = 0; // If it failed, we set a non-200 code
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return (int)response_code;
}

void log_status(Status *status) {
    FILE *log_file = fopen("status_log.txt", "a");
    if(log_file) {
        fprintf(log_file, "[%s] URL: %s - Status Code: %d\n", status->timestamp, status->url, status->status_code);
        fclose(log_file);
    }
}

int lock_monitor() {
    FILE *lock_file = fopen(LOCK_PATH, "w");
    if(lock_file) {
        fprintf(lock_file, "Monitor is running.\n");
        fclose(lock_file);
        return 1; // Lock acquired
    }
    return 0; // Lock not acquired
}

void unlock_monitor() {
    remove(LOCK_PATH);
}

int main() {
    char current_time[20];
    Status current_status;
    current_status.url = URL;

    if(!lock_monitor()) {
        printf("Another instance is already running. Please try again later.\n");
        return 1;
    }

    printf("Ah, sweet love! Let us watch over this digital beauty...\n");
    
    while (1) {
        get_current_time(current_time, sizeof(current_time));
        strcpy(current_status.timestamp, current_time);
        
        current_status.status_code = check_url(current_status.url);
        log_status(&current_status);

        if (current_status.status_code == 200) {
            printf("Oh joyful day! The love of my life (%s) is alive with a status code of %d!\n", current_status.url, current_status.status_code);
        } else {
            printf("Alas! My heart aches. The URL (%s) hath returned a status code of %d!\n", current_status.url, current_status.status_code);
        }

        sleep(CHECK_INTERVAL); // Wait before checking again
    }

    unlock_monitor();
    return 0;
}