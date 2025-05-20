//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <curl/curl.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    if (fwrite(contents, size, realsize, stdout) < realsize) {
        fprintf(stderr, "Error writing to stdout.\n");
        return 0;
    }
    return realsize;
}

int main(int argc, char *argv[]) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        struct in_addr ipaddr;
        struct hostent *host;

        if (argc < 3) {
            fprintf(stderr, "Usage: %s <URL> <OutputFile>\n", argv[0]);
            curl_easy_cleanup(curl);
            curl_global_cleanup();
            return 1;
        }

        host = gethostbyname(argv[1]);
        if (!host) {
            herror("gethostbyname");
            curl_easy_cleanup(curl);
            curl_global_cleanup();
            return 1;
        }

        ipaddr.s_addr = *(long *)host->h_addr;

        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, argv[2]);
        curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}