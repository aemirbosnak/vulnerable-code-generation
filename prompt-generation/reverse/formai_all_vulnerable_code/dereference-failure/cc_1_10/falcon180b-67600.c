//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_SIZE 2048
#define MAX_FAILURE_COUNT 3
#define SLEEP_TIME_SEC 60

typedef struct {
    char *url;
    int failure_count;
    time_t last_failure;
} Website;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((char*)userp)[strlen((char*)userp)] = '\0';
    return size * nmemb;
}

static int ProgressCallback(void *clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow) {
    return 0;
}

int main(int argc, char *argv[]) {
    CURL *curl;
    FILE *fp;
    char buffer[MAX_URL_SIZE];
    Website website;

    if (argc!= 2) {
        printf("Usage: %s <website_url>\n", argv[0]);
        return 1;
    }

    strcpy(website.url, argv[1]);
    website.failure_count = 0;
    time(&website.last_failure);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website.url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &website);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, ProgressCallback);

        CURLcode res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            website.failure_count++;
            time(&website.last_failure);

            if (website.failure_count >= MAX_FAILURE_COUNT) {
                printf("Website '%s' is down for more than %d times.\n", website.url, MAX_FAILURE_COUNT);
            }

            fp = fopen("website_down.log", "a");
            if (fp) {
                fprintf(fp, "%s is down at %s\n", website.url, ctime(&website.last_failure));
                fclose(fp);
            }
        } else {
            website.failure_count = 0;
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}