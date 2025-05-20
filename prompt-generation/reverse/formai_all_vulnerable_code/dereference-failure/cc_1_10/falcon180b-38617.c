//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 512
#define MAX_RESPONSE_LENGTH 1024

typedef struct {
    char *url;
    char *response;
    int response_length;
    int status_code;
} Response;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    Response *response = (Response *)userp;

    if (response->response_length + size * nmemb > MAX_RESPONSE_LENGTH) {
        fprintf(stderr, "Response too large\n");
        exit(1);
    }

    memcpy(response->response + response->response_length, contents, size * nmemb);
    response->response_length += size * nmemb;

    return size * nmemb;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s URL\n", argv[0]);
        exit(1);
    }

    CURL *curl;
    CURLcode res;
    Response response;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        strncpy(response.url, argv[1], MAX_URL_LENGTH);
        response.url[MAX_URL_LENGTH - 1] = '\0';
        response.response = malloc(MAX_RESPONSE_LENGTH);
        response.response_length = 0;

        curl_easy_setopt(curl, CURLOPT_URL, response.url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            fprintf(stdout, "URL: %s\nStatus Code: %d\nResponse:\n%s\n",
                    response.url, response.status_code, response.response);
        }

        curl_easy_cleanup(curl);
        free(response.response);
    }

    curl_global_cleanup();
    return 0;
}