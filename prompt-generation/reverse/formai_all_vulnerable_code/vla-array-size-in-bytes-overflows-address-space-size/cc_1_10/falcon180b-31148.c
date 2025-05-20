//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<curl/curl.h>
#include<time.h>

#define MAX_URL_SIZE 1024
#define CHECK_INTERVAL 60 // Check website uptime every one minute.

typedef struct {
    char url[MAX_URL_SIZE];
    int is_up;
    time_t last_check;
} website_t;

void init_curl() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
}

size_t write_data(void* buffer, size_t size, size_t nmemb, void* userp) {
    char* data = (char*) buffer;
    size_t len = size * nmemb;
    printf("%s", data);
    return len;
}

int check_website_uptime(website_t* website) {
    CURL* curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            fprintf(stderr, "Failed to check website %s: %s\n", website->url, curl_easy_strerror(res));
        } else {
            website->is_up = 1;
            website->last_check = time(NULL);
        }
        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Failed to initialize curl\n");
    }

    return 0;
}

int main() {
    int num_websites;
    scanf("%d", &num_websites);

    website_t websites[num_websites];

    for(int i=0; i<num_websites; i++) {
        scanf("%s", websites[i].url);
        websites[i].is_up = 0;
        websites[i].last_check = 0;
    }

    while(1) {
        time_t current_time = time(NULL);

        for(int i=0; i<num_websites; i++) {
            if((current_time - websites[i].last_check) >= CHECK_INTERVAL) {
                check_website_uptime(&websites[i]);
            }
        }

        sleep(1);
    }

    return 0;
}