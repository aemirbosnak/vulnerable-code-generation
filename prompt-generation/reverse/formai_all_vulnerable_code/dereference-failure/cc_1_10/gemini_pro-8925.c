//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: future-proof
#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Callback function to receive and process the HTTP response
size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    // Append the received data to the user-provided buffer
    char **buffer = (char **)userp;
    *buffer = realloc(*buffer, strlen(*buffer) + size * nmemb + 1);
    strcat(*buffer, contents);

    return size * nmemb;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Initialize the libcurl library
    CURL *curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Error initializing libcurl\n");
        return EXIT_FAILURE;
    }

    // Set the URL to fetch
    curl_easy_setopt(curl, CURLOPT_URL, argv[1]);

    // Set the callback function to receive the HTTP response
    char *buffer = malloc(1);
    *buffer = '\0';
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

    // Perform the HTTP request
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "Error performing HTTP request: %s\n", curl_easy_strerror(res));
        free(buffer);
        curl_easy_cleanup(curl);
        return EXIT_FAILURE;
    }

    // Get the response code
    long response_code;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

    // Get the response size
    double response_size;
    curl_easy_getinfo(curl, CURLINFO_SIZE_DOWNLOAD, &response_size);

    // Print the response code and size
    printf("Response code: %ld\n", response_code);
    printf("Response size: %lf bytes\n", response_size);

    // Print the response body
    printf("\nResponse body:\n%s\n", buffer);

    // Cleanup the libcurl library
    free(buffer);
    curl_easy_cleanup(curl);

    return EXIT_SUCCESS;
}