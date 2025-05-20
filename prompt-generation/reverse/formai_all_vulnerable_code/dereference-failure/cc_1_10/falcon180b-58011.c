//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((char *)userp)[size * nmemb - 1] = '\0';
    return size * nmemb;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <server_url>\n", argv[0]);
        return 1;
    }

    CURL *curl;
    CURLcode res;
    char url[100];
    char *server_url = argv[1];
    double download_speed = 0;
    double upload_speed = 0;
    double ping_time = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        strcpy(url, server_url);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &download_speed);
        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            double download_time = download_speed / (1024 * 1024);
            ping_time = download_time / 2;
            printf("Download Speed: %.2lf Mbps\n", download_speed / (1024 * 1024));
            printf("Upload Speed: %.2lf Mbps\n", upload_speed / (1024 * 1024));
            printf("Ping Time: %.2lf ms\n", ping_time);
        }
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}