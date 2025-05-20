//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <time.h>

#define SLEEP_TIME 10 // 10 seconds

// Function to calculate current time in HH:MM:SS format
char *getCurrentTime() {
    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    char *timeStr = malloc(9 * sizeof(char));
    sprintf(timeStr, "%02d:%02d:%02d", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

    return timeStr;
}

// Function to handle CURL errors
void curlError(CURLcode res) {
    fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
}

int main() {
    CURL *curl;
    CURLcode res;
    char *url = "https://www.google.com";
    char *timeStr;

    // Initialize CURL handle
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if(curl) {
        while(1) {
            curl_easy_setopt(curl, CURLOPT_URL, url);
            curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // Send HEAD request to check response time
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

            res = curl_easy_perform(curl);

            if(res != CURLE_OK) {
                curlError(res);
            }
            else {
                double responseTime;
                curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &responseTime);

                timeStr = getCurrentTime();
                printf("%s | %s is up | Response time: %.2f seconds\n", timeStr, url, responseTime);
                free(timeStr);
            }

            sleep(SLEEP_TIME);
        }

        // Cleanup CURL handle
        curl_easy_cleanup(curl);
    }

    // Cleanup CURL library
    curl_global_cleanup();

    return 0;
}