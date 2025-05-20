//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define CHECK_INTERVAL 60 // Check website every 60 seconds
#define TIMEOUT 10 // Timeout after 10 seconds

// Function to check if website is up
int check_website(char *url) {
    CURL *curl;
    CURLcode res;
    int response_code;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_AUTOREFERER, 1L);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, TIMEOUT);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }

        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        curl_easy_cleanup(curl);

        if(response_code == 200) {
            return 1; // Website is up
        } else {
            return 0; // Website is down
        }
    } else {
        fprintf(stderr, "curl_easy_init() failed\n");
        return 0;
    }
}

int main() {
    char *url = "https://www.example.com"; // Replace with website URL to monitor
    int website_is_up = 1;

    while(1) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        if(t->tm_min % CHECK_INTERVAL == 0) {
            website_is_up = check_website(url);

            if(website_is_up == 0) {
                printf("Website is down at %s\n", asctime(t));
            }
        }

        sleep(60); // Sleep for 60 seconds
    }

    return 0;
}