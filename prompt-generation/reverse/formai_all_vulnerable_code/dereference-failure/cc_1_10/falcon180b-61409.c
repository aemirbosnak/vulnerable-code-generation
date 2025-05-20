//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

struct website_info {
    char *url;
    char *hostname;
    int port;
    unsigned int status_code;
    time_t last_updated;
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((struct website_info *)userp)->last_updated = time(NULL);
    return size * nmemb;
}

int main(int argc, char *argv[])
{
    CURL *curl;
    FILE *fp;
    char buffer[8192];
    struct website_info website;

    if (argc!= 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    strcpy(website.url, argv[1]);
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website.url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &website);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    fp = fopen("websites.txt", "a");
    if (fp) {
        fprintf(fp, "%s - Last Updated: %s\n", website.url, ctime(&website.last_updated));
        fclose(fp);
    }

    return 0;
}