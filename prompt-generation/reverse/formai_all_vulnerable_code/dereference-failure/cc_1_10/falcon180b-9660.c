//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

#define MAX_URL_SIZE 2048
#define MAX_DATA_SIZE 1024 * 1024 * 10

typedef struct {
    char *url;
    char *data;
    size_t size;
} WebData;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    WebData *webData = (WebData *)userp;
    size_t newSize = webData->size + size * nmemb;
    webData->data = realloc(webData->data, newSize);
    if (webData->data == NULL) {
        return 0;
    }
    memcpy(webData->data + webData->size, contents, size * nmemb);
    webData->size += size * nmemb;
    return size * nmemb;
}

WebData *Download(const char *url) {
    CURL *curl;
    CURLcode res;
    WebData *webData = (WebData *)malloc(sizeof(WebData));
    if (webData == NULL) {
        return NULL;
    }
    webData->url = strdup(url);
    webData->data = NULL;
    webData->size = 0;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl == NULL) {
        free(webData->url);
        free(webData);
        return NULL;
    }
    curl_easy_setopt(curl, CURLOPT_URL, webData->url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, webData);
    res = curl_easy_perform(curl);
    if (res!= CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        free(webData->url);
        free(webData->data);
        free(webData);
        return NULL;
    }
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return webData;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return 1;
    }
    WebData *webData = Download(argv[1]);
    if (webData == NULL) {
        return 1;
    }
    printf("Downloaded %zu bytes from %s\n", webData->size, webData->url);
    free(webData->url);
    free(webData->data);
    free(webData);
    return 0;
}