//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Define the callback function for CURLOPT_WRITEFUNCTION.
size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
    // Cast the stream pointer to a FILE pointer.
    FILE *file = (FILE *)stream;

    // Write the data to the file.
    fwrite(ptr, size, nmemb, file);

    // Return the number of bytes written.
    return size * nmemb;
}

int main(int argc, char **argv) {
    // Initialize the curl library.
    curl_global_init(CURL_GLOBAL_DEFAULT);

    // Create a new curl handle.
    CURL *curl = curl_easy_init();

    // Set the URL to fetch.
    curl_easy_setopt(curl, CURLOPT_URL, argv[1]);

    // Set the callback function for CURLOPT_WRITEFUNCTION.
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

    // Set the stream pointer for CURLOPT_WRITEDATA.
    FILE *file = fopen("output.txt", "w");
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

    // Perform the HTTP request.
    CURLcode res = curl_easy_perform(curl);

    // Check for errors.
    if (res != CURLE_OK) {
        fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
        return EXIT_FAILURE;
    }

    // Close the file.
    fclose(file);

    // Cleanup the curl handle.
    curl_easy_cleanup(curl);

    // Cleanup the curl library.
    curl_global_cleanup();

    return EXIT_SUCCESS;
}