//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 4096

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t realsize = size * nmemb;
    char* data = (char*) malloc(realsize + 1);
    if (data == NULL) {
        return 0;
    }
    memcpy(data, contents, realsize);
    data[realsize] = '\0';
    *(char**) userp = data;
    return realsize;
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if (curl == NULL) {
        fprintf(stderr, "curl_easy_init() failed\n");
        return 1;
    }

    char url[MAX_URL_LENGTH];
    strcpy(url, argv[1]);

    res = curl_easy_setopt(curl, CURLOPT_URL, url);
    if (res!= CURLE_OK) {
        fprintf(stderr, "curl_easy_setopt(CURLOPT_URL) failed: %s\n",
                curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        return 1;
    }

    res = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    if (res!= CURLE_OK) {
        fprintf(stderr, "curl_easy_setopt(CURLOPT_WRITEFUNCTION) failed: %s\n",
                curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        return 1;
    }

    res = curl_easy_perform(curl);
    if (res!= CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        return 1;
    }

    char* response = NULL;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response);

    printf("Response code: %s\n", response);

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}