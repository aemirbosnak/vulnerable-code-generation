//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

typedef struct {
    char *url;
    char *method;
    char *headers;
    char *body;
    char *response;
} http_request_t;

typedef struct {
    char *header;
    char *value;
} http_header_t;

size_t write_data(void *ptr, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    http_request_t *request = (http_request_t *)userp;

    if (request->response == NULL) {
        request->response = malloc(realsize + 1);
        if (request->response == NULL) {
            printf("Out of memory!\n");
            exit(1);
        }
    } else {
        request->response = realloc(request->response, strlen(request->response) + realsize + 1);
    }

    memcpy(&request->response[strlen(request->response)], ptr, realsize);
    request->response[strlen(request->response) + realsize] = '\0';

    return realsize;
}

int http_client(http_request_t *request)
{
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, request->url);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, request->method);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, request->headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, request->body);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, request);

        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return res;
}

int main(int argc, char *argv[])
{
    http_request_t request;

    if (argc < 2) {
        printf("Usage: %s <method> <url> [<header>] [<body>]\n", argv[0]);
        exit(1);
    }

    request.method = argv[1];
    request.url = argv[2];

    if (argc > 3) {
        request.headers = argv[3];
    } else {
        request.headers = strdup("");
    }

    if (argc > 4) {
        request.body = argv[4];
    } else {
        request.body = strdup("");
    }

    http_client(&request);

    printf("Response:\n%s\n", request.response);

    return 0;
}