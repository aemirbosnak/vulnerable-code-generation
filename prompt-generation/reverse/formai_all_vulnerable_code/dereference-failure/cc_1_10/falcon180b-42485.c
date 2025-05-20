//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_SIZE 2048

// Function to perform HTTP GET request using libcurl
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((char*)userp)[(size_t)0] = '\0';
    return size * nmemb;
}

int main(int argc, char *argv[])
{
    if(argc!= 2)
    {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if(curl)
    {
        char url[MAX_URL_SIZE];
        strcpy(url, argv[1]);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &url);

        res = curl_easy_perform(curl);
        if(res!= CURLE_OK)
        {
            printf("Error: %s\n", curl_easy_strerror(res));
        }
        else
        {
            printf("URL: %s\n", url);
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}