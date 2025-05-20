//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URL_LENGTH 100
#define MAX_CHECK_FREQ_IN_SEC 300
#define MAX_TIME_IN_SEC_WITHOUT_RESPONSE 30

// function to get current time
char* getTime() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char* str = asctime(tm);
    str[strlen(str)-1] = '\0';
    return str;
}

// function to check url response
int check_url(char* url) {
    CURL *curl;
    CURLcode res;
    
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            curl_easy_cleanup(curl);
            return 1;
        }
    }
    curl_easy_cleanup(curl);
    return 0;
}

// main function
int main() {
    char urls[][MAX_URL_LENGTH] = {"https://www.google.com", "https://www.facebook.com", "https://www.github.com"};
    int n = sizeof(urls)/sizeof(urls[0]);
    int i, status[n];
    time_t last_checked_time;
    
    // init status to -1 to denote urls have not been checked yet
    for(i=0; i<n; i++) {
        status[i] = -1;
    }
    
    while(1) {
        for(i=0; i<n; i++) {
            // check url only if last checked time is greater than MAX_CHECK_FREQ_IN_SEC or first time
            if((status[i] == 0 && difftime(time(NULL), last_checked_time) > MAX_CHECK_FREQ_IN_SEC) || status[i] == -1) {
                printf("Checking %s...\n", urls[i]);
                if(check_url(urls[i])) {
                    printf("%s is up at %s\n", urls[i], getTime());
                    status[i] = 1;
                } else {
                    printf("%s is down at %s\n", urls[i], getTime());
                    status[i] = 0;
                }
                last_checked_time = time(NULL);
            }
            // check if url is still down even after MAX_TIME_IN_SEC_WITHOUT_RESPONSE
            if(status[i] == 0 && difftime(time(NULL), last_checked_time) > MAX_TIME_IN_SEC_WITHOUT_RESPONSE) {
                printf("%s is still down after %d seconds at %s\n", urls[i], MAX_TIME_IN_SEC_WITHOUT_RESPONSE, getTime());
                // send email to notify
                char command[MAX_URL_LENGTH + 50];
                sprintf(command, "echo 'Url %s is down at %s.' | mail -s 'Website Alert!!' you@example.com", urls[i], getTime());
                system(command);
                // reset status to -1 to denote urls have not been checked yet
                status[i] = -1;
            }
        }
        usleep(500000);
    }
    return 0;
}