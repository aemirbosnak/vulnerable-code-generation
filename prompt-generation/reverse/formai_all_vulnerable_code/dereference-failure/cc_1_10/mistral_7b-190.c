//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <errno.h>

size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    printf("Received %ld bytes of response: %.*s", (long)realsize, (int)realsize, (char *)contents);
    return realsize;
}

int main(int argc, char *argv[]) {

    CURL *curl;
    CURLcode res;
    char *url = NULL;
    char *useragent = NULL;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <url> <output_file>\n", argv[0]);
        return 1;
    }

    url = malloc(strlen(argv[1]) + strlen(getenv("QUERY_STRING")) + 2);
    strcpy(url, argv[1]);
    strcat(url, "?");
    strcat(url, getenv("QUERY_STRING"));

    useragent = malloc(strlen("Libcurl-URL-Sanitizer/1.0") + 1);
    strcpy(useragent, "Libcurl-URL-Sanitizer/1.0");

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, useragent);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    free(url);
    free(useragent);

    system("echo Done > output.txt");

    return 0;
}