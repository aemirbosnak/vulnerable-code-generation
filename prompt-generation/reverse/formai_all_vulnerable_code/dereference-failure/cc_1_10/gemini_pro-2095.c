//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

// A callback function to receive the response from the server
size_t write_callback(void *ptr, size_t size, size_t nmemb, void *stream) {
    // Cast the stream to a FILE pointer
    FILE *file = (FILE *)stream;
    
    // Write the response to the file
    size_t written = fwrite(ptr, size, nmemb, file);
    
    // Return the number of bytes written
    return written;
}

int main() {
    // Create a new cURL handle
    CURL *curl = curl_easy_init();

    // Set the URL of the server
    curl_easy_setopt(curl, CURLOPT_URL, "https://www.example.com");

    // Set the callback function to receive the response
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

    // Open a file to receive the response
    FILE *file = fopen("response.txt", "w");

    // Set the file as the stream for the callback function
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

    // Perform the request
    CURLcode res = curl_easy_perform(curl);

    // Check for errors
    if (res != CURLE_OK) {
        fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
        return EXIT_FAILURE;
    }

    // Close the file
    fclose(file);

    // Cleanup the cURL handle
    curl_easy_cleanup(curl);

    // Return success
    return EXIT_SUCCESS;
}