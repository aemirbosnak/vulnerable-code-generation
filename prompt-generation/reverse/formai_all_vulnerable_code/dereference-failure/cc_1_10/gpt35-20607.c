//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 100
#define MAX_TIMEOUT 10

// Function to check website status
int checkWebsite(char* url) {
    CURL* curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, MAX_TIMEOUT);
    CURLcode code = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    return code;
}

// Function to get current date and time
char* currentTime() {
    time_t t = time(NULL);
    char* ctime = asctime(localtime(&t));
    ctime[strlen(ctime)-1] = '\0';
    return ctime;
}

int main() {
    char urls[][MAX_URL_LENGTH] = {
        "https://www.google.com",
        "https://www.facebook.com",
        "https://www.twitter.com",
        "https://www.instagram.com",
        "https://www.linkedin.com"
    };
    int num_urls = sizeof(urls)/MAX_URL_LENGTH;
    int status[num_urls];
    int down[num_urls];
    int i, j;
    for(i=0; i<num_urls; i++) {
        status[i] = 0;
        down[i] = 0;
    }
    printf("Website Uptime Monitor\n");
    printf("======================\n");
    while(1) {
        printf("\nCurrent Time: %s\n", currentTime());
        printf("----------------------------------------------------------\n");
        for(i=0; i<num_urls; i++) {
            status[i] = checkWebsite(urls[i]);
            if(status[i] == 0 && down[i] == 0) {
                printf("%s is UP!\n", urls[i]);
            } else if(status[i] != 0 && down[i] == 0) {
                printf("%s is DOWN!\n", urls[i]);
                down[i] = 1;
            } else if(status[i] == 0 && down[i] == 1) {
                printf("%s is UP again!\n", urls[i]);
                down[i] = 0;
            }
        }
        printf("----------------------------------------------------------\n");
        printf("Press Ctrl+C to exit...\n");
        sleep(60);
    }
    return 0;
}