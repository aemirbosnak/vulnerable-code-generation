//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT "80"
#define TIMEOUT 5L
#define MAX_URL_SIZE 1024

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((char*)userp)[size * nmemb] = '\0';
    return size * nmemb;
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <URL> <Email>\n", argv[0]);
        return 1;
    }

    char url[MAX_URL_SIZE];
    strcpy(url, argv[1]);

    char email[100];
    strcpy(email, argv[2]);

    CURL* curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &email);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);

        CURLcode res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            printf("Error: %s\n", curl_easy_strerror(res));
        } else {
            printf("URL '%s' is up and running.\n", url);
        }

        curl_easy_cleanup(curl);
    }

    return 0;
}