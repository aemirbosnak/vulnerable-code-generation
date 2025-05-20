//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    char *buffer = (char *)malloc(realsize + 1);
    memcpy(buffer, contents, realsize);
    buffer[realsize] = '\0';
    printf("%s", buffer);
    free(buffer);
    return realsize;
}

void http_get(const char *url, int depth)
{
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        res = curl_easy_perform(curl);
        if(res!= CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        curl_easy_cleanup(curl);
    }

    if(depth > 0) {
        char *new_url = malloc(strlen(url) + 1);
        strcpy(new_url, url);
        char *pos = strrchr(new_url, '/');
        if(pos!= NULL) {
            *pos = '\0';
            http_get(new_url, depth-1);
        }
        free(new_url);
    }
}

int main(int argc, char *argv[])
{
    if(argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    http_get(argv[1], 2);

    curl_global_cleanup();
    return 0;
}