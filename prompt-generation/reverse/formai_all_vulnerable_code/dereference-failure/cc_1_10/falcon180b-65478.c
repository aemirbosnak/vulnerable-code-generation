//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    size_t realsize = size * nmemb;
    char* data = (char*)malloc(realsize + 1);
    if (data) {
        memcpy(data, contents, realsize);
        data[realsize] = '\0';
        // do something with the data
        free(data);
    }
    return realsize;
}

int main(int argc, char* argv[])
{
    if (argc!= 4) {
        printf("Usage: %s <method> <url> <data>\n", argv[0]);
        return 1;
    }

    CURL* curl = curl_easy_init();
    if (!curl) {
        printf("Failed to initialize curl\n");
        return 1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, argv[2]);
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, argv[1]);
    if (strcmp(argv[1], "GET")!= 0 && strcmp(argv[1], "HEAD")!= 0) {
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, argv[3]);
    }
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

    CURLcode res = curl_easy_perform(curl);
    if (res!= CURLE_OK) {
        printf("curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
    } else {
        printf("Operation completed successfully\n");
    }

    curl_easy_cleanup(curl);
    return 0;
}