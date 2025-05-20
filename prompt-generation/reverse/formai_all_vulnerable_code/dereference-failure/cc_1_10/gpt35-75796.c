//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

typedef struct {
    char *url;
    int *status_code;
} website;

size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    return size * nmemb;
}

int check_website_status(website *site) {
    CURL *curl;
    CURLcode res;
    long http_code = 0;
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, site->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
            *(site->status_code) = (int)http_code;
        } else {
            *(site->status_code) = -1;
        }
        curl_easy_cleanup(curl);
    } else {
        *(site->status_code) = -2;
    }
    return *(site->status_code);
}

int main() {
    website sites[3] = {
        {"http://www.google.com", NULL},
        {"http://www.github.com", NULL},
        {"http://www.example.com", NULL} // add or remove websites as needed
    };

    int num_sites = sizeof(sites) / sizeof(sites[0]);
    for(int i = 0; i < num_sites; i++) {
        sites[i].status_code = malloc(sizeof(int));
        printf("Checking website %s...\n", sites[i].url);
        int status_code = check_website_status(&sites[i]);
        if(status_code == -1) {
            printf("Error checking website %s\n", sites[i].url);
        } else if(status_code == -2) {
            printf("Could not check website %s\n", sites[i].url);
        } else {
            printf("Website %s is up and running. Status code: %d\n", sites[i].url, *(sites[i].status_code));
        }
        free(sites[i].status_code);
    }
    return 0;
}