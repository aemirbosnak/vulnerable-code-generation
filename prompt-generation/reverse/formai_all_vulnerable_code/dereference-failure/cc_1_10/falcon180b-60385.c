//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define CHECK_INTERVAL 30 // Check website every 30 seconds
#define MAX_REDIRECTS 10 // Maximum number of redirects allowed
#define TIMEOUT 10 // Timeout in seconds

typedef struct {
    char *url;
    char *last_response;
    time_t last_check;
    int status;
} website_t;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    website_t *website = (website_t*)userp;
    strncat(website->last_response, (char*)contents, size * nmemb);
    return size * nmemb;
}

int main()
{
    CURL *curl;
    FILE *fp;
    char *filename = "websites.txt";
    char line[1024];
    char *token;
    website_t *websites = NULL;
    int num_websites = 0;
    int running = 1;

    // Load websites from file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open %s\n", filename);
        return 1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, "\n");
        websites = realloc(websites, sizeof(website_t) * ++num_websites);
        websites[num_websites - 1].url = strdup(token);
        websites[num_websites - 1].status = 0; // Not checked yet
    }
    fclose(fp);

    // Initialize cURL
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        // Start checking websites
        while (running && num_websites > 0) {
            time_t now = time(NULL);

            for (int i = 0; i < num_websites; i++) {
                website_t *website = &websites[i];

                if (difftime(now, website->last_check) >= CHECK_INTERVAL) {
                    // Check website
                    curl_easy_setopt(curl, CURLOPT_URL, website->url);
                    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                    curl_easy_setopt(curl, CURLOPT_WRITEDATA, website);
                    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
                    curl_easy_setopt(curl, CURLOPT_MAXREDIRS, MAX_REDIRECTS);
                    curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);

                    CURLcode res = curl_easy_perform(curl);
                    if (res!= CURLE_OK) {
                        printf("Error checking %s: %s\n", website->url, curl_easy_strerror(res));
                    } else {
                        website->last_check = now;
                        website->status = 1; // Check succeeded
                    }
                }
            }

            sleep(1);
        }

        // Clean up
        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    free(websites);
    fclose(fp);

    return 0;
}