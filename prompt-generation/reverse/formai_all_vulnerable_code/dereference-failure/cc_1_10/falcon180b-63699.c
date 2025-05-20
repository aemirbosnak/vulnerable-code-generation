//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LEN 1024
#define MAX_RESPONSE_LEN 1024
#define MAX_ERROR_LEN 256

typedef struct {
    char *url;
    char *response;
    char *error;
} url_info_t;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    url_info_t *info = (url_info_t *)userp;
    char *response = (char *)malloc(size * nmemb);
    if (response == NULL) {
        info->error = "Out of memory";
        return 0;
    }
    memcpy(response, contents, size * nmemb);
    info->response = response;
    return size * nmemb;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    CURL *curl;
    CURLcode res;
    char *url = argv[1];
    url_info_t info = {.url = url };

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl == NULL) {
        info.error = "Failed to initialize curl";
        goto error;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &info);

    res = curl_easy_perform(curl);
    if (res!= CURLE_OK) {
        info.error = curl_easy_strerror(res);
        goto error;
    }

    printf("URL: %s\nResponse:\n%s\n", info.url, info.response);

    curl_easy_cleanup(curl);
    curl_global_cleanup();
    free(info.response);
    free(info.error);

    return 0;

error:
    printf("Error: %s\n", info.error);
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    free(info.response);
    free(info.error);
    return 1;
}