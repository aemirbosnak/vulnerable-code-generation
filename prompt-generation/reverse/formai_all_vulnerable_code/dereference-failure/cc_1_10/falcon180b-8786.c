//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: asynchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <curl/curl.h>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    char *data = (char*)malloc(realsize + 1);
    if (data == NULL)
        return 0;
    memcpy(data, contents, realsize);
    data[realsize] = '\0';
    printf("%s", data);
    free(data);
    return realsize;
}

int main()
{
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        char url[200] = {0};
        printf("Enter URL to sanitize: ");
        scanf("%s", url);

        // Sanitize the URL
        char *sanitized_url = malloc(strlen(url) + 1);
        char *ptr = sanitized_url;
        for (int i = 0; i < strlen(url); i++) {
            if (isalnum(url[i]) || url[i] == '-') {
                *ptr++ = tolower(url[i]);
            }
        }
        *ptr = '\0';

        // Download the sanitized URL
        curl_easy_setopt(curl, CURLOPT_URL, sanitized_url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        res = curl_easy_perform(curl);
        if(res!= CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}