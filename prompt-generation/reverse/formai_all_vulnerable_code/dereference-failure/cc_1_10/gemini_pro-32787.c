//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: modular
#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom data structure to hold HTTP response data
typedef struct {
    char *data;
    size_t size;
} ResponseData;

// Callback function to handle HTTP response data
static size_t write_response_data(void *ptr, size_t size, size_t nmemb, void *stream) {
    ResponseData *response_data = (ResponseData *)stream;

    // Calculate the total size of the response
    size_t total_size = size * nmemb;

    // Reallocate memory for the response data
    response_data->data = realloc(response_data->data, response_data->size + total_size + 1);

    // Append the new data to the response data
    memcpy(response_data->data + response_data->size, ptr, total_size);

    // Update the size of the response data
    response_data->size += total_size;

    // Null-terminate the response data
    response_data->data[response_data->size] = '\0';

    // Return the total size of the response
    return total_size;
}

// Function to perform an HTTP GET request
static ResponseData *http_get(const char *url) {
    // Initialize the CURL library
    curl_global_init(CURL_GLOBAL_DEFAULT);

    // Create a CURL handle
    CURL *curl = curl_easy_init();

    // Set the URL to retrieve
    curl_easy_setopt(curl, CURLOPT_URL, url);

    // Set the callback function to handle HTTP response data
    ResponseData *response_data = malloc(sizeof(ResponseData));
    response_data->data = NULL;
    response_data->size = 0;
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, response_data);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_response_data);

    // Perform the HTTP GET request
    CURLcode res = curl_easy_perform(curl);

    // Check for errors
    if (res != CURLE_OK) {
        fprintf(stderr, "cURL error: %s\n", curl_easy_strerror(res));
        free(response_data->data);
        free(response_data);
        curl_easy_cleanup(curl);
        curl_global_cleanup();
        return NULL;
    }

    // Clean up the CURL handle
    curl_easy_cleanup(curl);

    // Clean up the CURL library
    curl_global_cleanup();

    // Return the HTTP response data
    return response_data;
}

// Function to free the HTTP response data
static void free_response_data(ResponseData *response_data) {
    free(response_data->data);
    free(response_data);
}

int main(int argc, char **argv) {
    // Check for the required number of arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Perform the HTTP GET request
    ResponseData *response_data = http_get(argv[1]);

    // Check for errors
    if (response_data == NULL) {
        return EXIT_FAILURE;
    }

    // Print the HTTP response data
    printf("%s", response_data->data);

    // Free the HTTP response data
    free_response_data(response_data);

    return EXIT_SUCCESS;
}