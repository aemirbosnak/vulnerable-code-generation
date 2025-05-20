//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URL_LEN 1024
#define TIMEOUT_SEC 5

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    char *buffer = (char *)malloc(size * nmemb);
    if (buffer == NULL) {
        return 0;
    }
    memcpy(buffer, contents, size * nmemb);
    ((char **)userp)[nmemb - 1] = buffer;
    return size * nmemb;
}

int main(int argc, char **argv)
{
    if (argc!= 3) {
        printf("Usage: %s <url> <logfile>\n", argv[0]);
        return 1;
    }

    char url[MAX_URL_LEN];
    strncpy(url, argv[1], MAX_URL_LEN - 1);

    FILE *logfile = fopen(argv[2], "a");
    if (logfile == NULL) {
        printf("Error: failed to open log file %s\n", argv[2]);
        return 1;
    }

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &logfile);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT_SEC);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            fprintf(logfile, "Error: %s\n", curl_easy_strerror(res));
        } else {
            fprintf(logfile, "Success: %s\n", url);
        }

        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }

    curl_global_cleanup();
    fclose(logfile);

    return 0;
}