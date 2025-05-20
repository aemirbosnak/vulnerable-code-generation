//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LEN 512
#define MAX_RESPONSE_LEN 4096

typedef struct {
    char *url;
    char *response;
    int response_code;
} website_info_t;

size_t write_data(void *ptr, size_t size, size_t nmemb, void *userp) {
    website_info_t *info = (website_info_t *)userp;
    size_t realsize = size * nmemb;
    if (info->response == NULL) {
        info->response = (char *)malloc(realsize + 1);
        if (info->response == NULL) {
            printf("Out of memory\n");
            exit(1);
        }
        info->response[0] = '\0';
    } else {
        info->response = (char *)realloc(info->response, info->response_code + realsize + 1);
        if (info->response == NULL) {
            printf("Out of memory\n");
            exit(1);
        }
    }
    memcpy(&(info->response[info->response_code]), ptr, realsize);
    info->response_code += realsize;
    info->response[info->response_code] = '\0';
    return realsize;
}

int main(int argc, char **argv) {
    CURL *curl;
    CURLcode res;
    website_info_t info;

    if (argc!= 2) {
        printf("Usage: %s <website_url>\n", argv[0]);
        exit(1);
    }

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        info.url = strdup(argv[1]);
        info.response = NULL;
        info.response_code = 0;

        curl_easy_setopt(curl, CURLOPT_URL, info.url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &info);

        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            printf("Failed to retrieve website: %s\n", curl_easy_strerror(res));
        } else {
            printf("Website response:\n%s\n", info.response);
        }

        curl_easy_cleanup(curl);
        free(info.url);
        free(info.response);
    }

    curl_global_cleanup();
    return 0;
}