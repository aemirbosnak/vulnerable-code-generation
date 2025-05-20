//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

int main(int argc, char *argv[])
{
    CURL *curl;
    CURLcode res;
    char url[100];

    if (argc != 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    // Check URL for "http://" or "https://" prefix
    if (strncmp(argv[1], "http://", 7) != 0 &&
            strncmp(argv[1], "https://", 8) != 0) {
        printf("Error: Invalid URL. URL must begin with 'http://' or 'https://'\n");
        return 1;
    }

    // Copy URL to local variable
    strcpy(url, argv[1]);

    // Enable paranoid mode
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl == NULL) {
        printf("Error: Could not initialize libcurl. Aborting.\n");
        return 1;
    }

    // Disable redirects
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 0L);

    // Enable SSL certificate verification
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2L);

    // Set timeout to 10 seconds
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

    // Set user-agent string
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0");

    // Set URL
    curl_easy_setopt(curl, CURLOPT_URL, url);

    // Perform HTTP request
    res = curl_easy_perform(curl);

    // Check results
    if (res != CURLE_OK) {
        printf("Error: Could not connect to server. (Error code: %d)\n", res);
    } else {
        long response_code;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        printf("HTTP Status Code: %ld\n", response_code);
    }

    // Clean up
    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}