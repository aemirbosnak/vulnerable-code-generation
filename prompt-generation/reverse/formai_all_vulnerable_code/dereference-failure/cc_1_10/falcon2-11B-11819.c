//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

void send_http_request(char* url, char* method, char* headers, char* body) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();
    if (curl) {
        if (method) {
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method);
        }

        if (headers) {
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        }

        if (body) {
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body);
        }

        curl_easy_setopt(curl, CURLOPT_URL, url);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            fprintf(stderr, "HTTP request failed: %s\n",
                    curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <URL> <METHOD> <HEADERS> <BODY>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *url = argv[1];
    char *method = argv[2];
    char *headers = argv[3];
    char *body = argv[4];

    send_http_request(url, method, headers, body);

    return 0;
}