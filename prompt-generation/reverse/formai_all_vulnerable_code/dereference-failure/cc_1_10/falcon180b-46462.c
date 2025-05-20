//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

#define MAX_URL_SIZE 2048
#define MAX_CONTENT_SIZE 1024 * 1024 * 10 // 10 MB

struct url_data {
    char *url;
    char *content;
    size_t content_len;
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    struct url_data *data = (struct url_data *) userp;
    size_t realsize = size * nmemb;

    if (data->content_len + realsize > MAX_CONTENT_SIZE) {
        fprintf(stderr, "Content too large\n");
        return 0;
    }

    memcpy(data->content + data->content_len, contents, realsize);
    data->content_len += realsize;

    return realsize;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    CURL *curl;
    CURLcode res;
    struct url_data data;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (!curl) {
        fprintf(stderr, "curl_easy_init() failed\n");
        return 1;
    }

    data.url = argv[1];
    data.content = NULL;
    data.content_len = 0;

    curl_easy_setopt(curl, CURLOPT_URL, data.url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);

    res = curl_easy_perform(curl);

    if (res!= CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
        return 1;
    }

    printf("Content length: %zu\n", data.content_len);
    printf("Content:\n%s", data.content);

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    free(data.content);
    free(data.url);

    return 0;
}