//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URL_LEN 512
#define MAX_RESPONSE_LEN 4096
#define CHECK_INTERVAL 60 // seconds

struct url_info {
    char *url;
    time_t last_checked;
    int status;
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    char *response = (char *)malloc(size * nmemb);
    memcpy(response, contents, size * nmemb);
    printf("%s", response);
    return size * nmemb;
}

int main()
{
    CURL *curl;
    FILE *config_file;
    char line[MAX_URL_LEN];
    struct url_info *urls = NULL;
    int num_urls = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        config_file = fopen("config.txt", "r");

        if (config_file) {
            while (fgets(line, MAX_URL_LEN, config_file)!= NULL) {
                urls = realloc(urls, sizeof(struct url_info) * ++num_urls);
                urls[num_urls - 1].url = strdup(line);
                urls[num_urls - 1].last_checked = 0;
                urls[num_urls - 1].status = 0;
            }

            fclose(config_file);

            while (1) {
                time_t current_time = time(NULL);

                for (int i = 0; i < num_urls; i++) {
                    if (current_time - urls[i].last_checked >= CHECK_INTERVAL) {
                        char url_copy[MAX_URL_LEN];
                        strcpy(url_copy, urls[i].url);

                        curl_easy_setopt(curl, CURLOPT_URL, url_copy);
                        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

                        CURLcode res = curl_easy_perform(curl);

                        if (res == CURLE_OK) {
                            urls[i].status = 200;
                            urls[i].last_checked = current_time;
                        } else {
                            urls[i].status = 0;
                            printf("Error checking %s: %s\n", urls[i].url, curl_easy_strerror(res));
                        }
                    }
                }

                sleep(CHECK_INTERVAL);
            }
        } else {
            printf("Error opening config file\n");
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    } else {
        printf("Error initializing cURL\n");
    }

    return 0;
}