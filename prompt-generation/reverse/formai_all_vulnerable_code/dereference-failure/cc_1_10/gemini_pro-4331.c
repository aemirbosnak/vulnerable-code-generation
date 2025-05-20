//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: future-proof
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 2048

// Custom URL sanitizer function
int sanitize_url(char *url, size_t url_len) {
    // Check if the URL is too long
    if (url_len > MAX_URL_LENGTH) {
        fprintf(stderr, "Error: URL is too long (%zu bytes)\n", url_len);
        return -1;
    }

    // Check if the URL contains any invalid characters
    for (size_t i = 0; i < url_len; i++) {
        if (!isalnum(url[i]) && url[i] != '.' && url[i] != '/' && url[i] != ':' && url[i] != '-' && url[i] != '_') {
            fprintf(stderr, "Error: URL contains invalid character '%c'\n", url[i]);
            return -1;
        }
    }

    // Check if the URL starts with a valid protocol
    if (strncmp(url, "http://", strlen("http://")) != 0 && strncmp(url, "https://", strlen("https://")) != 0) {
        fprintf(stderr, "Error: URL must start with 'http://' or 'https://'\n");
        return -1;
    }

    // Check if the URL contains any spaces
    if (strchr(url, ' ') != NULL) {
        fprintf(stderr, "Error: URL cannot contain spaces\n");
        return -1;
    }

    // Return 0 if the URL is valid
    return 0;
}

int main(int argc, char *argv[]) {
    // Initialize the curl library
    curl_global_init(CURL_GLOBAL_ALL);

    // Get the URL from the command line
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return -1;
    }

    char *url = argv[1];

    // Sanitize the URL
    int status = sanitize_url(url, strlen(url));
    if (status != 0) {
        return status;
    }

    // Create a curl handle
    CURL *curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Error: curl_easy_init() failed\n");
        return -1;
    }

    // Set the URL on the curl handle
    curl_easy_setopt(curl, CURLOPT_URL, url);

    // Perform the request
    status = curl_easy_perform(curl);
    if (status != CURLE_OK) {
        fprintf(stderr, "Error: curl_easy_perform() failed: %s\n", curl_easy_strerror(status));
        return -1;
    }

    // Get the response code
    long response_code;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

    // Print the response code
    printf("Response code: %ld\n", response_code);

    // Cleanup the curl handle
    curl_easy_cleanup(curl);

    // Cleanup the curl library
    curl_global_cleanup();

    return 0;
}