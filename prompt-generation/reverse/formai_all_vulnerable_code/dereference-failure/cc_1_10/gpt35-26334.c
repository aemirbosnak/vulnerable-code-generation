//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: synchronous
#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void checkWebsite(char *url) {
    CURL *curl;
    CURLcode response_code;
    char error_buffer[CURL_ERROR_SIZE];
    char *current_time;
    time_t raw_time;
    struct tm *time_info;
    
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, error_buffer);
        response_code = curl_easy_perform(curl);
        
        if (response_code != CURLE_OK) {
            printf("%s Error: Unable to connect to %s | Error: %s \n", current_time, url, error_buffer);
        } else {
            printf("%s Success: %s is up and running!\n", current_time, url);
        }
        
        curl_easy_cleanup(curl);
    } else {
        printf("Error: Unable to initialize curl");
    }
}

int main(int argc, char *argv[]) {
    char *websites[3] = {"https://www.google.com", "https://www.yahoo.com", "https://www.facebook.com"};
    char *current_time;
    time_t raw_time;
    struct tm *time_info;
    int i;
    
    while(1) {
        time(&raw_time);
        time_info = localtime(&raw_time);
        current_time = asctime(time_info);
        current_time[strlen(current_time) - 1] = '\0';
        
        for (i = 0; i < 3; i++) {
            checkWebsite(websites[i]);
        }
        
        sleep(60);
    }
    
    return 0;
}