//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URL_LEN 1024
#define MAX_RESPONSE_LEN 1024
#define MAX_ERROR_LEN 1024
#define CHECK_INTERVAL 60 // seconds

// Callback function to store response data
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t realsize = size * nmemb;
    char* data = (char*)malloc(realsize + 1);
    if (data == NULL) {
        fprintf(stderr, "Failed to allocate memory for response data\n");
        exit(1);
    }
    memcpy(data, contents, realsize);
    data[realsize] = '\0';
    *((char**)userp) = data;
    return realsize;
}

// Callback function to handle errors
void ErrorCallback(CURL* curl, curl_infotype type, char* data, size_t size, void* userp) {
    char error[MAX_ERROR_LEN];
    memset(error, 0, MAX_ERROR_LEN);
    if (data!= NULL) {
        strncpy(error, data, size);
    }
    fprintf(stderr, "Error: %s\n", error);
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        exit(1);
    }

    CURL* curl = curl_easy_init();
    if (curl == NULL) {
        fprintf(stderr, "Failed to initialize curl\n");
        exit(1);
    }

    char url[MAX_URL_LEN];
    strcpy(url, argv[1]);

    char* response = NULL;
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, response);

    int res = curl_easy_perform(curl);
    if (res!= CURLE_OK) {
        fprintf(stderr, "Failed to perform curl request: %s\n", response);
        exit(1);
    }

    curl_easy_cleanup(curl);
    free(response);

    return 0;
}