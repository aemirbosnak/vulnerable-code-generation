//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: standalone
#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>

// Function to write the response body to a file
size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp) {
    FILE *fp = (FILE *)userp;
    return fwrite(buffer, size, nmemb, fp);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <url> <output file> <post data>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Initialize the CURL library
    curl_global_init(CURL_GLOBAL_ALL);

    // Create a new CURL handle
    CURL *curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Failed to initialize CURL\n");
        return EXIT_FAILURE;
    }

    // Set the URL to fetch
    curl_easy_setopt(curl, CURLOPT_URL, argv[1]);

    // Create a file to store the response body
    FILE *fp = fopen(argv[2], "w");
    if (!fp) {
        fprintf(stderr, "Failed to open file %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    // Set the function to be called when the response body is received
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

    // Set the file to store the response body in
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

    // Set the HTTP POST data
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, argv[3]);

    // Perform the HTTP request
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "Failed to perform request: %s\n", curl_easy_strerror(res));
        return EXIT_FAILURE;
    }

    // Cleanup the CURL handle
    curl_easy_cleanup(curl);

    // Cleanup the file
    fclose(fp);

    // Cleanup the CURL library
    curl_global_cleanup();

    return EXIT_SUCCESS;
}