//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/timeb.h>

#define MAX_URL_LEN 1024
#define MAX_RESPONSE_LEN 10240

struct url_info {
    char url[MAX_URL_LEN];
    char last_response[MAX_RESPONSE_LEN];
    time_t last_check;
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((char *)userp)[size * nmemb - 1] = '\0';
    return size * nmemb;
}

int main(int argc, char *argv[])
{
    CURL *curl;
    FILE *fp;
    struct url_info urls[10];
    int num_urls = 0;
    char line[MAX_URL_LEN];

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        fp = fopen("urls.txt", "r");

        if(fp) {
            while(fgets(line, MAX_URL_LEN, fp)) {
                strcpy(urls[num_urls].url, line);
                num_urls++;
            }

            fclose(fp);

            for(int i = 0; i < num_urls; i++) {
                curl_easy_setopt(curl, CURLOPT_URL, urls[i].url);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &(urls[i].last_response));

                curl_easy_perform(curl);
                urls[i].last_check = time(NULL);
            }

            for(int i = 0; i < num_urls; i++) {
                printf("URL: %s\nLast response: %s\nLast check: %ld\n\n", urls[i].url, urls[i].last_response, urls[i].last_check);
            }
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}