//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define BUFFER_SIZE 1024

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    FILE *file = (FILE *)userp;
    return fwrite(contents, size, nmemb, file);
}

int main(int argc, char *argv[])
{
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <HTTP method> <URL>\n", argv[0]);
        return 1;
    }

    CURL *curl;
    CURLcode res;
    FILE *file;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        file = fopen("response.txt", "wb");
        if (!file) {
            fprintf(stderr, "Failed to open file for writing.\n");
            curl_easy_cleanup(curl);
            curl_global_cleanup();
            return 1;
        }

        char http_method[10] = {0};
        strcpy(http_method, argv[1]);

        curl_easy_setopt(curl, CURLOPT_URL, argv[2]);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, http_method);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            fprintf(stdout, "Request successful.\n");
        }

        fclose(file);
        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}