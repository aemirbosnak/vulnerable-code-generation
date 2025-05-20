//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_SIZE 1024
#define MAX_RESPONSE_SIZE 10240

struct url_info {
    char url[MAX_URL_SIZE];
    char response[MAX_RESPONSE_SIZE];
    int response_length;
    int response_code;
};

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    struct url_info* url_info = (struct url_info*)userp;
    size_t realsize = size * nmemb;
    if (url_info->response_length + realsize > MAX_RESPONSE_SIZE) {
        realsize = MAX_RESPONSE_SIZE - url_info->response_length;
    }
    memcpy(&url_info->response[url_info->response_length], contents, realsize);
    url_info->response_length += realsize;
    return realsize;
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    struct url_info url_info;
    strncpy(url_info.url, argv[1], MAX_URL_SIZE);
    url_info.response_length = 0;

    CURL* curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url_info.url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &url_info);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    printf("URL: %s\n", url_info.url);
    printf("Response Code: %d\n", url_info.response_code);
    printf("Response:\n%s\n", url_info.response);

    return 0;
}