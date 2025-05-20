//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/time.h>

#define URL "https://example.com"
#define INTERVAL 60
#define TIMEOUT 5

struct timeval start_time;

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

int main() {
    CURL *curl;
    FILE *fp;
    char readBuffer[1024];
    int status_code;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        fp = fopen("response.html", "w");
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        status_code = curl_easy_perform(curl);
        fclose(fp);
        curl_easy_cleanup(curl);
    }

    gettimeofday(&start_time, NULL);

    while(1) {
        sleep(INTERVAL);
        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();

        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, URL);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
            status_code = curl_easy_perform(curl);
            fclose(fp);
            curl_easy_cleanup(curl);

            if(status_code!= 200) {
                printf("Website is down\n");
            }
        }

        gettimeofday(&start_time, NULL);
    }

    return 0;
}