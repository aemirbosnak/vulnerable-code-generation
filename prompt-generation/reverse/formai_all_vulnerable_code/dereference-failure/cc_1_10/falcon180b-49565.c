//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 2048
#define DEFAULT_PORT 80

typedef struct {
    char url[MAX_URL_LENGTH];
    int port;
} http_client_t;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    http_client_t *client = (http_client_t *)userp;
    if (client->port == 443) {
        fwrite(contents, size, nmemb, stdout);
    } else {
        printf("HTTP response:\n");
        fwrite(contents, size, nmemb, stdout);
    }
    return size * nmemb;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <URL> [port]\n", argv[0]);
        return 1;
    }

    http_client_t client;
    strcpy(client.url, argv[1]);
    client.port = DEFAULT_PORT;

    if (argc > 2) {
        client.port = atoi(argv[2]);
    }

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, client.url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &client);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            printf("Request completed successfully\n");
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}