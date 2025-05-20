//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URL_LEN 1024
#define MAX_RESPONSE_LEN 1024 * 10

struct url_info {
    char *url;
    time_t last_check;
};

int main() {
    CURL *curl;
    FILE *fp;
    char readBuffer[MAX_RESPONSE_LEN];
    struct url_info urls[10];
    int num_urls = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (!curl) {
        fprintf(stderr, "curl_easy_init() failed\n");
        return 1;
    }

    fp = fopen("urls.txt", "r");
    if (!fp) {
        fprintf(stderr, "Failed to open urls.txt\n");
        curl_easy_cleanup(curl);
        curl_global_cleanup();
        return 1;
    }

    while (fgets(readBuffer, MAX_URL_LEN, fp)) {
        if (num_urls >= 10) {
            fprintf(stderr, "Reached maximum number of URLs (10)\n");
            break;
        }

        char *url = strtok(readBuffer, "\n");
        struct url_info *info = &urls[num_urls];

        info->url = strdup(url);
        info->last_check = 0;

        num_urls++;
    }

    fclose(fp);

    while (1) {
        time_t current_time = time(NULL);

        for (int i = 0; i < num_urls; i++) {
            struct url_info *info = &urls[i];

            if (current_time - info->last_check >= 60) {
                check_url(curl, info->url);
                info->last_check = current_time;
            }
        }

        sleep(60);
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    return size * nmemb;
}

int check_url(CURL *curl, char *url) {
    CURLcode res;

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);

    res = curl_easy_perform(curl);

    if (res!= CURLE_OK) {
        fprintf(stderr, "Failed to check URL '%s': %s\n", url, curl_easy_strerror(res));
        return 1;
    }

    return 0;
}