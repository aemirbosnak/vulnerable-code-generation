//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/time.h>
#include <sys/select.h>
#include <unistd.h>
#include <fcntl.h>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    return size * nmemb;
}

void check_website_status(char *url)
{
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        res = curl_easy_perform(curl);

        if(res!= CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

void monitor_website(char *url, int interval)
{
    while(1) {
        check_website_status(url);
        sleep(interval);
    }
}

int main(int argc, char *argv[])
{
    if(argc!= 3) {
        fprintf(stderr, "Usage: %s <URL> <interval>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    int interval = atoi(argv[2]);

    monitor_website(url, interval);

    return 0;
}