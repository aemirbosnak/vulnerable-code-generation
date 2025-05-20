//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_WEBSITE_COUNT 10
#define WEBSITE_CHECK_INTERVAL 60 //seconds

typedef struct {
    char *url;
    char *last_status;
    time_t last_check;
} website_t;

website_t websites[MAX_WEBSITE_COUNT];
int num_websites = 0;

size_t write_data(void *ptr, size_t size, size_t nmemb, void *userp) {
    char *buffer = (char *) malloc(size * nmemb);
    memcpy(buffer, ptr, size * nmemb);
    printf("%s", buffer);
    free(buffer);
    return size * nmemb;
}

void check_website(website_t *website) {
    CURL *curl;
    CURLcode res;
    char *response;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            printf("Failed to check website: %s\n", website->url);
        } else {
            response = strdup(website->last_status);
            printf("Website %s is %s\n", website->url, response);
        }
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

int main() {
    int i;
    char *line = NULL;
    size_t len = 0;
    FILE *file = fopen("websites.txt", "r");

    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while ((getline(&line, &len, file))!= -1) {
        website_t *website = (website_t *) malloc(sizeof(website_t));
        strcpy(website->url, line);
        website->last_status = strdup("");
        website->last_check = time(NULL);
        websites[num_websites++] = *website;
        free(website);
    }

    fclose(file);

    while (1) {
        for (i = 0; i < num_websites; i++) {
            if (difftime(time(NULL), websites[i].last_check) > WEBSITE_CHECK_INTERVAL) {
                check_website(&websites[i]);
                websites[i].last_check = time(NULL);
            }
        }

        sleep(5); //check every 5 seconds
    }

    return 0;
}