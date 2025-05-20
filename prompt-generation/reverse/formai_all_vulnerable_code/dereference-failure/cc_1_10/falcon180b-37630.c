//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/time.h>
#include <time.h>

#define MAX_URL_SIZE 2048
#define MAX_RESPONSE_SIZE 2048

// Callback function to handle response data
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    char *response = (char*)malloc(realsize + 1);
    if (response == NULL) {
        return 0;
    }
    memcpy(response, contents, realsize);
    response[realsize] = '\0';
    printf("%s", response);
    free(response);
    return realsize;
}

// Function to check if website is up
int CheckWebsite(char* url) {
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            printf("Error: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return res;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        exit(1);
    }
    char url[MAX_URL_SIZE];
    strcpy(url, argv[1]);
    int response_code = CheckWebsite(url);
    if (response_code == CURLE_OK) {
        printf("Website is up\n");
    } else {
        printf("Website is down\n");
    }
    return 0;
}