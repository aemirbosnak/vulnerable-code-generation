//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((char *)userp)[size * nmemb] = '\0';
    return size * nmemb;
}

int main(int argc, char *argv[]) {
    CURL *curl;
    CURLcode res;
    char url[100];
    char *response;
    FILE *fp;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        exit(1);
    }

    strcpy(url, argv[1]);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        response = malloc(100000);
        if (!response) {
            fprintf(stderr, "Failed to allocate memory.\n");
            exit(1);
        }

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            fprintf(stderr, "Failed to download %s: %s\n", url, curl_easy_strerror(res));
            exit(1);
        }

        fp = fopen("response.txt", "w");
        if (!fp) {
            fprintf(stderr, "Failed to open file.\n");
            exit(1);
        }

        fwrite(response, strlen(response), 1, fp);
        fclose(fp);

        printf("Downloaded %s successfully.\n", url);
    } else {
        fprintf(stderr, "Failed to initialize curl.\n");
        exit(1);
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}