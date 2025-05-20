//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <sys/timeb.h>

#define MAX_SIZE 1024
#define TIMEOUT 30

struct Status {
    char *url;
    int status_code;
    char *response;
    time_t timestamp;
};

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    char *buffer = (char *)malloc(size * nmemb);
    if (buffer == NULL) {
        return 0;
    }
    memcpy(buffer, contents, size * nmemb);
    ((struct Status *)userp)->response = buffer;
    return size * nmemb;
}

int main() {
    CURL *curl;
    FILE *file;
    struct Status status;
    char *url = "http://example.com";
    file = fopen("status.log", "a");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl == NULL) {
        printf("Error initializing curl\n");
        exit(1);
    }
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &status);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36");
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    fprintf(file, "%s - %d - %s\n", url, status.status_code, status.response);
    fprintf(file, "Timestamp: %s\n", ctime(&status.timestamp));
    fclose(file);
    free(status.response);
    return 0;
}