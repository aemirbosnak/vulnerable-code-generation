//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

// Function to write data to a file
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the number of arguments is correct
    if (argc != 3) {
        printf("Usage: %s <URL> <output file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the URL and output file name from the arguments
    char *url = argv[1];
    char *output_file = argv[2];

    // Initialize the CURL library
    curl_global_init(CURL_GLOBAL_ALL);

    // Create a new CURL handle
    CURL *curl = curl_easy_init();

    // Set the URL to fetch
    curl_easy_setopt(curl, CURLOPT_URL, url);

    // Set the output file to write to
    FILE *fp = fopen(output_file, "wb");
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

    // Set the write callback function
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

    // Perform the HTTP request
    CURLcode res = curl_easy_perform(curl);

    // Check if the request was successful
    if (res != CURLE_OK) {
        printf("Error: %s\n", curl_easy_strerror(res));
        return EXIT_FAILURE;
    }

    // Cleanup the CURL handle and library
    curl_easy_cleanup(curl);
    curl_global_cleanup();

    // Close the output file
    fclose(fp);

    return EXIT_SUCCESS;
}