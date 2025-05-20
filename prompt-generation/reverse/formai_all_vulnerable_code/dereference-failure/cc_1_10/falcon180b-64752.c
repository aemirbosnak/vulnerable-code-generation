//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LEN 512
#define MAX_RESPONSE_LEN 1024

struct url_data {
    char *url;
    int response_code;
    char response[MAX_RESPONSE_LEN];
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    struct url_data *data = (struct url_data *)userp;
    size_t realsize = size * nmemb;

    if (realsize > MAX_RESPONSE_LEN - strlen(data->response)) {
        realsize = MAX_RESPONSE_LEN - strlen(data->response);
    }

    memcpy(&data->response[strlen(data->response)], contents, realsize);
    data->response[strlen(data->response) + realsize] = '\0';

    return realsize;
}

int main(int argc, char **argv)
{
    CURL *curl;
    CURLcode res;
    FILE *fp;
    char readBuffer[MAX_URL_LEN];
    struct url_data data;

    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    strcpy(data.url, argv[1]);
    data.response_code = 0;
    data.response[0] = '\0';

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, data.url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            printf("Response code: %d\n", data.response_code);
            printf("Response:\n%s", data.response);
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}