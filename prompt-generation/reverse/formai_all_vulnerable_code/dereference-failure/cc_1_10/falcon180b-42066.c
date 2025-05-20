//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/time.h>
#include <time.h>

#define MAX_URL_LENGTH 1024
#define MAX_RESPONSE_LENGTH (1024 * 1024)
#define CHECK_INTERVAL 60 // seconds

typedef struct {
    char url[MAX_URL_LENGTH];
    time_t last_check;
    time_t last_response;
    int response_code;
    char response[MAX_RESPONSE_LENGTH];
} website_t;

void init_curl() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
}

size_t write_data(void *ptr, size_t size, size_t nmemb, void *userp) {
    website_t *website = (website_t *)userp;
    if (website->response_code == 200) {
        strncat(website->response, (char *)ptr, size * nmemb);
    }
    return size * nmemb;
}

int check_website(website_t *website) {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, website);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }

    if (website->response_code == 200) {
        website->last_response = time(NULL);
        return 1;
    }

    return 0;
}

void log_website_status(website_t *website) {
    time_t now = time(NULL);
    time_t elapsed = now - website->last_response;

    if (elapsed <= CHECK_INTERVAL) {
        printf("Website %s is up. Last response at %ld seconds ago.\n",
               website->url, elapsed);
    } else {
        printf("Website %s is down. Last response at %ld seconds ago.\n",
               website->url, elapsed);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <website_url>\n", argv[0]);
        return 1;
    }

    website_t website;
    strncpy(website.url, argv[1], MAX_URL_LENGTH);
    website.last_check = time(NULL);
    website.last_response = 0;
    website.response_code = 0;
    strcpy(website.response, "");

    while (1) {
        sleep(CHECK_INTERVAL);
        init_curl();
        check_website(&website);
        log_website_status(&website);
    }

    return 0;
}