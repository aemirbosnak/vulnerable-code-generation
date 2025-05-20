//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <unistd.h>
#include <time.h>

#define URL "https://example.com" // Replace with your website URL
#define TIMEOUT 10 // Timeout for connection in seconds
#define INTERVAL 5 // Time interval between checks in seconds

// Function to check website uptime
int check_uptime() {
    CURL *curl;
    CURLcode res;
    long code;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            printf("Error: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return 0;
        }
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &code);
        curl_easy_cleanup(curl);
        if(code == 200) {
            return 1;
        }
        return 0;
    }
    return 0;
}

// Function to print current date and time
void print_time() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    printf("%02d:%02d:%02d ", tm->tm_hour, tm->tm_min, tm->tm_sec);
}

// Main function
int main() {
    int uptime = 1;
    while(1) {
        int current_uptime = check_uptime();
        if(current_uptime != uptime) {
            print_time();
            if(current_uptime) {
                printf("Website is back up!\n");
            } else {
                printf("Website is down!\n");
            }
            uptime = current_uptime;
        }
        sleep(INTERVAL);
    }
    return 0;
}