//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URLS 100
#define TIMEOUT 5
#define LOG_FILE "uptime_log.txt"

void write_log(const char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file != NULL) {
        fprintf(file, "%s\n", message);
        fclose(file);
    } else {
        perror("Could not open log file");
    }
}

int check_url(const char *url) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        curl_easy_setopt(curl, CURLOPT_CONNECT_ONLY, 1L); // Check connection only
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    
    curl_global_cleanup();

    if (res != CURLE_OK) {
        return 0; // URL is down
    }
    return 1; // URL is up
}

void monitor_urls(const char *urls[], int count) {
    for (int i = 0; i < count; i++) {
        int status = check_url(urls[i]);
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        
        char log_message[256];
        snprintf(log_message, sizeof(log_message),
                 "%04d-%02d-%02d %02d:%02d:%02d - URL: %s is %s",
                 t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
                 t->tm_hour, t->tm_min, t->tm_sec,
                 urls[i], (status ? "UP" : "DOWN"));

        write_log(log_message);
        printf("%s\n", log_message);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <url1> <url2> ... <urlN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *urls[MAX_URLS];
    int url_count = argc - 1;

    for (int i = 0; i < url_count; i++) {
        urls[i] = argv[i + 1];
    }

    while (1) {
        monitor_urls(urls, url_count);
        sleep(60); // Check every 60 seconds
    }

    return EXIT_SUCCESS;
}