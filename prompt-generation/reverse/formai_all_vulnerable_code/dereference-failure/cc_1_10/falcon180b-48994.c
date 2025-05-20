//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>

#define MAX_URL_LENGTH 1024
#define CHECK_INTERVAL_SECONDS 60

typedef struct {
    char url[MAX_URL_LENGTH];
    char last_response[MAX_URL_LENGTH];
    time_t last_check_time;
} website_t;

void check_website(void *param) {
    website_t *website = (website_t *)param;
    CURL *curl;
    CURLcode res;
    char readBuffer[1024];

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        sprintf(website->url, "http://%s", website->url);
        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &website->last_response[0]);
            time(&website->last_check_time);
        }
        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "curl_easy_init() failed\n");
    }
}

int main(int argc, char *argv[]) {
    pthread_t threads[argc - 1];
    int i;

    for(i = 1; i < argc; i++) {
        website_t website;
        strcpy(website.url, argv[i]);
        website.last_response[0] = '\0';
        time(&website.last_check_time);

        pthread_create(&threads[i - 1], NULL, check_website, &website);
    }

    for(i = 0; i < argc - 1; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}