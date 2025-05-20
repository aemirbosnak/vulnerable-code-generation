//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LEN 1024
#define MAX_RESPONSE_LEN 10240

struct url_data {
    char url[MAX_URL_LEN];
    char response[MAX_RESPONSE_LEN];
    int response_code;
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    struct url_data *data = (struct url_data *)userp;
    size_t realsize = size * nmemb;
    memcpy(&data->response[data->response_code], contents, realsize);
    data->response_code += realsize;
    return realsize;
}

int main(int argc, char *argv[])
{
    CURL *curl;
    FILE *logfile;
    struct url_data urldata;
    char logentry[256];

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        if (argc!= 2) {
            fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
            exit(1);
        }

        strcpy(urldata.url, argv[1]);
        urldata.response_code = 0;

        curl_easy_setopt(curl, CURLOPT_URL, urldata.url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &urldata);

        CURLcode res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            int response_code = urldata.response_code;
            snprintf(logentry, sizeof(logentry), "URL '%s' responded with code %d\n",
                     urldata.url, response_code);
            logfile = fopen("uptime.log", "a");
            if (logfile) {
                fprintf(logfile, "%s", logentry);
                fclose(logfile);
            } else {
                perror("fopen");
            }
        }
    } else {
        fprintf(stderr, "curl_easy_init() failed\n");
    }

    curl_global_cleanup();
    return 0;
}