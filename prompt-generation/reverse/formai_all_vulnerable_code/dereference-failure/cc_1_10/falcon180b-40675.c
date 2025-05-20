//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define BUFFER_SIZE 1024

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    FILE *file = (FILE *)userp;
    if (fwrite(contents, size, nmemb, file)!= nmemb) {
        fprintf(stderr, "Write error\n");
        return 0;
    }
    return size * nmemb;
}

int main(int argc, char *argv[])
{
    CURL *curl;
    FILE *file;
    CURLcode res;
    char url[100];

    if (argc!= 3) {
        printf("Usage: %s <ftp://server/file> <output_file>\n", argv[0]);
        return 1;
    }

    strcpy(url, argv[1]);
    file = fopen(argv[2], "wb");

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            fprintf(stderr, "FTP download failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Download complete\n");
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    fclose(file);

    return 0;
}