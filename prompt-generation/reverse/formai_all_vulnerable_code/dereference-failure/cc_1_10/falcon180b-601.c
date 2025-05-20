//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/timeb.h>

typedef struct {
    char *url;
    char *hostname;
    int port;
    int timeout;
} website_t;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((char *)userp)[(size_t)0] = '\0';
    return size * nmemb;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <config_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening config file.\n");
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *url = strtok(line, " ");
        char *hostname = strtok(NULL, " ");
        char *port_str = strtok(NULL, " ");
        int port = atoi(port_str);
        int timeout = 5; // default timeout

        website_t *website = malloc(sizeof(website_t));
        website->url = strdup(url);
        website->hostname = strdup(hostname);
        website->port = port;
        website->timeout = timeout;

        curl_global_init(CURL_GLOBAL_DEFAULT);
        CURL *curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, website->url);
            curl_easy_setopt(curl, CURLOPT_PORT, website->port);
            curl_easy_setopt(curl, CURLOPT_TIMEOUT, website->timeout);

            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &website->url);

            CURLcode res = curl_easy_perform(curl);
            if (res!= CURLE_OK) {
                printf("Error: %s\n", curl_easy_strerror(res));
            }

            curl_easy_cleanup(curl);
        }
        curl_global_cleanup();
        free(website);
    }

    fclose(fp);
    return 0;
}