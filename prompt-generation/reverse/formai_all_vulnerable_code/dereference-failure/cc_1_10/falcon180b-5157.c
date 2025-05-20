//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_SIZE 1000
#define MAX_HEADERS_SIZE 1000

struct HTTPRequest {
    char *url;
    char *headers;
    char *method;
};

struct HTTPResponse {
    CURLcode res;
    char *response_body;
    long response_code;
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((char *)userp)[size*nmemb] = '\0';
    return size * nmemb;
}

int main(int argc, char *argv[])
{
    CURL *curl;
    CURLcode res;
    struct HTTPRequest request;
    struct HTTPResponse response;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();

    if (curl) {
        printf("Enter the URL: ");
        scanf("%s", request.url);

        printf("Enter the HTTP method (GET/POST): ");
        scanf("%s", request.method);

        request.headers = (char *)malloc(MAX_HEADERS_SIZE * sizeof(char));
        if (request.headers == NULL) {
            printf("Memory error\n");
            exit(1);
        }

        printf("Enter additional headers (leave blank for none): ");
        scanf("%[^\n]", request.headers);

        curl_easy_setopt(curl, CURLOPT_URL, request.url);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, request.method);

        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, request.headers);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        response.response_body = (char *)malloc(MAX_URL_SIZE * sizeof(char));
        if (response.response_body == NULL) {
            printf("Memory error\n");
            exit(1);
        }
        response.response_body[0] = '\0';

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            printf("curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response.response_code);
            printf("Response Code: %ld\n", response.response_code);
            printf("Response Body: %s\n", response.response_body);
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}