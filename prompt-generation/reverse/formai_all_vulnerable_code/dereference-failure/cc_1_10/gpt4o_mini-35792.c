//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URLS 100
#define TIMEOUT 5 // timeout in seconds
#define CHECK_INTERVAL 60 // check every 60 seconds

typedef struct {
    char url[256];
    int status;
} Website;

void check_website(Website *website) {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website->url);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // Don't need body to just check status
        res = curl_easy_perform(curl);

        if(res == CURLE_OK) {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            website->status = (response_code == 200) ? 1 : 0; // 1 for up, 0 for down
        } else {
            website->status = 0; // Treat any curl error as down
        }

        curl_easy_cleanup(curl);
    }
}

void log_status(Website *website) {
    time_t now;
    time(&now);
    char *timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0'; // Remove newline character

    if (website->status) {
        printf("[%s] %s is UP\n", timestamp, website->url);
    } else {
        printf("[%s] %s is DOWN\n", timestamp, website->url);
    }
}

int main() {
    Website websites[MAX_URLS];
    int website_count = 0;
    char input[256];
    
    printf("Website Uptime Monitor\n");
    printf("Enter URLs to monitor (type 'done' to finish):\n");

    while (website_count < MAX_URLS) {
        printf("Enter URL: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        if (strcmp(input, "done") == 0) {
            break;
        }

        strcpy(websites[website_count++].url, input);
    }
    
    printf("Monitoring the following websites:\n");
    for (int i = 0; i < website_count; i++) {
        printf("%s\n", websites[i].url);
    }

    while (1) {
        for (int i = 0; i < website_count; i++) {
            check_website(&websites[i]);
            log_status(&websites[i]);
        }
        sleep(CHECK_INTERVAL);
    }

    return 0;
}