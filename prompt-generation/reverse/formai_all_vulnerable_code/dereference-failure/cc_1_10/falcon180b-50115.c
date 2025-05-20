//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

#define BUFFER_SIZE 1024

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    char *buffer = (char*)malloc(realsize + 1);
    if (buffer == NULL) {
        return 0;
    }
    memcpy(buffer, contents, realsize);
    buffer[realsize] = '\0';
    printf("%s", buffer);
    free(buffer);
    return realsize;
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <HTTP method> <URL>\n", argv[0]);
        return 1;
    }

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        char method[10];
        strcpy(method, argv[1]);
        curl_easy_setopt(curl, CURLOPT_URL, argv[2]);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            printf("curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}