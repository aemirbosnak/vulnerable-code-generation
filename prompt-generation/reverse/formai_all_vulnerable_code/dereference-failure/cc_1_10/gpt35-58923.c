//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <curl/curl.h>

// define website URLs to be checked
char *urls[] = {
    "https://www.google.com",
    "https://www.facebook.com",
    "https://www.twitter.com",
    "https://www.linkedin.com",
    "https://www.instagram.com",
};

// define a struct to hold website status information
struct website_status {
    char *url;
    int status_code;
    bool is_running;
};

// callback function for curl_easy_setopt to get response code
static size_t response_code_callback(void *buffer, size_t size, size_t nmemb, void *userdata) {
    int *response_code = userdata;
    char *resp_str = buffer;
    char *endptr;
    *response_code = strtol(resp_str, &endptr, 10);
    return size * nmemb;
}

// function to check website status using libcurl
void check_website_status(char *url, struct website_status *status) {
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, response_code_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &status->status_code);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "Failed to check website status for %s: %s\n", url, curl_easy_strerror(res));
            status->is_running = false;
        } else {
            if (status->status_code == 200) {
                status->is_running = true;
            } else {
                status->is_running = false;
            }
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

int main(int argc, char **argv) {
    struct website_status *statuses = calloc(sizeof(struct website_status), sizeof(urls)/sizeof(urls[0]));
    size_t i;
    while (true) {
        for (i=0; i < sizeof(urls)/sizeof(urls[0]); i++) {
            check_website_status(urls[i], &statuses[i]);
            if (statuses[i].is_running) {
                printf("%s is running!\n", urls[i]);
            } else {
                printf("%s is down!\n", urls[i]);
            }
        }
        printf("---------------\n");
        sleep(60);
    }
    free(statuses);
    return 0;
}