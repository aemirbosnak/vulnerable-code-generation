//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>
#include <unistd.h>

#define MAX_URLS 10
#define CHECK_INTERVAL 10 // seconds

typedef struct {
    char *url;
    int status; // 1 for up, 0 for down
} Monitor;

void log_status(Monitor *monitor) {
    FILE *log_file = fopen("uptime_log.txt", "a");
    if (log_file == NULL) {
        perror("Unable to open log file!");
        return;
    }
    time_t now = time(NULL);
    char *time_str = ctime(&now);
    // remove newline character from ctime result
    time_str[strcspn(time_str, "\n")] = 0;
    
    fprintf(log_file, "[%s] %s is %s\n", time_str, monitor->url,
            monitor->status ? "UP" : "DOWN");
    fclose(log_file);
}

int check_website(const char *url) {
    CURL *curl;
    CURLcode res;
    int status_code = 0;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // we don't need the body
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        // Perform the request
        res = curl_easy_perform(curl);

        if(res == CURLE_OK) {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status_code);
        } else {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }
    return (status_code >= 200 && status_code < 400) ? 1 : 0; // 1 for up, 0 for down
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <url1> [<url2> ... <urlN>]\n", argv[0]);
        return EXIT_FAILURE;
    }

    Monitor monitors[MAX_URLS];
    int monitor_count = argc - 1;

    for (int i = 0; i < monitor_count; i++) {
        monitors[i].url = argv[i + 1];
        monitors[i].status = 1; // assume all are up initially
    }

    // Initialize libcurl
    curl_global_init(CURL_GLOBAL_DEFAULT);

    while (1) {
        for (int i = 0; i < monitor_count; i++) {
            int current_status = check_website(monitors[i].url);
            if (current_status != monitors[i].status) {
                monitors[i].status = current_status;
                log_status(&monitors[i]);
                if (current_status == 0) {
                    fprintf(stderr, "Alert: %s is DOWN!\n", monitors[i].url);
                } else {
                    fprintf(stdout, "Info: %s is UP!\n", monitors[i].url);
                }
            }
        }
        sleep(CHECK_INTERVAL);
    }

    curl_global_cleanup();
    return EXIT_SUCCESS;
}