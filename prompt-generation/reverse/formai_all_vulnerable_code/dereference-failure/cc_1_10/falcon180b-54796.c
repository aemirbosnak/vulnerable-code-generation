//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_SITES 10
#define TIMEOUT 30

// Function to check if a site is up
int check_site(char* url) {
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if(res == CURLE_OK) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

int main(int argc, char* argv[]) {
    int num_sites;
    char* sites[MAX_SITES];
    int i;

    // Check if the correct number of arguments were provided
    if(argc < 2 || argc > MAX_SITES) {
        printf("Usage: %s [site1] [site2]... [site%d]\n", argv[0], MAX_SITES-1);
        return 1;
    }

    // Loop through the arguments and store the sites
    num_sites = argc - 1;
    for(i = 0; i < num_sites; i++) {
        strcpy(sites[i], argv[i+1]);
    }

    // Check each site and print the results
    for(i = 0; i < num_sites; i++) {
        if(check_site(sites[i]) == 1) {
            printf("%s is up\n", sites[i]);
        } else {
            printf("%s is down\n", sites[i]);
        }
    }

    return 0;
}