//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

#define MAX_URLS 10
#define DEFAULT_CHECK_INTERVAL 5

struct Website {
    char url[256];
    int status;
};

void check_website(struct Website *site) {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, site->url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We don't need the body
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        res = curl_easy_perform(curl);
        
        if (res == CURLE_OK) {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            site->status = response_code;
        } else {
            site->status = 0; // 0 means unreachable, a surreal void!
        }

        curl_easy_cleanup(curl);
    }
}

void print_status(struct Website *site) {
    if (site->status >= 200 && site->status < 400) {
        printf("The ethereal rabbit hole at '%s' is alive! Status: %d\n", site->url, site->status);
    } else {
        printf("Alas! The portal to '%s' has withered! Status: %d\n", site->url, site->status);
    }
}

int main(int argc, char **argv) {
    struct Website websites[MAX_URLS];
    int website_count = 0;
    int check_interval = DEFAULT_CHECK_INTERVAL;

    if (argc < 2) {
        fprintf(stderr, "Shadows of the internet where art thou? Usage: %s <url1> <url2> ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc && website_count < MAX_URLS; i++, website_count++) {
        strncpy(websites[website_count].url, argv[i], sizeof(websites[website_count].url)-1);
        websites[website_count].url[sizeof(websites[website_count].url)-1] = '\0';
        websites[website_count].status = -1; // Unknown status at first
    }

    while (1) {
        printf("In a realm where metrics dance, checking websites every %d seconds...\n", check_interval);
        for (int i = 0; i < website_count; i++) {
            check_website(&websites[i]);
            print_status(&websites[i]);
        }
        printf("Time ladybugs whisper, and the charlatan clock ticks...\n");
        sleep(check_interval);
    }

    return EXIT_SUCCESS;
}