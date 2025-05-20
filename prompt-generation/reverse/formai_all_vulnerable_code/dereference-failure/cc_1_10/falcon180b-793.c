//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <ctype.h>

#define MAX_URL_LEN 2048
#define MAX_STATUS_CODE_LEN 32
#define MAX_RESPONSE_BODY_LEN 8192

typedef struct {
    char* url;
    char* status_code;
    char* response_body;
} Response;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    Response* response = (Response*)userp;
    size_t realsize = size * nmemb;
    char* ptr = (char*) malloc(realsize + 1);
    if (ptr == NULL) {
        return 0;
    }
    memcpy(ptr, contents, realsize);
    ptr[realsize] = '\0';
    if (response->response_body == NULL) {
        response->response_body = ptr;
    } else {
        response->response_body = realloc(response->response_body, strlen(response->response_body) + strlen(ptr) + 1);
        strcat(response->response_body, ptr);
    }
    return realsize;
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    CURL* curl = curl_easy_init();
    if (curl == NULL) {
        printf("Failed to initialize curl\n");
        return 1;
    }

    Response response = {0};
    response.url = argv[1];

    curl_easy_setopt(curl, CURLOPT_URL, response.url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    CURLcode res = curl_easy_perform(curl);
    if (res!= CURLE_OK) {
        printf("Failed to get response from %s: %s\n", response.url, curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        return 1;
    }

    curl_easy_cleanup(curl);

    int status_code_len = strlen(response.status_code);
    if (status_code_len == 3 && isdigit(response.status_code[0]) &&
        isdigit(response.status_code[1]) && isdigit(response.status_code[2])) {
        printf("Response status code: %d\n", atoi(response.status_code));
    } else {
        printf("Response status code: unknown\n");
    }

    printf("Response body:\n%s\n", response.response_body);

    free(response.url);
    free(response.status_code);
    free(response.response_body);

    return 0;
}