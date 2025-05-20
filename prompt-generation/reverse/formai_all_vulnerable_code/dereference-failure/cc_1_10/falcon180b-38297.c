//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <pthread.h>

#define MAX_URL_LEN 1024
#define CHECK_INTERVAL 60 // in seconds

struct url_info {
    char url[MAX_URL_LEN];
    int is_up;
};

int check_website_status(struct url_info *url_info) {
    CURL *curl;
    CURLcode res;
    char readBuffer[1024];
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        sprintf(url_info->url, "http://%s", url_info->url);
        res = curl_easy_perform(curl);
        if(res!= CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        else {
            int response_code = 0;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            if(response_code >= 200 && response_code < 300)
                url_info->is_up = 1;
            else
                url_info->is_up = 0;
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return 0;
}

void *monitor_thread(void *arg) {
    struct url_info *url_info = (struct url_info *) arg;
    time_t last_check_time = time(NULL);

    while(1) {
        sleep(CHECK_INTERVAL);
        time_t current_time = time(NULL);
        if(current_time - last_check_time >= CHECK_INTERVAL) {
            check_website_status(url_info);
            last_check_time = current_time;
        }
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    struct url_info url_info;
    strcpy(url_info.url, argv[1]);

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, monitor_thread, &url_info);

    while(1) {
        sleep(1);
    }

    return 0;
}