//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>

#define MAX_URL 100
#define TIMEOUT 10

struct url_data {
    char url[MAX_URL];
    char last_response[MAX_URL];
    time_t last_update;
    int status_code;
};

size_t write_data(void *ptr, size_t size, size_t nmemb, void *userp) {
    struct url_data *data = (struct url_data *)userp;
    strncat(data->last_response, (char *)ptr, size * nmemb);
    data->last_response[size * nmemb] = '\0';
    return size * nmemb;
}

int main() {
    CURL *curl;
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    struct url_data urls[10];
    int num_urls = 0;

    curl = curl_easy_init();
    if (curl) {
        file = fopen("urls.txt", "r");
        if (file) {
            while ((read = getline(&line, &len, file))!= -1) {
                if (num_urls >= 10) {
                    printf("Error: Maximum number of URLs reached.\n");
                    exit(1);
                }
                strcpy(urls[num_urls].url, line);
                num_urls++;
            }
            fclose(file);
        } else {
            printf("Error: Unable to open urls.txt.\n");
            exit(1);
        }

        for (int i = 0; i < num_urls; i++) {
            curl_easy_setopt(curl, CURLOPT_URL, urls[i].url);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &urls[i]);
            curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
            curl_easy_perform(curl);
        }

        for (int i = 0; i < num_urls; i++) {
            if (urls[i].status_code == 200) {
                printf("%s - UP\n", urls[i].url);
            } else {
                printf("%s - DOWN\n", urls[i].url);
            }
        }

        curl_easy_cleanup(curl);
    }

    return 0;
}