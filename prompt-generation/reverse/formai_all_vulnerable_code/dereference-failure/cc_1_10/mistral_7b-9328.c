//MISTRAL-7B DATASET v1.0 Category: Building a FTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <curl/curl.h>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    FILE *fp = (FILE *)userp;
    size_t written = fwrite(contents, size, realsize, fp);
    return written > 0 ? realsize - written : 0;
}

int main(int argc, char *argv[]) {
    CURL *curl;
    CURLcode res;
    FILE *fp;
    char *url;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ftp_address> <file_name>\n", argv[0]);
        exit(1);
    }

    curl = curl_easy_init();
    if(curl) {
        url = malloc(strlen(argv[1]) + strlen(argv[2]) + 2);
        sprintf(url, "%s/%s", argv[1], argv[2]);

        fp = fopen(argv[2], "wb");
        if(fp == NULL) {
            fprintf(stderr, "Error opening file '%s'\n", argv[2]);
            res = CURLE_FAILED_INIT;
        } else {
            curl_easy_setopt(curl, CURLOPT_URL, url);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

            res = curl_easy_perform(curl);
            if(res != CURLE_OK) {
                fprintf(stderr, "Failed to download file: %s\n", curl_easy_strerror(res));
                fclose(fp);
            }

            curl_easy_cleanup(curl);
            free(url);
        }

        fclose(fp);
    }

    curl_easy_cleanup(curl);

    return res != CURLE_OK ? 1 : 0;
}