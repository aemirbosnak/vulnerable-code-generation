//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_SITES 10
#define CHECK_INTERVAL 60 // seconds

struct site {
    char *url;
    char *name;
};

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

int check_site(struct site *site) {
    CURL *curl;
    CURLcode res;
    FILE *fp;
    char readbuffer[1024];

    curl = curl_easy_init();
    if (curl) {
        sprintf(site->url, "http://%s", site->name);
        curl_easy_setopt(curl, CURLOPT_URL, site->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res!= CURLE_OK) {
            printf("Error checking site %s: %s\n", site->name, curl_easy_strerror(res));
            return 0;
        } else {
            printf("Site %s is up.\n", site->name);
            return 1;
        }
    } else {
        printf("Error initializing curl.\n");
        return 0;
    }
}

int main() {
    struct site sites[MAX_SITES];
    int num_sites = 0;
    char input[1024];

    printf("Enter the names and URLs of the sites to monitor, one per line.\n");
    printf("Format: name url\n");
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        char *name = strtok(input, " ");
        char *url = strtok(NULL, " ");

        if (name && url) {
            strcpy(sites[num_sites].name, name);
            strcpy(sites[num_sites].url, url);
            num_sites++;
        }
    }

    while (1) {
        for (int i = 0; i < num_sites; i++) {
            if (!check_site(&sites[i])) {
                exit(1);
            }
        }
        sleep(CHECK_INTERVAL);
    }

    return 0;
}