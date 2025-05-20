//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <curl/curl.h>

typedef struct {
    char *url;
    char *name;
} Site;

void monitor_site(Site *site) {
    time_t current_time;
    char *formatted_time;
    int response_code;

    CURL *curl_handle = curl_easy_init();

    curl_easy_setopt(curl_handle, CURLOPT_URL, site->url);
    curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl_handle, CURLOPT_NOBODY, 1L);
    curl_easy_setopt(curl_handle, CURLOPT_CONNECTTIMEOUT, 5L);

    CURLcode res = curl_easy_perform(curl_handle);

    if (res == CURLE_OK) {
        curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &response_code);

        current_time = time(NULL);
        formatted_time = ctime(&current_time);
        formatted_time[strlen(formatted_time) - 1] = '\0';

        if (response_code == 200) {
            printf("[%s] %s is up (Response Code: %d)\n", formatted_time, site->name, response_code);
        } else {
            printf("[%s] %s is down (Response Code: %d)\n", formatted_time, site->name, response_code);
        }
    } else {
        printf("[%s] %s is down (Couldn't connect)\n", formatted_time, site->name);
    }

    curl_easy_cleanup(curl_handle);
}

int main() {
    Site sites[] = {
            {"https://www.google.com", "Google"},
            {"https://www.apple.com", "Apple"},
            {"https://www.microsoft.com", "Microsoft"},
    };

    int num_sites = sizeof(sites) / sizeof(sites[0]);

    while(1) {
        for (int i = 0; i < num_sites; i++) {
            monitor_site(&sites[i]);
        }

        sleep(10);
    }

    return 0;
}