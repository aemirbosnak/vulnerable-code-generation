//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_SIZE 1024
#define MAX_DATA_SIZE 1024 * 1024

struct SpeedTestResult {
    double download_speed;
    double upload_speed;
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    char *ptr = (char *)userp;
    size_t realsize = size * nmemb;
    if (realsize > MAX_DATA_SIZE - strlen(ptr)) {
        return 0;
    }
    memcpy(ptr, contents, realsize);
    ptr[realsize] = '\0';
    return realsize;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <server_url>\n", argv[0]);
        return 1;
    }

    CURL *curl;
    CURLcode res;
    struct SpeedTestResult result;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        char url[MAX_URL_SIZE];
        strcpy(url, argv[1]);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result.download_speed);

        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}