//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>


size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    FILE *fp = (FILE *)userp;
    return fwrite(contents, realsize, 1, fp);
}

int main(int argc, char *argv[]) {
    CURL *curl;
    FILE *fp;
    CURLcode res;
    char url[100];

    if(argc!= 2) {
        printf("Usage: %s <url>\n", argv[0]);
        exit(1);
    }

    strcpy(url, argv[1]);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        fp = fopen("response.txt", "wb");
        if(!fp) {
            printf("Failed to open file\n");
            exit(1);
        }

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK) {
            printf("Failed to perform request: %s\n", curl_easy_strerror(res));
            exit(1);
        }

        fclose(fp);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}