//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>
#include <string.h>
#include <errno.h>

#define MAX_URL_LEN 512
#define MAX_HEADERS_LEN 1024
#define MAX_RESPONSE_LEN 2048
#define TIMEOUT 10

// Function to log errors
void log_error(char *error_msg) {
    fprintf(stderr, "Error: %s\n", error_msg);
}

// Function to log the response body
void log_response(char *response) {
    fprintf(stdout, "Response: %s\n", response);
}

// Function to perform a GET request and log the response
size_t write_response_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    char *response = (char *)malloc(size * nmemb);
    memcpy(response, ptr, size * nmemb);
    log_response(response);
    free(response);
    return size * nmemb;
}

// Function to check if the website is up
int check_website_up(char *url) {
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_response_callback);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            log_error(curl_easy_strerror(res));
            return 0;
        }
        curl_easy_cleanup(curl);
        return 1;
    } else {
        log_error("Failed to initialize curl");
        return 0;
    }
}

// Function to check the website at regular intervals
void check_website_interval(char *url, int interval_sec) {
    while(1) {
        if(check_website_up(url)) {
            printf("Website is up\n");
        } else {
            printf("Website is down\n");
        }
        sleep(interval_sec);
    }
}

int main(int argc, char *argv[]) {
    if(argc < 3) {
        log_error("Usage:./program <url> <interval_sec>");
        return 1;
    }

    char *url = argv[1];
    int interval_sec = atoi(argv[2]);

    check_website_interval(url, interval_sec);

    return 0;
}