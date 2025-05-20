//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <time.h>

#define MAX_URL_LEN 1024
#define MAX_RESPONSE_LEN 1024 * 100

typedef struct {
    char url[MAX_URL_LEN];
    time_t last_check;
    int response_code;
    char response[MAX_RESPONSE_LEN];
} website_t;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((char*)userp)[(size_t)0] = '\0';
    return size * nmemb;
}

int main(int argc, char *argv[])
{
    CURL *curl;
    FILE *fp;
    char buffer[MAX_URL_LEN];
    website_t website;

    if(argc!= 2) {
        printf("Usage: %s <website_url>\n", argv[0]);
        return 1;
    }

    strcpy(website.url, argv[1]);
    website.last_check = time(NULL);
    website.response_code = -1;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website.url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &website.response);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);

        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    fp = fopen("website_status.log", "a+");

    if(fp) {
        fprintf(fp, "%s - Response Code: %d\n", ctime(&website.last_check), website.response_code);
        fclose(fp);
    }

    return 0;
}