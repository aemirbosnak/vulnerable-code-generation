//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <time.h>

#define MAX_URL_LEN 1024
#define MAX_RESPONSE_LEN 1024*10

typedef struct {
    char *url;
    char *response;
    time_t last_check;
} website_t;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((char *)userp)[((size_t)0)*nmemb] = '\0';
    return size * nmemb;
}

int main()
{
    CURL *curl;
    FILE *fp;
    char buffer[MAX_RESPONSE_LEN];
    website_t websites[] = {{"http://example.com", NULL, 0}, {"http://google.com", NULL, 0}};
    int num_websites = sizeof(websites) / sizeof(website_t);
    int i;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        for(i=0; i<num_websites; i++) {
            website_t *website = &websites[i];

            if(website->response == NULL) {
                website->response = malloc(MAX_RESPONSE_LEN);
                memset(website->response, 0, MAX_RESPONSE_LEN);

                curl_easy_setopt(curl, CURLOPT_URL, website->url);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, website->response);

                curl_easy_perform(curl);
                curl_easy_cleanup(curl);

                time(&website->last_check);
            }

            printf("Website %s is ", website->url);

            if(strstr(website->response, "200 OK")) {
                printf("UP\n");
            } else {
                printf("DOWN\n");
            }
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}