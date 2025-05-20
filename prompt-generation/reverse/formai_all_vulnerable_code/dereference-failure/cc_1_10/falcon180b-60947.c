//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    size_t realsize = size * nmemb;
    char* data = (char*)contents;

    if(userp!= NULL)
    {
        *(char**)userp = malloc(realsize + 1);
        if(*(char**)userp!= NULL)
        {
            memcpy(*(char**)userp, data, realsize);
            (*(char**)userp)[realsize] = '\0';
        }
    }

    return realsize;
}

int main(int argc, char** argv)
{
    CURL* curl;
    CURLcode res;

    if(argc < 5)
    {
        printf("Usage: %s <username> <password> <server> <port>\n", argv[0]);
        return 1;
    }

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if(curl == NULL)
    {
        printf("Error initializing curl.\n");
        return 1;
    }

    char* username = argv[1];
    char* password = argv[2];
    char* server = argv[3];
    int port = atoi(argv[4]);

    char* url = malloc(strlen(server) + 20);
    sprintf(url, "imap://%s:%d", server, port);

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_USERNAME, username);
    curl_easy_setopt(curl, CURLOPT_PASSWORD, password);

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);

    res = curl_easy_perform(curl);
    if(res!= CURLE_OK)
    {
        printf("Error performing curl operation: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        curl_global_cleanup();
        return 1;
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}