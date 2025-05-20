//Falcon2-11B DATASET v1.0 Category: Website Uptime Monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curl/curl.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

void check_uptime(char* url, int retry_count) {
    int retries = retry_count;
    struct timeval start_time;
    struct timeval end_time;
    struct timeval cur_time;
    char* response;

    while (retries > 0) {
        gettimeofday(&start_time, NULL);

        retries--;

        CURL *curl;
        CURLcode res;
        curl_global_init(CURL_GLOBAL_ALL);
        curl = curl_easy_init();

        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
            curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, 1000);
            curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT_MS, 1000);
            res = curl_easy_perform(curl);

            if (res == CURLE_OK) {
                gettimeofday(&end_time, NULL);
                long diff_time = (end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_usec - start_time.tv_usec) / 1000;
                if (diff_time < 1000) {
                    printf("Uptime: %ld ms\n", diff_time);
                    return;
                }
            } else {
                printf("Error: %s\n", curl_easy_strerror(res));
            }
        }

        gettimeofday(&cur_time, NULL);
        usleep(50000);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <url> <retry_count>\n", argv[0]);
        return 1;
    }

    char* url = argv[1];
    int retry_count = atoi(argv[2]);

    check_uptime(url, retry_count);

    curl_global_cleanup();
    return 0;
}