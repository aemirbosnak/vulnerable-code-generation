//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>

#define TIMEOUT 10
#define MAX_URL_LEN 1024
#define MAX_RESPONSE_LEN 1024*1024

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    size_t realsize = size * nmemb;
    char* data = (char*)contents;
    printf("%s", data);
    return realsize;
}

int main(int argc, char** argv)
{
    if(argc!= 2)
    {
        printf("Usage: %s [URL]\n", argv[0]);
        return 1;
    }

    CURL* curl;
    CURLcode res;
    char url[MAX_URL_LEN];
    strcpy(url, argv[1]);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }
        else
        {
            printf("Operation completed successfully\n");
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}