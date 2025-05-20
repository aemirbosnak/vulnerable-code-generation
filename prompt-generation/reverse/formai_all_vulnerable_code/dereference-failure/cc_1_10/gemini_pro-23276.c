//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: minimalist
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

#define URL_SIZE 2048

int main(int argc, char *argv[]) {
    CURL *curl;
    CURLcode res;
    char url[URL_SIZE];
    char *ptr;

    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    // Copy the URL into a buffer large enough to escape any characters
    strncpy(url, argv[1], URL_SIZE - 1);
    url[URL_SIZE - 1] = '\0';

    // Escaping characters that are not allowed in URLs
    ptr = curl_easy_escape(NULL, url, 0);
    if (!ptr) {
        fprintf(stderr, "Error escaping URL\n");
        return 1;
    }

    // Copy the escaped URL back into the original buffer
    strncpy(url, ptr, URL_SIZE - 1);
    url[URL_SIZE - 1] = '\0';

    // Free the escaped URL
    curl_free(ptr);

    // Initialize the CURL library
    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Error initializing CURL\n");
        return 1;
    }

    // Set the URL to fetch
    curl_easy_setopt(curl, CURLOPT_URL, url);

    // Perform the request
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "Error fetching URL: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        return 1;
    }

    // Clean up the CURL library
    curl_easy_cleanup(curl);

    return 0;
}