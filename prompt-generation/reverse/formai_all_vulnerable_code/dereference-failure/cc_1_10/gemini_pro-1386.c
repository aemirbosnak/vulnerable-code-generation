//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <curl/curl.h>


int main(int argc, char *argv[]) {

    CURL *curl;
    CURLcode res;
    FILE *fp;

    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    curl = curl_easy_init();
    if (!curl) {
        printf("curl_easy_init() failed\n");
        return 1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
    curl_easy_setopt(curl, CURLOPT_HEADER, 1);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        return 1;
    }

    fp = fopen("headers.txt", "w");
    if (!fp) {
        printf("fopen() failed: %s\n", strerror(errno));
        return 1;
    }

    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &res);
    fprintf(fp, "HTTP/1.1 %d %s\n", res, curl_easy_strerror(res));

    curl_easy_cleanup(curl);
    fclose(fp);

    return 0;
}