//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <curl/curl.h>

#define URL_MAX_LENGTH 256
#define CHECK_INTERVAL 5 // check interval in seconds

void check_website(const char *url) {
    CURL *curl;
    CURLcode res;
    double elapsed_time;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We only need to check if the site is reachable
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L); // Set timeout for the request

        // Perform the request, res will get the return code
        res = curl_easy_perform(curl);

        // Get the elapsed time for the request
        curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &elapsed_time);

        if(res == CURLE_OK) {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            printf("Website %s is reachable. Response Code: %ld, Time taken: %.2f seconds\n", url, response_code, elapsed_time);
        } else {
            fprintf(stderr, "Failed to reach website %s - %s\n", url, curl_easy_strerror(res));
        }

        // Always cleanup
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char url[URL_MAX_LENGTH];
    strncpy(url, argv[1], URL_MAX_LENGTH - 1);
    url[URL_MAX_LENGTH - 1] = '\0'; // Ensure null termination

    while (1) {
        check_website(url);
        sleep(CHECK_INTERVAL); // Wait for the specified interval before checking again
    }

    return EXIT_SUCCESS;
}