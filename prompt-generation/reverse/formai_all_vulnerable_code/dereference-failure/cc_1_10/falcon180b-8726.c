//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

#define MAX_LINE 1024

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t realsize = size * nmemb;
    char* data = (char*)malloc(realsize + 1);
    if (data == NULL) {
        return 0;
    }
    memcpy(data, contents, realsize);
    data[realsize] = '\0';
    printf("%s", data);
    free(data);
    return realsize;
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <username> <password> <server>\n", argv[0]);
        return 1;
    }

    CURL* curl = curl_easy_init();
    if (curl == NULL) {
        printf("Error initializing curl\n");
        return 1;
    }

    char* username = argv[1];
    char* password = argv[2];
    char* server = argv[3];

    char* url = malloc(strlen(server) + 32);
    sprintf(url, "imap://%s:%s@%s", username, password, server);

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);

    int res = curl_easy_perform(curl);
    if (res!= CURLE_OK) {
        printf("Error performing curl: %s\n", curl_easy_strerror(res));
        return 1;
    }

    curl_easy_cleanup(curl);
    free(url);

    return 0;
}