//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/time.h>
#include <unistd.h>
#include <errno.h>

#define MAX_URL_LEN 1024
#define MAX_HOST_LEN 1024
#define MAX_RESPONSE_LEN 1024

struct url_data {
    char host[MAX_HOST_LEN];
    char url[MAX_URL_LEN];
    char response[MAX_RESPONSE_LEN];
    time_t last_checked;
};

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    struct url_data* data = (struct url_data*)userp;
    size_t realsize = size * nmemb;
    strncat(data->response, (char*)contents, realsize);
    return realsize;
}

int main(int argc, char** argv)
{
    if (argc < 3) {
        printf("Usage: %s <url> <interval_in_seconds>\n", argv[0]);
        return 1;
    }

    char url[MAX_URL_LEN] = "";
    strncpy(url, argv[1], MAX_URL_LEN - 1);

    int interval = atoi(argv[2]);

    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        struct url_data data;
        strncpy(data.host, url, MAX_HOST_LEN - 1);
        strncpy(data.url, url, MAX_URL_LEN - 1);

        data.last_checked = time(NULL);

        while (1) {
            res = curl_easy_perform(curl);

            if (res!= CURLE_OK) {
                printf("curl_easy_perform() failed: %s\n",
                        curl_easy_strerror(res));
            }

            time_t now = time(NULL);

            if (now - data.last_checked >= interval) {
                data.last_checked = now;

                curl_easy_setopt(curl, CURLOPT_URL, data.url);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);

                res = curl_easy_perform(curl);

                if (res!= CURLE_OK) {
                    printf("curl_easy_perform() failed: %s\n",
                            curl_easy_strerror(res));
                }
            }

            sleep(1);
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}