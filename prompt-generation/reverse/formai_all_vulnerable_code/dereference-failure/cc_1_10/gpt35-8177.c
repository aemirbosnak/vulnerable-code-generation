//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <curl/curl.h>

#define WEBSITE_URL "https://example.com"
#define TIMEOUT_SECONDS 10

bool check_website_availability(const char* url) {
    CURL* curl;
    CURLcode res;
    long response_code;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, TIMEOUT_SECONDS);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            printf("Error: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return false;
        }
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        curl_easy_cleanup(curl);
        if(response_code >= 200 && response_code < 300) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

int main() {
    int seconds = 60;
    bool website_available = false;
    printf("Website Uptime Monitor\n");
    while(true) {
        website_available = check_website_availability(WEBSITE_URL);
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        printf("[%04d-%02d-%02d %02d:%02d:%02d] %s is %s\n", 
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, 
            tm.tm_hour, tm.tm_min, tm.tm_sec, 
            WEBSITE_URL, website_available ? "UP" : "DOWN");
        sleep(seconds);
    }
    return 0;
}