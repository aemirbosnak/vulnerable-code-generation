//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LEN 1024

void handle_http_request(CURL *curl, char *url) {
    CURLcode res;
    FILE *fp;
    char response[1024];

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &fp);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

    res = curl_easy_perform(curl);
    if (res!= CURLE_OK) {
        printf("Error: %s\n", curl_easy_strerror(res));
        return;
    }

    fclose(fp);
    fp = fopen(response, "rb");
    if (!fp) {
        perror("fopen");
        return;
    }

    fseek(fp, 0, SEEK_END);
    long len = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    response[len] = '\0';

    fclose(fp);

    printf("%s", response);
}

int main(int argc, char *argv[]) {
    CURL *curl;
    char url[MAX_URL_LEN];
    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    strncpy(url, argv[1], MAX_URL_LEN);
    curl = curl_easy_init();
    if (!curl) {
        perror("curl_easy_init");
        return 1;
    }

    handle_http_request(curl, url);

    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return 0;
}