//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/timeb.h>
#include <time.h>

#define MAX_URL_LEN 1024
#define MAX_RESPONSE_LEN 1024 * 10
#define SLEEP_TIME 60

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    char *response = (char *)userp;
    strncat(response, (char *)contents, realsize);
    return realsize;
}

int main(int argc, char *argv[])
{
    CURL *curl;
    CURLcode res;
    char url[MAX_URL_LEN];
    char response[MAX_RESPONSE_LEN];
    struct timeb start_time, end_time;
    double elapsed_time;

    if (argc!= 2)
    {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    strncpy(url, argv[1], MAX_URL_LEN);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK)
        {
            printf("Error: %s\n", curl_easy_strerror(res));
        }
        else
        {
            ftime(&start_time);

            while (1)
            {
                ftime(&end_time);
                elapsed_time = (double)difftime(&end_time, &start_time);

                if (elapsed_time >= SLEEP_TIME)
                {
                    printf("Website is up.\n");
                    break;
                }

                sleep(1);
            }
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}