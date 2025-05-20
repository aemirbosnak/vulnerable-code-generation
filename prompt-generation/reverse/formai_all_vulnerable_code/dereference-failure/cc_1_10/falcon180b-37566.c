//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define SERVER_URL "http://localhost:8080"
#define REQUEST_METHOD "POST"
#define REQUEST_PATH "/api/data"
#define REQUEST_CONTENT_TYPE "application/json"

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((char*)userp)[size * nmemb] = '\0';
    return size * nmemb;
}

int main()
{
    CURL* curl;
    CURLcode res;
    char* response;
    struct curl_slist* headers = NULL;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        headers = curl_slist_append(headers, "Content-Type: application/json");
        headers = curl_slist_append(headers, "Accept: application/json");

        char* request_body = "{\"name\": \"John\", \"age\": 30}";
        curl_easy_setopt(curl, CURLOPT_URL, SERVER_URL "/" REQUEST_PATH);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, REQUEST_METHOD);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, request_body);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Response:\n%s\n", response);
        }

        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
        free(response);
    }

    curl_global_cleanup();
    return 0;
}