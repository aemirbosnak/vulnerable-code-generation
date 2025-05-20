//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <curl/curl.h>

#define MAX_RESPONSE_SIZE 1024

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    char *msg = (char *)userp;
    if (msg) {
        memcpy(msg, contents, realsize + 1);
        msg += realsize;
        *msg-- = 0;
    }
    return realsize;
}

int main(int argc, char **argv) {
    CURL *curl;
    CURLcode res;
    char url[100];
    char *response;
    size_t response_size = MAX_RESPONSE_SIZE;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    strcpy(url, argv[1]);

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            printf("URL: %s\n", url);
            printf("Response size: %ld\n", (long)strlen(response));
            printf("Response:\n%s\n", response);
        }

        free(response);
        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Error initializing libcurl\n");
        return 1;
    }

    return 0;
}