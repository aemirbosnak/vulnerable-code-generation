//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: systematic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include <curl/curl.h>

#define MAX_URL_LEN 2048
#define MAX_BUF_LEN 16384

typedef struct {
    char *url;
    char *data;
    long response_code;
    char *response_body;
} http_request;

CURL *curl_handle;

int init_curl() {
    curl_handle = curl_easy_init();
    if (!curl_handle) {
        fprintf(stderr, "curl_easy_init() failed\n");
        return -1;
    }
    return 0;
}

void cleanup_curl() {
    curl_easy_cleanup(curl_handle);
}

int send_http_request(http_request *req) {
    CURLcode res;

    curl_easy_setopt(curl_handle, CURLOPT_URL, req->url);

    if (req->data) {
        curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, req->data);
        curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDSIZE, strlen(req->data));
    }

    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, fwrite);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &req->response_body);

    res = curl_easy_perform(curl_handle);
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        return -1;
    }

    curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &req->response_code);

    return 0;
}

int main(int argc, char *argv[]) {
    http_request req;
    int res;

    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Usage: %s <url> [<data>]\n", argv[0]);
        return -1;
    }

    if (init_curl() == -1) {
        return -1;
    }

    req.url = argv[1];
    if (argc == 3) {
        req.data = argv[2];
    } else {
        req.data = NULL;
    }

    res = send_http_request(&req);
    if (res == -1) {
        cleanup_curl();
        return -1;
    }

    printf("Response code: %ld\n", req.response_code);
    printf("Response body:%s", req.response_body);

    cleanup_curl();
    return 0;
}