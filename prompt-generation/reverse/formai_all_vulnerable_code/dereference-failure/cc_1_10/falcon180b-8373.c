//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/time.h>

#define MAX_URL_LEN 1024
#define MAX_RESPONSE_LEN 1024 * 10

char *url;
long response_code;
char *effective_url;
CURL *curl;
FILE *fp;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    char *ptr = (char *)contents;
    fwrite(ptr, realsize, 1, (FILE *)userp);
    return realsize;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <url> <logfile>\n", argv[0]);
        return 1;
    }

    url = argv[1];
    fp = fopen(argv[2], "w");

    if (!fp) {
        printf("Error opening log file.\n");
        return 1;
    }

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (!curl) {
        printf("Error initializing curl.\n");
        return 1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

    CURLcode res;
    res = curl_easy_perform(curl);

    if (res!= CURLE_OK) {
        printf("Error performing request: %s\n", curl_easy_strerror(res));
    } else {
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        effective_url = curl_easy_escape(curl, url, 0);
        printf("Request to %s returned response code %ld\n", effective_url, response_code);
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();
    fclose(fp);

    return 0;
}