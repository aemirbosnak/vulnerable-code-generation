//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define URL_SIZE 2048
#define STATUS_OK 200

void check_website(const char* url, CURL* curl){
    CURLcode res;
    long response_code;
    char time_str[26];
    struct tm* timeinfo;

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
    res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
        fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
        return;
    }

    res = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

    if (res != CURLE_OK || response_code != STATUS_OK) {
        fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
        return;
    }

    time_t current_time = time(NULL);
    timeinfo = localtime(&current_time);
    strftime(time_str, sizeof(time_str), "[%d/%b/%Y %H:%M:%S]", timeinfo);

    printf("%s %s is up\n", time_str, url);
}

int main(){
    CURL *curl;
    char url[URL_SIZE];
    int num_urls;

    printf("Enter number of websites to monitor: ");
    scanf("%d", &num_urls);

    char** urls = malloc(num_urls * sizeof(char*));

    for (int i = 0; i < num_urls; i++){
        printf("Enter a website URL to monitor: ");
        scanf("%s", url);
        urls[i] = strdup(url);
    }

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (!curl) {
        fprintf(stderr, "Error: Could not initialize curl\n");
        return 1;
    }

    printf("Monitoring websites every 5 seconds...\n");

    while (1) {
        for (int i = 0; i < num_urls; i++) {
            check_website(urls[i], curl);
        }

        sleep(5);
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    for (int i = 0; i < num_urls; i++){
        free(urls[i]);
    }

    free(urls);

    return 0;
}