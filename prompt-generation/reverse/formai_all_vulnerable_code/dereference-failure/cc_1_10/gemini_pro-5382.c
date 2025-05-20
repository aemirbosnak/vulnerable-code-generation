//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URLS 100

typedef struct {
    char *url;
    time_t last_checked;
    int status_code;
} url_info;

url_info urls[MAX_URLS];

int num_urls = 0;

void add_url(char *url) {
    if (num_urls >= MAX_URLS) {
        fprintf(stderr, "Error: Too many URLs specified\n");
        exit(1);
    }

    urls[num_urls].url = strdup(url);
    urls[num_urls].last_checked = 0;
    urls[num_urls].status_code = 0;

    num_urls++;
}

void check_urls() {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Error: Failed to initialize CURL\n");
        exit(1);
    }

    for (int i = 0; i < num_urls; i++) {
        if (time(NULL) - urls[i].last_checked >= 60) {
            curl_easy_setopt(curl, CURLOPT_URL, urls[i].url);
            curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
            res = curl_easy_perform(curl);
            if (res != CURLE_OK) {
                fprintf(stderr, "Error: Failed to check URL %s (%s)\n", urls[i].url, curl_easy_strerror(res));
            } else {
                long response_code;
                curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
                urls[i].status_code = (int)response_code;
            }
            urls[i].last_checked = time(NULL);
        }
    }

    curl_easy_cleanup(curl);
}

void print_results() {
    for (int i = 0; i < num_urls; i++) {
        printf("%s: %d\n", urls[i].url, urls[i].status_code);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <URL1> <URL2> ...\n", argv[0]);
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        add_url(argv[i]);
    }

    while (1) {
        check_urls();
        print_results();

        sleep(60);
    }

    return 0;
}