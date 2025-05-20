//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <stdbool.h>

// Function to check if a website is up or down
bool is_website_up(char *url) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT_MS, 5000);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, 5000);
        res = curl_easy_perform(curl);

        if (res == CURLE_OK) {
            printf("Website is up\n");
            return true;
        } else {
            printf("Website is down\n");
            return false;
        }
    } else {
        printf("Error initializing curl\n");
        return false;
    }
}

// Function to get the current time in a formatted string
char *get_current_time() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    char time_str[80];
    strftime(time_str, 80, "%Y-%m-%d %H:%M:%S", t);

    return strdup(time_str);
}

// Function to log website status to a file
void log_website_status(char *url, bool is_up) {
    FILE *log_file;
    char log_entry[160];

    log_file = fopen("website_status.log", "a");

    if (log_file) {
        sprintf(log_entry, "%s %s\n", is_up? "UP" : "DOWN", url);
        fwrite(log_entry, strlen(log_entry), 1, log_file);
        fclose(log_file);
    } else {
        printf("Error opening log file\n");
    }
}

int main(int argc, char *argv[]) {
    char *url = argv[1];
    int interval_secs = atoi(argv[2]);

    while (true) {
        bool is_up = is_website_up(url);

        char *time_str = get_current_time();
        printf("%s Website status: %s\n", time_str, is_up? "UP" : "DOWN");

        log_website_status(url, is_up);

        sleep(interval_secs);
    }

    return 0;
}