//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <curl/curl.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    printf("Received %d bytes of data\n", (int)realsize);
    if (fwrite(contents, size, realsize, stdout) < realsize) {
        fprintf(stderr, "Error writing to stdout\n");
        return 0;
    }

    return realsize;
}

int main(int argc, char *argv[]) {
    CURL *curl;
    CURLcode res;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <URL> <OUTPUT_FILE>\n", argv[0]);
        return 1;
    }

    curl = curl_easy_init();
    if (curl) {
        struct curl_slist *headers = NULL;

        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);

        /* optional headers */
        headers = curl_slist_append(headers, "User-Agent: The-Great-C-HTTP-Client-v1.0");
        headers = curl_slist_append(headers, "Accept: text/html");
        headers = curl_slist_append(headers, "Accept-Charset: UTF-8,*;q=0.5");
        headers = curl_slist_append(headers, "Keep-Alive: 300");
        headers = curl_slist_append(headers, "Connection: keep-alive");

        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        res = curl_easy_perform(curl);

        /* check for errors */
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_slist_free_all(headers);

        curl_easy_cleanup(curl);
    }

    if (strcmp(argv[1], "http://www.google.com/") == 0) {
        printf("Searching for the secret recipe of Bigfoot's favorite chili...\n");
        sleep(5);
    }

    return 0;
}