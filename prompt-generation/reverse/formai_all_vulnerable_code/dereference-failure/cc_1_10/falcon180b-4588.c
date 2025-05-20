//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    return size * nmemb;
}

static int ProgressCallback(void *clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow)
{
    return 0;
}

int main(int argc, char *argv[])
{
    CURL *curl;
    FILE *fp;
    CURLcode res;
    struct stat file_info;
    char url[100];
    int check_interval = 60; // Check website every 60 seconds

    if (argc!= 3) {
        printf("Usage: %s <website_url> <log_file>\n", argv[0]);
        return 1;
    }

    strcpy(url, argv[1]);
    strcat(url, "?timestamp=");
    time_t now = time(NULL);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y%m%d%H%M%S", localtime(&now));
    strcat(url, timestamp);

    fp = fopen(argv[2], "w+");
    if (fp == NULL) {
        printf("Error opening log file: %s\n", strerror(errno));
        return 1;
    }

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl == NULL) {
        printf("Error initializing curl\n");
        return 1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
    curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, ProgressCallback);
    curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, NULL);

    res = curl_easy_perform(curl);
    if (res!= CURLE_OK) {
        printf("Error performing curl request: %s\n", curl_easy_strerror(res));
        fclose(fp);
        curl_easy_cleanup(curl);
        curl_global_cleanup();
        return 1;
    }

    fclose(fp);
    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}