//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/timeb.h>
#include <time.h>

#define BUFFER_SIZE 1024

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    char *buffer = (char *)malloc(realsize + 1);
    if (buffer == NULL)
        return 0;
    memcpy(buffer, contents, realsize);
    buffer[realsize] = '\0';
    *((char **)userp) = buffer;
    return realsize;
}

int main(int argc, char *argv[])
{
    CURL *curl;
    FILE *fp;
    char url[100];
    char buffer[BUFFER_SIZE];
    struct timeb start, end;
    double elapsed;

    if (argc!= 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    strcpy(url, argv[1]);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl == NULL) {
        printf("Failed to initialize curl\n");
        return 1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

    if (curl_easy_perform(curl)!= CURLE_OK) {
        printf("Failed to download URL\n");
        return 1;
    }

    fflush(stdout);
    fflush(stderr);
    fprintf(stdout, "Downloaded URL: %s\n", buffer);

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    fp = fopen("output.txt", "w");
    if (fp == NULL) {
        printf("Failed to open output file\n");
        return 1;
    }

    fprintf(fp, "Downloaded URL: %s\n", buffer);
    fclose(fp);

    printf("Output saved to output.txt\n");

    return 0;
}