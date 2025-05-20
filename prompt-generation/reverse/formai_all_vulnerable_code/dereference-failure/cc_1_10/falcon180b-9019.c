//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    FILE *file = (FILE *)userp;
    return fwrite(contents, realsize, 1, file);
}

void progress_callback(void *clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow)
{
    double progress;
    if (dltotal > 0)
        progress = ((double)dlnow / (double)dltotal) * 100.0;
    else
        progress = 0;
    printf("Progress: %.2f%%\r", progress);
}

int main(int argc, char *argv[])
{
    CURL *curl;
    FILE *file;
    CURLcode res;

    if (argc < 4) {
        fprintf(stderr, "Usage: %s <FTP URL> <username> <password>\n", argv[0]);
        return 1;
    }

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        char *url = argv[1];
        char *userpwd = argv[2];
        int userpwd_len = strlen(userpwd);
        char *username = strtok(userpwd, ":");
        char *password = strtok(NULL, ":");

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_USERPWD, userpwd);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, progress_callback);
        curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, NULL);

        res = curl_easy_perform(curl);
        if (res!= CURLE_OK)
            fprintf(stderr, "FTP transfer failed: %s\n", curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}