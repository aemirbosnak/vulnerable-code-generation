//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: ephemeral
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

#define MAX_URLS 10
#define CHECK_INTERVAL 300

struct url_info {
    char *url;
    int status;
    char *last_response;
};

struct url_info urls[MAX_URLS];
int num_urls = 0;

void add_url(char *url) {
    if (num_urls < MAX_URLS) {
        urls[num_urls].url = malloc(strlen(url) + 1);
        strcpy(urls[num_urls].url, url);
        num_urls++;
    }
}

int check_url(struct url_info *url) {
    CURL *curl;
    CURLcode res;
    char buffer[1024];

    curl = curl_easy_init();
    if (!curl) {
        return -1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url->url);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, buffer);
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        url->status = -1;
        url->last_response = strdup(curl_easy_strerror(res));
    } else {
        url->status = 200;
        url->last_response = strdup(buffer);
    }

    curl_easy_cleanup(curl);

    return 0;
}

void print_results() {
    for (int i = 0; i < num_urls; i++) {
        printf("%s: %s\n", urls[i].url, urls[i].last_response);
    }
}

int main() {
    add_url("https://google.com");
    add_url("https://amazon.com");
    add_url("https://facebook.com");
    add_url("https://baidu.com");
    add_url("https://wikipedia.org");

    while (1) {
        for (int i = 0; i < num_urls; i++) {
            check_url(&urls[i]);
        }

        print_results();

        sleep(CHECK_INTERVAL);
    }

    return 0;
}